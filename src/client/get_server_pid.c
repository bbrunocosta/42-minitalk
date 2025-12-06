/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_server_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:41:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:47:36 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

pid_t	get_server_pid(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc < 3)
		print_error_and_exit("Missing server PID or message\n");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		print_error_and_exit("Invalid server PID\n");
	return (server_pid);
}
