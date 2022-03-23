/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:42:05 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/23 21:33:48 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init(int argc, char **argv, t_pipex *px)
{
	int	i;

	px->cmds = argc - DEFAULT_ARGS;
	if (argc != 5)
		error(ERROR_ARGC);
	//px->cmd = malloc(sizeof(char *) * px->cmds);
	px->cmd_args = malloc(sizeof(char *) * px->cmds);
	i = 0;
	while (i < px->cmds)
	{
		px->cmd_args[i] = ft_split(argv[i + 2], ' ');
		//px->cmd[i] = px->cmd_args[i][0];
		i++;
	}
	px->file[READ] = open(argv[1], O_RDONLY | O_CREAT);
	if (px->file[READ] == -1)
		error(ERROR_OPEN);
	px->file[WRITE] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC); // O_APPEND
	if (px->file[WRITE] == -1)
		error(ERROR_OPEN);
	if (pipe(px->pipe) == -1)
		error(ERROR_PIPE);
}
