/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:43:36 by gmoulin           #+#    #+#             */
/*   Updated: 2024/01/04 22:43:40 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rec_itoa(long nbr, char **buffer)
{
	if (nbr / 10 != 0)
		rec_itoa(nbr / 10, buffer);
	*(*buffer)++ = (nbr % 10) + '0';
}

static size_t	tomalloc(long nbr, int neg)
{
	size_t	size;

	size = 2;
	if (neg == 1)
		size++;
	while (nbr / 10)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		neg;
	long	nbr;
	char	*res;
	char	*ptr;

	neg = 0;
	nbr = n;
	if (nbr < 0)
		neg++;
	if (neg == 1)
		nbr *= -1;
	res = (char *)malloc(sizeof(char) * (tomalloc(nbr, neg)));
	if (!res)
		return (NULL);
	ptr = res;
	if (neg == 1)
		*res++ = '-';
	rec_itoa(nbr, &res);
	*res = '\0';
	return (ptr);
}
