/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:36:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/23 21:09:17 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	fork_check(void);
static void	exec_cmd(char **cmd, int stdin, int stdout, int fd_close);

int	main(int argc, char **argv)
{
	t_pipex	px;
	int		id;

	init(argc, argv, &px);
	id = fork_check();
	if (id == 0)
		exec_cmd(px.cmd_args[0], px.file[READ], px.pipe[WRITE], px.pipe[READ]);
	wait(0);
	id = fork_check();
	if (id == 0)
		exec_cmd(px.cmd_args[1], px.pipe[READ], px.file[WRITE], px.pipe[WRITE]);
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

static void	exec_cmd(char **cmd, int fd_in, int fd_out, int fd_close)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_close);
	execvp(cmd[0], cmd); // TODO: change to - execve();
	//execve(const char *pathname, char *const argv[], char *const envp[]);
}
