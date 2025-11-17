# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 16:54:26 by bcosta-b          #+#    #+#              #
#    Updated: 2025/11/17 17:15:23 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = minitalk_server
CLIENT_NAME = minitalk_client

SERVER_OBJDIR = server/obj
CLIENT_OBJDIR = client/obj
UTILS_OBJDIR = utils/obj

UTILS_SRCS = utils/ft_memset.c \
             utils/ft_putchar.c \
             utils/ft_putnumber.c \
             utils/ft_putstr.c \
             utils/print_error_and_exit.c

SERVER_SRCS = server/server.c \
              server/state.c \
              server/handler/append_bit.c \
              server/handler/buffer_is_from_different_client.c \
              server/handler/listen_to_client.c \
              server/handler/print_buffer.c \
              server/handler/print_pid.c \
              server/handler/send_confirmation_signal.c \
              server/handler/server_is_listening.c \
              server/handler/server_is_not_listening.c \
              server/handler/signal_handler.c \
              server/handler/signal_is_from_different_client.c

CLIENT_SRCS = client/client.c \
              client/ft_atoi.c \
              client/get_server_pid.c \
              client/send_message.c \
              client/to_signal.c

SERVER_OBJS = $(addprefix $(SERVER_OBJDIR)/, $(notdir $(SERVER_SRCS:.c=.o)))
CLIENT_OBJS = $(addprefix $(CLIENT_OBJDIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))
UTILS_OBJS = $(addprefix $(UTILS_OBJDIR)/, $(notdir $(UTILS_SRCS:.c=.o)))

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_OBJDIR)/%.o: server/%.c
	@mkdir -p $(SERVER_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJDIR)/%.o: server/handler/%.c
	@mkdir -p $(SERVER_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJDIR)/%.o: client/%.c
	@mkdir -p $(CLIENT_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_OBJDIR)/%.o: utils/%.c
	@mkdir -p $(UTILS_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME): $(SERVER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(UTILS_OBJS)

$(CLIENT_NAME): $(CLIENT_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(UTILS_OBJS)

clean:
	rm -rf $(SERVER_OBJDIR) $(CLIENT_OBJDIR) $(UTILS_OBJDIR)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
