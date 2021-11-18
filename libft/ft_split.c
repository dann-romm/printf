/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:18 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/11 19:45:19 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			count++;
			i++;
		}
		if (count > 0)
			j++;
	}
	return (j);
}

static size_t	free_arr(char **arr)
{
	while (*arr)
		free(*arr++);
	free(arr);
	return (1);
}

static size_t	allocate_strs(char **arr, const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			count++;
			i++;
		}
		if (count > 0)
		{
			arr[j] = (char *) malloc(sizeof(char) * (count + 1));
			if (!arr[j++])
				return (free_arr(arr));
		}
	}
	return (0);
}

static void	fill_strs(char **arr, const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			arr[j][count++] = str[i++];
		if (count > 0)
			arr[j][count] = 0;
		j++;
	}
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	size_t	count;

	if (str == 0)
		return (0);
	count = count_words(str, c);
	arr = (char **) malloc(sizeof(char *) * (count + 1));
	if (arr == 0)
		return (0);
	arr[count] = 0;
	if (allocate_strs(arr, str, c))
		return (0);
	fill_strs(arr, str, c);
	return (arr);
}
