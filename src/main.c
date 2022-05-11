/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:36:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/05/11 15:15:10 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	pipex(t_pipex *px);
static void	cleanup(t_pipex *px);
static int	fork_check(void);
static void	exec_cmd(t_cmd *cmd, int fd_in, int fd_out, int fd_close);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	init(&px, argc, argv, envp);
	pipex(&px);
	cleanup(&px);
	return (px.exit_code);
}

static void	pipex(t_pipex *px)
{
	int	id;
	int	status;

	id = fork_check();
	if (id == CHILD_PROCESS)
	{
		if (access(px->cmd[0]->path, F_OK && X_OK) == 0 && px->file[READ] != -1)
			exec_cmd(px->cmd[0], px->file[0], px->pipe[WRITE], px->pipe[READ]);
		free_pipex(px);
		error(ERROR_CMD);
	}
	id = fork_check();
	if (id == CHILD_PROCESS)
	{
		if (access(px->cmd[1]->path, F_OK && X_OK) == 0)
			exec_cmd(px->cmd[1], px->pipe[0], px->file[WRITE], px->pipe[WRITE]);
		free_pipex(px);
		error(ERROR_CMD);
	}
	close(px->pipe[WRITE]);
	waitpid(id, &status, 0);
	px->exit_code = WEXITSTATUS(status);
}

static void	cleanup(t_pipex *px)
{
	close(px->file[READ]);
	close(px->file[WRITE]);
	free_pipex(px);
}

static int	fork_check(void)
{
	int	id;

	id = fork();
	if (id == -1)
		error(ERROR_FORK);
	return (id);
}

static void	exec_cmd(t_cmd *cmd, int fd_in, int fd_out, int fd_close)
{
	close(fd_close);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	if (execve(cmd->path, cmd->args, NULL) == -1)
		error(ERROR_EXEC);
}
