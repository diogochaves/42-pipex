/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:59:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/25 11:38:58 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static size_t	token_count2(char const *s, char c)
{
	size_t	flag;
	size_t	count;

	flag = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (count);
}

static void	create_tokens2(char **group, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	int		pos;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	pos = -1;
	while (i <= len)
	{
		if (s[i] != c && pos == -1)
			pos = i;
		else if ((s[i] == c || i == len) && pos != -1)
		{
			group[j] = malloc(sizeof(char) * (i - pos + 1));
			if (group[j])
				ft_strlcpy(group[j], s + pos, i - pos + 1);
			j++;
			pos = -1;
		}
		i++;
	}
	group[j] = 0;
}

char	**ft_split2(char const *s, char c)
{
	char	**group;

	group = malloc((token_count2(s, c) + 1) * sizeof(char *));
	if (!s || !group)
		return (0);
	create_tokens2(group, s, c);
	return (group);
}
