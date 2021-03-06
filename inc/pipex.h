/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:36:04 by dchaves-          #+#    #+#             */
/*   Updated: 2022/05/08 23:45:11 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> // malloc free exit
# include <unistd.h> // read write close access dup execve fork pipe unlink
# include <fcntl.h> // open
# include <stdio.h> // perror
# include <string.h> // strerror
# include <sys/wait.h> // wait waitpid
# include "../lib/libft/inc/libft.h" // libft gnl
# include "./macros.h"
# include "./structs.h"

void	init(t_pipex *px, int argc, char **argv, char **envp);
void	init_files(t_pipex *px, char **argv);
void	init_args(t_pipex *px, int argc, char **argv);
void	error(int error_code);
void	free_pipex(t_pipex *px);

char	**ft_split2(char const *s, char c);

#endif
