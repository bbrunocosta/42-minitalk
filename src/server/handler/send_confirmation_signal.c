/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_confirmation_signal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:29 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:59:59 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void	send_confirmation_signal(void)
{
	kill(g_state.client_pid, SIGUSR1);
}
