/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:50 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:53:51 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

int	main(void)
{
	t_sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error_and_exit("Error setting up signal handlers\n");
	print_pid();
	while (1)
		pause();
	return (0);
}
