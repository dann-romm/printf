/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:27:07 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:12:43 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/utils_write.h"
#include "../includes/flags.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_flags	*flags;
	int		i;
	int		len;

	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			flags = handle_flags(&s[i], &i, ap);
			if (!flags)
				return (-1);
			len += write_argument(ap, flags);
		}
		else
			len += ft_putchar(s[i++]);
	}
	va_end(ap);
	return (len);
}
