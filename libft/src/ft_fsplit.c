/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:59:47 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/12 18:37:31 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_fsplit(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}
