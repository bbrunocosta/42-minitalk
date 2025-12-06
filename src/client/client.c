/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:35:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:47:40 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

int	main(int argc, char **argv)
{
	t_sigaction	sa;
	pid_t		server_pid;
	const char	*msg;

	server_pid = get_server_pid(argc, argv);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = ack_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error_and_exit("Error setting up signal handler\n");
	msg = argv[2];
	send_message(server_pid, msg);
	return (0);
}
