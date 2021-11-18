/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:21:05 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/11 19:43:01 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	while (i < dstsize && dst[i])
		i++;
	dst_len = i;
	i = 0;
	while ((i + dst_len + 1) < dstsize && src[i])
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	if (dstsize > dst_len)
		dst[i + dst_len] = 0;
	while (src[i])
		i++;
	return (i + min(dst_len, dstsize));
}
