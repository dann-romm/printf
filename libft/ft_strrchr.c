/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:54:42 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:13 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				pos;
	unsigned char	value;

	i = 0;
	pos = 0;
	value = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == value)
			pos = i;
		i++;
	}
	if (s[pos] == value)
		return ((char *) &s[pos]);
	if (s[i] == value)
		return ((char *) &s[i]);
	return (0);
}
