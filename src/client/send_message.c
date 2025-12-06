/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:02:31 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/24 17:47:12 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void send_bit(pid_t server_pid, int bit)
{
    int sig = to_signal(bit);

    g_ack_received = 0;
    if (kill(server_pid, sig) == -1)
        print_error_and_exit("Error sending signal\n");

    while (!g_ack_received)
        pause();  
}


void	send_char(pid_t server_pid, unsigned char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		send_bit(server_pid, bit);
		i++;
	}
}

void	send_message(pid_t server_pid, const char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(server_pid, msg[i]);
		i++;
	}
	send_char(server_pid, '\0');
}
