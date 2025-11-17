/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:54:20 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/11/17 16:54:20 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(const char *str);

void	print_error_and_exit(const char *msg)
{
	ft_putstr(msg);
	exit(EXIT_FAILURE);
}
