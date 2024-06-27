/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:56:28 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/26 10:21:35 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while(format[i] != '\0')
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

/*int main() {
	ft_printf("yo %c, %c\n", '0', 0);
}*/
