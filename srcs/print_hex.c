/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:25:48 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:07:52 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_write.h"
#include "../includes/utils_int_hex.h"
#include "../includes/flags.h"

int	print_hex_minus(unsigned int n, t_flags *flags)
{
	int	ans;

	ans = ft_putsymbols('0', flags->accuracy - hex_len(n));
	if (n || flags->accuracy)
		ans += ft_puthex(n, flags->conversion == 'X');
	else if (flags->width != -1)
		ans += ft_putchar(' ');
	ans += ft_putsymbols(' ', flags->width - ans);
	return (ans);
}

int	print_hex_zero(unsigned int n, t_flags *flags)
{
	int	ans;

	if (flags->accuracy == -1)
		flags->accuracy = flags->width;
	ans = ft_putsymbols(' ', flags->width
			- max_int(flags->accuracy, hex_len(n)));
	ans += ft_putsymbols('0', flags->accuracy - hex_len(n));
	if (n || flags->accuracy)
		ans += ft_puthex(n, flags->conversion == 'X');
	else if (flags->width != -1)
		ans += ft_putchar(' ');
	return (ans);
}

int	print_hex(unsigned int n, t_flags *flags)
{
	int	ans;

	ans = ft_putsymbols(' ', flags->width
			- max_int(hex_len(n), flags->accuracy));
	if (flags->flag == '#' && n)
		ans += ft_putchar('0') + ft_putchar(flags->conversion);
	ans += ft_putsymbols('0', flags->accuracy - hex_len(n));
	if (n || flags->accuracy)
		ans += ft_puthex(n, flags->conversion == 'X');
	else if (flags->width != -1)
		ans += ft_putchar(' ');
	return (ans);
}

int	ft_print_hex(va_list ap, t_flags *flags)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (flags->flag == '-')
		return (print_hex_minus(n, flags));
	if (flags->flag == '0')
		return (print_hex_zero(n, flags));
	return (print_hex(n, flags));
}
