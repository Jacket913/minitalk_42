/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:46 by gmoulin           #+#    #+#             */
/*   Updated: 2024/01/04 23:05:59 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*destret;

	if (!dest && !src)
		return (NULL);
	destret = dest;
	if (src < dest)
	{
		src += (n - 1);
		dest += (n - 1);
		while (n--)
			*(char *)dest-- = *(char *)src--;
	}
	else
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	return (destret);
}
