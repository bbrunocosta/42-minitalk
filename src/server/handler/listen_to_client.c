/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:59:37 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void	listen_to_client(siginfo_t *info)
{
	g_state.client_pid = info->si_pid;
	g_state.buffer = 0;
	g_state.bit_count = 0;
}
