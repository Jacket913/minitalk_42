/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:00:44 by gmoulin           #+#    #+#             */
/*   Updated: 2024/01/04 14:01:57 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && n--)
	{
		s1++;
		s2++;
		if (n == 0)
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
