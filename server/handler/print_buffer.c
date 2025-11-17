/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:22 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:59:51 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void	print_buffer(void)
{
	unsigned char	current_char;

	current_char = g_state.buffer;
	g_state.buffer = 0;
	g_state.bit_count = 0;
	if (current_char == '\0')
	{
		ft_putchar('\n');
		g_state.client_pid = 0;
	}
	else
	{
		ft_putchar(current_char);
	}
}
