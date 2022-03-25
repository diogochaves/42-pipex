/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:59:47 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/25 11:39:19 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/pipex.h"

void	init(int argc, char **argv, t_pipex *px)
{
	int	i;

	px->cmd_count = argc - DEFAULT_ARGS;
	if (argc != 5)
		error(ERROR_ARGC);
	px->cmd = malloc(sizeof(t_cmd *) * px->cmd_count);
	i = 0;
	while (i < px->cmd_count)
	{
		px->cmd[i] = malloc(sizeof(t_cmd));
		px->cmd[i]->args = ft_split2(argv[i + 2], ' ');
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
