/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:20:09 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:11:54 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long long n)
{
	if (n == LLONG_MIN)
		return (write(1, "−9223372036854775808", 20));
	if (n < 0)
		return (write(1, "-", 1) + ft_putnbr(-n));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
}

int	ft_putstr(char *s)
{
	if (s == 0)
		return (0);
	return (write(1, s, ft_strlen(s)));
}

int	ft_puthexchar(int c, int uppercase)
{
	c += 48;
	if (c > 57)
	{
		if (uppercase)
			c += 7;
		else
			c += 39;
		return (write(1, &c, 1));
	}
	return (write(1, &c, 1));
}

int	ft_puthex(unsigned long long n, int uppercase)
{
	int	shift;
	int	len;

	shift = 60;
	while ((n >> shift) == 0 && shift)
		shift -= 4;
	len = shift / 4 + 1;
	while (shift > -1)
	{
		ft_puthexchar((n >> shift) % 16, uppercase);
		shift -= 4;
	}
	return (len);
}
