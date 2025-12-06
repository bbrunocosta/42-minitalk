/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/24 15:34:14 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void    signal_handler(int sig, siginfo_t *info, void *context)
{
        pid_t   client_pid;

        (void) context;
        if (!info)
                return ;
        if (g_state.client_pid == 0)
        {
                g_state.client_pid = info->si_pid;
	        g_state.buffer = 0;
	        g_state.bit_count = 0;
        }

        else if (signal_is_from_different_client(info))
                return ;
        append_bit(sig == SIGUSR2);
        if (buffer_is_full())
        {
                client_pid = g_state.client_pid;
                print_buffer();
                if (client_pid != 0)
                        kill(client_pid, SIGUSR1);
        }
        else if (server_is_listening())
                send_confirmation_signal();
}
