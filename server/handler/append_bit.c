/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:10 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:59:21 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void	append_bit(int bit)
{
	g_state.buffer |= (bit << g_state.bit_count);
	g_state.bit_count++;
}
