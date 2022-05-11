/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:40:22 by dchaves-          #+#    #+#             */
/*   Updated: 2022/05/11 15:20:13 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error(int error_code)
{
	if (error_code == ERROR_MALLOC)
		perror("MALLOC ERROR");
	else if (error_code == ERROR_OPEN)
		perror("ERROR OPENING FILE");
	else if (error_code == ERROR_ARGC)
		ft_putstr_fd("WRONG NUMBER OF ARGUMENTS\n", 1);
	else if (error_code == ERROR_FORK)
		perror("FORK ERROR");
	else if (error_code == ERROR_PIPE)
		perror("PIPE ERROR");
	else if (error_code == ERROR_EXEC)
		perror("EXEC ERROR");
	else if (error_code == ERROR_PATH)
		perror("PATH ENV ERROR");
	exit(error_code);
}

void	free_pipex(t_pipex *px)
{
	int	i;
	int	j;

	i = -1;
	while (++i < px->cmd_count)
	{
		j = 0;
		while (px->cmd[i]->args[j])
			free(px->cmd[i]->args[j++]);
		free(px->cmd[i]->args);
		free(px->cmd[i]->path);
		free(px->cmd[i]);
	}
	free(px->cmd);
	i = -1;
	while (px->path[++i])
		free(px->path[i]);
	free(px->path);
}
