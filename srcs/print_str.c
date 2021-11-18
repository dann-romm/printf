/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:48:20 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:14:44 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/utils_write.h"
#include "../includes/utils_int_hex.h"
#include "../includes/flags.h"

int	print_strn_null(char *s, int size)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (size > 6)
			return (write(1, "(null)", 6));
		return (write(1, "(null)", size));
	}
	while (s[i] && i < size)
		ft_putchar(s[i++]);
	return (i);
}

int	strlen_null(const char *s)
{
	int	len;

	if (!s)
		return (6);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_print_str(va_list ap, t_flags *flags)
{
	char	*s;
	int		ans;

	s = va_arg(ap, void *);
	ans = 0;
	if (flags->accuracy == -1)
		flags->accuracy = strlen_null(s);
	if (flags->flag != '-')
		ans += ft_putsymbols(' ', flags->width
				- min_int(flags->accuracy, strlen_null(s)));
	ans += print_strn_null(s, flags->accuracy);
	if (flags->flag == '-')
		ans += ft_putsymbols(' ', flags->width
				- min_int(flags->accuracy, strlen_null(s)));
	return (ans);
}
