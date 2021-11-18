/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:26:55 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:13 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_comp(char *substr, const char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] && substr[i])
	{
		if (to_find[i] != substr[i])
			return (0);
		i++;
	}
	if (to_find[i] == 0)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;
	size_t	needle_len;

	str = (char *) haystack;
	if (*needle == 0)
		return (str);
	needle_len = ft_strlen(needle);
	i = 0;
	while (str[i] && (i + needle_len - 1) < len)
	{
		if (find_comp(&str[i], needle))
			return (&str[i]);
		i++;
	}
	return (0);
}
