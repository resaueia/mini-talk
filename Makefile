# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:58:15 by rsaueia-          #+#    #+#              #
#    Updated: 2024/03/05 20:02:14 by rsaueia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CLIENT_SRC = client.c

SERVER_SRC = server.c

CLIENT_NAME = client

SERVER_NAME = server

OBJS_SERVER = $(SERVER_SRC:.c=.o)

OBJS_CLIENT = $(CLIENT_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTF_PATH = printf

PRINTF_ARCHIVE = $(PRINTF_PATH)/libftprintf.a

$(NAME): $(PRINTF_ARCHIVE) $(SERVER_NAME) $(CLIENT_NAME)
	ar rcs $(NAME)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) $(CLIENT_NAME): $(OBJS_SERVER) $(OBJS_CLIENT) $(NAME) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF_ARCHIVE) -o $(SERVER_NAME)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_ARCHIVE) -o $(CLIENT_NAME)

$(PRINTF_ARCHIVE):
	make -C $(PRINTF_PATH)

clean:
	make -C $(PRINTF_PATH) clean
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re
