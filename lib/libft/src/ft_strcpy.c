/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:01:07 by dchaves-          #+#    #+#             */
/*   Updated: 2022/04/28 19:01:08 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_orig;

	dest_orig = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_orig);
}
