/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:43:57 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:07:59 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_write.h"
#include "../includes/utils_int_hex.h"
#include "../includes/flags.h"

int	ft_print_pointer(va_list ap, t_flags *flags)
{
	unsigned long long	n;
	int					ans;

	n = va_arg(ap, unsigned long long);
	ans = 0;
	if (flags->flag != '-')
	{
		ans += ft_putsymbols(' ', flags->width - hex_len(n) - 2);
		if (!n && flags->accuracy == 0 && flags->width > 1)
			ans += ft_putchar(' ');
	}
	ans += ft_putstr("0x");
	if (n || flags->accuracy)
		ans += ft_puthex(n, 0);
	if (flags->flag == '-')
	{
		ans += ft_putsymbols(' ', flags->width - hex_len(n) - 2);
		if (!n && flags->accuracy == 0 && flags->width > 1)
			ans += ft_putchar(' ');
	}
	return (ans);
}
