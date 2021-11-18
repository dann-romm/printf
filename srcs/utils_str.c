/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:58:28 by doalbaco          #+#    #+#             */
/*   Updated: 2021/11/18 19:40:04 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putsymbols(char c, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		write(1, &c, 1);
	return (i);
}
