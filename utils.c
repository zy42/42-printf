/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeng <yzeng@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:38:18 by yzeng             #+#    #+#             */
/*   Updated: 2023/10/10 17:48:56 by yzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count += 1;
	}
	return (count);
}

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	min_len;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		min_len = min(len, ft_strlen(s) - start);
		if (min_len > 0)
		{
			result = (char *)malloc((min_len + 1) * sizeof(char));
			if (!result)
				return (NULL);
			result = ft_memcpy(result, s + start, min_len);
			result[min_len] = '\0';
			return (result);
		}
	}
	result = (char *)malloc(1 * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, "", 1);
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
int	main()
{
	//char const	str[] = "ABCDE";
	//char * s = ft_substr("trisdfDB", 100, 1);;
	printf("%s\n",ft_substr("hola", 2, 3));
}*/
