/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:03 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:07:56 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_write.h"
#include "../includes/flags.h"

int	ft_print_percent(t_flags *flags)
{
	int	ans;

	ans = 0;
	if (flags->flag != '-')
	{
		if (flags->flag == '0')
			ans += ft_putsymbols('0', flags->width - 1);
		else
			ans += ft_putsymbols(' ', flags->width - 1);
	}
	ans += ft_putchar('%');
	if (flags->flag == '-')
		ans += ft_putsymbols(' ', flags->width - 1);
	return (ans);
}
