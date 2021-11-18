/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:09:14 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 19:43:43 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	abs_long(long long a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	number_len(long long n)
{
	int	len;

	len = (n == 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	hex_len(unsigned long long n)
{
	int	len;

	len = (n == 0);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
