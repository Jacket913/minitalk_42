/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:25:56 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/27 16:47:54 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Converts a string to binary
void	sendbyte(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		bit++;
		usleep(100);
	}
}

//Sends the binary string to the server
int		main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (ft_printf("Error. Try \"./client <PID> <MESSAGE>\".\n"), 1);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		sendbyte(av[2][i], pid);
		i++;
	}
	return (0);
}
