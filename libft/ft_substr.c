/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:33:36 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:15 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (min(max(size - start, 0), len) + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (s[i + start] && i < len && (i + start) <= size)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}
