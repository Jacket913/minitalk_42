/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:25:50 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/17 16:18:18 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Converts a binary string to a char and prints it
void	sighandler(int sig, siginfo_t *info, void *context)
{
	static int	result;
	static int	bit;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		result |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (result == 0)
		{
			printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", result);
		result = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (ft_printf("Error. Try \"./server\".\n"), 1);
	ft_printf("PID: %d\nListening for signals...\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigemptyset(&sa.sa_mask);
	while (ac == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
