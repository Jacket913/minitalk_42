/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:56:18 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/17 16:26:13 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_safe_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_safe_strlen(s)));
}

int	put_ptr(unsigned long n, unsigned long baselength, char *base)
{
	unsigned long	length;

	length = 0;
	if (n >= baselength)
		length += pnbase(n / baselength, baselength, base);
	return (length + ft_putchar(base[n % baselength]));
}

int	ft_print_ptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (put_ptr((unsigned long)ptr, 16, "0123456789abcdef") + 2);
}
