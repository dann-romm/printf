/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:35:44 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:07:49 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_write.h"
#include "../includes/utils_int_hex.h"
#include "../includes/flags.h"

int	print_decimal_minus(long long n, t_flags *flags)
{
	int	ans;

	ans = (n < 0);
	if (ans)
		n = -n * ft_putchar('-');
	ans += ft_putsymbols('0', flags->accuracy - number_len(n));
	if (n || flags->accuracy)
		ans += ft_putnbr(n);
	else if (flags->width != -1)
		ans += ft_putchar(' ');
	ans += ft_putsymbols(' ', flags->width - ans);
	return (ans);
}

int	print_decimal_zero(long long n, t_flags *flags)
{
	int	ans;
	int	len;

	if (flags->accuracy == -1)
		flags->accuracy = flags->width - (n < 0);
	ans = 0;
	len = max_int(flags->accuracy, number_len(n)) + (n < 0);
	ans = ft_putsymbols(' ', flags->width - len);
	len = flags->width - len;
	if (n < 0)
		ans += ft_putchar('-');
	ans += ft_putsymbols('0', flags->accuracy - number_len(n));
	if (n || flags->accuracy)
		ans += ft_putnbr(abs_long(n));
	else if (flags->width != -1)
		ans += ft_putchar(' ');
	return (ans);
}

int	print_decimal(long long n, t_flags *flags)
{
	int	ans;
	int	len;

	ans = (flags->flag || (n < 0));
	len = max_int(number_len(n), flags->accuracy) + (n < 0);
	ans += ft_putsymbols(' ', flags->width - len);
	if (n < 0)
		n = -n * ft_putchar('-');
	else if (flags->flag)
		ft_putchar(flags->flag);
	ans += ft_putsymbols('0', flags->accuracy - number_len(n));
	if (n || flags->accuracy)
		ans += ft_putnbr(n);
	else if (flags->width != -1)
		ans += ft_putchar(' ');
	return (ans);
}

int	ft_print_decimal(va_list ap, t_flags *flags)
{
	long long	n;

	if (flags->conversion == 'u')
		n = va_arg(ap, unsigned int);
	else
		n = va_arg(ap, int);
	if (flags->flag == '-')
		return (print_decimal_minus(n, flags));
	if (flags->flag == '0')
		return (print_decimal_zero(n, flags));
	return (print_decimal(n, flags));
}
