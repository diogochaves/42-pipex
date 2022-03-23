/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:36:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/23 02:04:00 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	int	f_in;
	int	f_out;
	int	pid1;
	//int	pid2;

	if (argc != 5)
		error(ERROR_ARGC);
	f_in = open(argv[1], O_RDONLY | O_CREAT);
	if (f_in == -1)
		error(ERROR_OPEN);
	f_out = open(argv[4], O_WRONLY | O_CREAT);
	if (f_out == -1)
		error(ERROR_OPEN);
		
	// Execute the command from argv[2], using the file1 as input
	pid1 = fork();
	if (pid1 == -1)
		error(ERROR_FORK);
	if (pid1 == 0)
	{
		execve(argv[2], argv);

	} 
	else
	{
		printf("main\n");
	}
	// Execute the command from argv[3], using the argv[2] output as input
	// Output the result from argv[3] to file from argv[4]
	close(f_in);
	close(f_out);
	return (0);
}
