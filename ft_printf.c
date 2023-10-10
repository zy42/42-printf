/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeng <yzeng@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:15:20 by yzeng             #+#    #+#             */
/*   Updated: 2023/10/10 18:45:17 by yzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>
void	print_param(const char *str, va_list *params)
{
	if (*(str + 1))
	       if (va_arg(*params, int) == 'c' && *(str + 1) == 'c')
		       write(1, str + 1, 1);
}

int	ft_printf(const char *str, ...)
{
	char	**datatype;
	int	i;

	va_list	params;
	va_start(params, 2);

	for (i = 0; i < 3; i++)
	{
		while (*str)
		{
			if (*str != '%')
			{
				write(1, str,1);
				str++;
			}
			else
			{
				print_param(str, params);
				if (* (str + 2))
					str += 2;
				else
					return (NULL);
			}
		}
	}
	va_end(params);
}

int	main()
{
	char c = 'c';
	char d = 'd';
	ft_printf("SBF%c,%c", c,d);
}
