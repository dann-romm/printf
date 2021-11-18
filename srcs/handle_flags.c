/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:37:12 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 20:13:35 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/flags.h"

static int	handle_flag(char c, t_flags *flags)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
	{
		flags->flag = c;
		return (1);
	}
	flags->flag = 0;
	return (0);
}

static int	handle_width(const char *s, t_flags *flags, va_list ap)
{
	int	i;

	i = 0;
	if (ft_isdigit(s[0]) || *s == '*' || *s == '-' || *s == ' ' || *s == '+')
	{
		flags->width = ft_atoi(s);
		if (s[0] == '-')
			flags->width = -flags->width * ++i;
		while (s[i] == '-' || s[i] == '0' || s[i] == ' ' || s[i] == '+')
			i++;
		if (s[i] == '*')
		{
			flags->width = va_arg(ap, int) * (++i > 0);
			if (flags->width < 0)
			{
				flags->width = -flags->width;
				flags->flag = '-';
			}
		}
		while (ft_isdigit(s[i]))
			i++;
		return (i);
	}
	flags->width = -1;
	return (0);
}

static int	handle_accuracy(const char *s, t_flags *flags, va_list ap)
{
	int	i;

	if (s[0] == '.')
	{
		if (s[1] == '*')
		{
			flags->accuracy = va_arg(ap, int);
			if (flags->accuracy < 0)
				flags->accuracy = -1;
			return (2);
		}
		flags->accuracy = ft_atoi(&(s[1]));
		if (flags->accuracy < 0)
			flags->accuracy = -flags->accuracy;
		i = 1;
		while (ft_isdigit(s[i]))
			i++;
		return (i);
	}
	flags->accuracy = -1;
	return (0);
}

static int	handle_conversion(char c, t_flags *flags)
{
	flags->conversion = c;
	return (1);
}

t_flags	*handle_flags(const char *s, int *pos, va_list ap)
{
	t_flags	*flags;
	int		i;

	flags = (t_flags *) malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	i = 1;
	i += handle_flag(s[i], flags);
	i += handle_width(&(s[i]), flags, ap);
	i += handle_accuracy(&(s[i]), flags, ap);
	i += handle_conversion(s[i], flags);
	*pos += i;
	return (flags);
}
