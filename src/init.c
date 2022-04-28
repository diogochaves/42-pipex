/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:59:47 by dchaves-          #+#    #+#             */
/*   Updated: 2022/04/28 19:13:12 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	init_path(t_pipex *px, char **envp);

void	init(t_pipex *px, int argc, char **argv, char **envp)
{
	px->exit_code = 0;
	if (argc != 5)
		error(ERROR_ARGC);
	if (pipe(px->pipe) == -1)
		error(ERROR_PIPE);
	init_files(px, argv);
	init_path(px, envp);
	init_args(px, argc, argv);
}

static void	init_path(t_pipex *px, char **envp)
{
	int	i;

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
