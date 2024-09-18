/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:56:28 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/17 16:26:43 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pnbase(long n, int baselength, char *base)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n *= -1;
		length += ft_putchar('-');
	}
	if (n >= baselength)
		length += pnbase(n / baselength, baselength, base);
	return (length + ft_putchar(base[n % baselength]));
}

int	check_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args[0], int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args[0], char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args[0], void *)));
	else if (c == 'd')
		return (pnbase(va_arg(args[0], int), 10, "0123456789"));
	else if (c == 'i')
		return (pnbase(va_arg(args[0], int), 10, "0123456789"));
	else if (c == 'u')
		return (pnbase(va_arg(args[0], unsigned int), 10, "0123456789"));
	else if (c == 'x')
		return (pnbase(va_arg(args[0], unsigned int), 16, "0123456789abcdef"));
	else if (c == 'X')
		return (pnbase(va_arg(args[0], unsigned int), 16, "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	length = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			length += check_format(format[++i], &args);
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
