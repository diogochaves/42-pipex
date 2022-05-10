/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:30:56 by dchaves-          #+#    #+#             */
/*   Updated: 2022/05/10 18:20:45 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_files(t_pipex *px, char **argv)
{
	if (access(argv[1], F_OK) != 0)
	{
		perror(argv[1]);
		px->file[READ] = -1;
		px->exit_code = 1;
	}
	else
	{
		px->file[READ] = open(argv[1], O_RDONLY);
		if (px->file[READ] == -1)
		{
			perror(argv[1]);
			px->exit_code = 0;
		}
	}
	px->file[WRITE] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (px->file[WRITE] == -1)
	{
		px->exit_code = -1;
		error(ERROR_OPEN);
	}
}
