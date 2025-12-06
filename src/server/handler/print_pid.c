/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:25 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:53:26 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_server.h"

void	print_pid(void)
{
	ft_putstr("Server PID: ");
	ft_putnumber(getpid());
	ft_putstr("\nWaiting for signals...\n");
}
