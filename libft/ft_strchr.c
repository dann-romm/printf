/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:50:53 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:02 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	value;

	value = (unsigned char) c;
	i = 0;
	while (s[i] && s[i] != value)
		i++;
	if (s[i] == value)
		return ((char *) &s[i]);
	return (0);
}
