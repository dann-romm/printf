/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:43:46 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:17:52 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_printf.h"
#include "../includes/flags.h"

int	write_argument(va_list ap, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->conversion == '%')
		len = ft_print_percent(flags);
	if (flags->conversion == 'i' || flags->conversion == 'd'
		|| flags->conversion == 'u')
		len = ft_print_decimal(ap, flags);
	if (flags->conversion == 'c')
		len = ft_print_char(ap, flags);
	if (flags->conversion == 's')
		len = ft_print_str(ap, flags);
	if (flags->conversion == 'x' || flags->conversion == 'X')
		len = ft_print_hex(ap, flags);
	if (flags->conversion == 'p')
		len = ft_print_pointer(ap, flags);
	free(flags);
	return (len);
}
