/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeng <yzeng@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:06:34 by yzeng             #+#    #+#             */
/*   Updated: 2023/10/10 17:36:08 by yzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

/* Allocates (with malloc(3)) and returns an array of strings 
** obtained by splitting ’s’ using the character ’c’ as a delimiter. 
** The array must end with a NULL pointer.
*/

static size_t	arr_size(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
			j++;
	}
	return (j);
}

static void	*free_arr(char **arr, size_t index)
{
	while (arr[index])
	{
		free(arr[index]);
		index--;
	}
	free(arr);
	return (NULL);
}

static void	fill_arr(char const*s, char c, char **arr, size_t len)
{
	size_t	i;
	size_t	start;
	size_t	arr_ele;

	i = 0;
	arr_ele = 0;
	while (s[i] && arr_ele <= len)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			arr[arr_ele] = ft_substr(s, start, i - start);
			if (!arr[arr_ele])
				free_arr(arr, arr_ele);
			arr[arr_ele][i - start + 1] = '\0';
			arr_ele++;
		}
	}
	arr[arr_ele] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **) malloc(sizeof(char *) * (arr_size(s, c) + 1));
	if (!arr)
		return (NULL);
	fill_arr(s, c, arr, arr_size(s, c));
	return (arr);
}

/*
int main()
{
	//printf("%zu\n", arr_size("hello!xxxx", ' '));
	char **arr = ft_split("   lorem   ipsum dolor     sit amet, 
	consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	int i = 0;
	while (arr[i])
	{
		printf("%s\n",arr[i]);
		i++;
	}
}
*/
