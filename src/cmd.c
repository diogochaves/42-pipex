/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:10:52 by dchaves-          #+#    #+#             */
/*   Updated: 2022/05/08 23:45:24 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*set_cmd_path(char *cmd, t_pipex *px);
static char	*change_char_between_quote(char *arg, char old_char, char new_char);
static char	*change_char(char *arg, char old_char, char new_char);
static void	remove_quotes(char *arg);

void	init_args(t_pipex *px, int argc, char **argv)
{
	int	i;
	int	j;

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
		argv[i + 2] = change_char_between_quote(argv[i + 2], ' ', NOT_ASCII);
		remove_quotes(argv[i + 2]);
		px->cmd[i]->args = ft_split(argv[i + 2], ' ');
		j = 0;
		while (px->cmd[i]->args[j])
			change_char(px->cmd[i]->args[j++], NOT_ASCII, ' ');
		px->cmd[i]->path = set_cmd_path(px->cmd[i]->args[0], px);
		if (!px->cmd[i]->path)
			perror(px->cmd[i]->args[0]);
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

static char	*change_char_between_quote(char *arg, char old_char, char new_char)
{
	char	*arg_pos;
	size_t	flag;

	flag = 0;
	arg_pos = arg;
	while (*arg != '\0')
	{
		if (*arg == '\'')
			flag = !flag;
		if (flag)
		{
			if (*arg == old_char)
				*arg = new_char;
		}
		arg++;
	}
	return (arg_pos);
}

static char	*change_char(char *arg, char old_char, char new_char)
{
	char	*arg_pos;

	arg_pos = arg;
	while (*arg != '\0')
	{
		if (*arg == old_char)
			*arg = new_char;
		arg++;
	}
	return (arg_pos);
}

static void	remove_quotes(char *arg)
{
	arg = ft_strchr(arg, '\'');
	while (arg != NULL)
	{
		ft_strcpy(arg, arg + 1);
		arg = ft_strchr(arg, '\'');
	}
}
