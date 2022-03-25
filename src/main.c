/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:36:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/25 15:46:46 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	fork_check(void);
static void	exec_cmd(t_cmd *cmd, int fd_in, int fd_out, int fd_close);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		id;

	init(&px, argc, argv, envp);
	id = fork_check();
	if (id == 0)
		exec_cmd(px.cmd[0], px.file[READ], px.pipe[WRITE], px.pipe[READ]);
	wait(0);
	id = fork_check();
	if (id == 0)
		exec_cmd(px.cmd[1], px.pipe[READ], px.file[WRITE], px.pipe[WRITE]);
	close(px.pipe[WRITE]); // && close(pipe[READ]) ?
	wait(0);
	close(px.file[READ]);
	close(px.file[WRITE]);
	free_pipex(&px);
	return (0);
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
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_close);
	if (execve(cmd->path, cmd->args, NULL) == -1)
		error(ERROR_EXEC);
}
