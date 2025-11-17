/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:53:40 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (!info)
		return ;
	if (server_is_not_listening())
		listen_to_client(info);
	else if (signal_is_from_different_client(info))
		return ;
	append_bit(sig == SIGUSR2);
	if (buffer_is_full())
		print_buffer();
	if (server_is_listening())
		send_confirmation_signal();
}
