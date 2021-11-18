/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:53:04 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:17:20 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/flags.h"

// ft_printf.c
int			ft_printf(const char *s, ...);

// handle_flags.c
t_flags		*handle_flags(const char *s, int *pos, va_list ap);

// write_argument.c
int			write_argument(va_list ap, t_flags *flags);

// print_*.c
int			ft_print_percent(t_flags *flags);
int			ft_print_decimal(va_list ap, t_flags *flags);
int			ft_print_unsigned_decimal(va_list ap, t_flags *flags);
int			ft_print_char(va_list ap, t_flags *flags);
int			ft_print_str(va_list ap, t_flags *flags);
int			ft_print_hex(va_list ap, t_flags *flags);
int			ft_print_pointer(va_list ap, t_flags *flags);

#endif // FT_PRINTF_H
