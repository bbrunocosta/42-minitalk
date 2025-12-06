/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:53:46 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:23 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H
# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct sigaction	t_sigaction;

typedef struct s_state
{
	unsigned char	buffer;
	pid_t			client_pid;
	int				bit_count;
}	t_state;

extern t_state				g_state;

void						signal_handler(int sig, siginfo_t *info, void *ctx);
void						append_bit(int bit);
void						print_buffer(void);
void						send_confirmation_signal(void);
int							buffer_is_full(void);
int							server_is_listening(void);
int							server_is_not_listening(void);
void						listen_to_client(siginfo_t *info);
int							signal_is_from_different_client(siginfo_t *info);
void						print_pid(void);
void						ft_memset(void *s, int c, size_t n);
void						ft_putchar(char c);
void						ft_putnumber(int n);
void						ft_putstr(const char *str);
void						print_error_and_exit(const char *msg);

#endif
