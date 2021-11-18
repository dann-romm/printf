/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:39:12 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:06 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == 0)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = (char) s1[i];
	i = 0;
	while (s2[i])
	{
		str[i + len1] = (char) s2[i];
		i++;
	}
	str[i + len1] = 0;
	return (str);
}
