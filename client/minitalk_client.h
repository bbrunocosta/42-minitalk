/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:41:27 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:52:19 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H
# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

extern volatile sig_atomic_t	g_ack_received;

typedef struct sigaction		t_sigaction;

void							ack_handler(int sig);
void							send_bit(pid_t server_pid, int bit);
void							send_char(pid_t server_pid, unsigned char c);
void							send_message(pid_t server_pid, const char *msg);
int								ft_atoi(const char *str);
int								to_signal(int bit);
pid_t							get_server_pid(int argc, char **argv);
void							ft_memset(void *s, int c, size_t n);
void							print_error_and_exit(const char *msg);

#endif
