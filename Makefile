# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 16:54:26 by bcosta-b          #+#    #+#              #
#    Updated: 2025/12/06 18:26:42 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server
CLIENT_NAME = client

SERVER_OBJDIR = src/server/obj
CLIENT_OBJDIR = src/client/obj
UTILS_OBJDIR = src/utils/obj

UTILS_SRCS = src/utils/ft_memset.c \
             src/utils/ft_putchar.c \
             src/utils/ft_putnumber.c \
             src/utils/ft_putstr.c \
             src/utils/print_error_and_exit.c

SERVER_SRCS = src/server/server.c \
              src/server/state.c \
              src/server/handler/append_bit.c \
              src/server/handler/buffer_is_from_different_client.c \
              src/server/handler/listen_to_client.c \
              src/server/handler/print_buffer.c \
              src/server/handler/print_pid.c \
              src/server/handler/send_confirmation_signal.c \
              src/server/handler/server_is_listening.c \
              src/server/handler/server_is_not_listening.c \
              src/server/handler/signal_handler.c \
              src/server/handler/signal_is_from_different_client.c

CLIENT_SRCS = src/client/client.c \
              src/client/ft_atoi.c \
              src/client/get_server_pid.c \
              src/client/send_message.c \
              src/client/to_signal.c

SERVER_OBJS = $(addprefix $(SERVER_OBJDIR)/, $(notdir $(SERVER_SRCS:.c=.o)))
CLIENT_OBJS = $(addprefix $(CLIENT_OBJDIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))
UTILS_OBJS = $(addprefix $(UTILS_OBJDIR)/, $(notdir $(UTILS_SRCS:.c=.o)))

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_OBJDIR)/%.o: src/server/%.c
	@mkdir -p $(SERVER_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJDIR)/%.o: src/server/handler/%.c
	@mkdir -p $(SERVER_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJDIR)/%.o: src/client/%.c
	@mkdir -p $(CLIENT_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_OBJDIR)/%.o: src/utils/%.c
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
