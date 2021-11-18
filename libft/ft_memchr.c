/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:15:43 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/11 19:31:55 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	value;

	str = (unsigned char *) s;
	value = (unsigned char) c;
	i = 0;
	while (i < n && str[i] != value)
		i++;
	if (i != n && str[i] == value)
		return ((void *) &str[i]);
	return (0);
}
