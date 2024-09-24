/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:25:56 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/24 14:03:09 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig_confirm;

static void	received(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received by the server.\n");
	else
		ft_printf("Error. Try again.\n");
}

void	acknowledge(int sig)
{
	(void)sig;
	g_sig_confirm = 1;
}

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
		while (!g_sig_confirm)
			;
		g_sig_confirm = 0;
		c >>= 1;
		bit++;
	}
}

int	main(int ac, char **av)
{
	size_t	pid;
	int		i;

	i = 0;
	if (ac != 3)
		return (ft_printf("Error. Try \"./client <PID> <MESSAGE>\".\n"), 1);
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("Error. Invalid PID.\n"), 1);
	signal(SIGUSR1, acknowledge);
	signal(SIGUSR2, received);
	while (av[2][i])
	{
		sendbyte(av[2][i], pid);
		i++;
	}
	sendbyte(0, pid);
	return (0);
}
