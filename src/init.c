/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:59:47 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/25 15:54:44 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	init_path(t_pipex *px, char **envp);
static void	init_args(t_pipex *px, int argc, char **argv);
static char	*set_cmd_path(char *cmd, t_pipex *px);

void	init(t_pipex *px, int argc, char **argv, char **envp)
{
	if (argc != 5)
		error(ERROR_ARGC);
	init_path(px, envp);
	init_args(px, argc, argv);
	px->file[READ] = open(argv[1], O_RDONLY | O_CREAT);
	if (px->file[READ] == -1)
		error(ERROR_OPEN);
	px->file[WRITE] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC); // O_APPEND
	if (px->file[WRITE] == -1)
		error(ERROR_OPEN);
	if (pipe(px->pipe) == -1)
		error(ERROR_PIPE);
}

static void	init_path(t_pipex *px, char **envp)
{
	int	i;
	(void)px;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			px->path = ft_split(envp[i] + 5, ':');
			return ;
		}
	}
	error(ERROR_PATH);
}

static void	init_args(t_pipex *px, int argc, char **argv)
{
	int	i;

	i = -1;
	px->cmd_count = argc - DEFAULT_ARGS;
	px->cmd = malloc(sizeof(t_cmd *) * px->cmd_count);
	if (!px->cmd)
		error(ERROR_MALLOC);
	while (++i < px->cmd_count)
	{
		px->cmd[i] = malloc(sizeof(t_cmd));
		if (!px->cmd[i])
			error(ERROR_MALLOC);
		px->cmd[i]->args = ft_split(argv[i + 2], ' ');
		px->cmd[i]->path = set_cmd_path(px->cmd[i]->args[0], px);
		if (!px->cmd[i]->path)
			error(ERROR_CMD);
	}
}

static char	*set_cmd_path(char *cmd, t_pipex *px)
{
	int		i;
	char	*cmd_path;
	char	*full_path;

	i = -1;
	while (px->path[++i])
	{
		full_path = ft_strjoin(px->path[i], "/");
		cmd_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(cmd_path, F_OK && X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (0);
}
