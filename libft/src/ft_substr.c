/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:22:29 by gmoulin           #+#    #+#             */
/*   Updated: 2024/01/04 18:53:28 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	bkplen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	s += start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	bkplen = len;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (len--)
		*ptr++ = *s++;
	*ptr = '\0';
	ptr -= bkplen;
	return (ptr);
}
