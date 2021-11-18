/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:52:55 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:14 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	pref;
	size_t	suff;
	size_t	i;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	suff = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	pref = i;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i++]))
			suff++;
		else
			suff = 0;
	}
	str = malloc(sizeof(char) * (i - pref - suff + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1 + pref, i - pref - suff + 1);
	return (str);
}
