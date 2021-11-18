/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:39:48 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:13:38 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	int_len(int n, long long *p, size_t *len)
{
	*len = 0;
	*p = 1;
	while (n / *p)
	{
		*p *= 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	p;
	char		*str;

	int_len(n, &p, &len);
	str = malloc(sizeof(char) * (len + (n <= 0) + 1));
	if (str == 0)
		return (0);
	len = 0;
	if (n < 0)
		str[len++] = '-';
	p /= 10;
	str[len] = '0';
	str[len + 1] = 0;
	while (p)
	{
		str[len++] = ((n / p) % 10) * (n > 0) + -(n / p % 10) * (n <= 0) + '0';
		p /= 10;
	}
	str[len + (n == 0)] = 0;
	return (str);
}
