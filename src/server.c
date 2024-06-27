/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:25:50 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/27 16:48:00 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Converts a binary string to a char and prints it
void	ft_sighandler(int sig)
{
	static int	result;
	static int	bit;

	if (sig == SIGUSR1)
		result |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", result);
		result = 0;
		bit = 0;
	}
}

//Receives and processes the binary string
int		main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
		return (ft_printf("Error. Try \"./server\".\n"), 1);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Listening for signals...\n");
	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	while (1)
	{
		pause();
	}
	return (0);
}

