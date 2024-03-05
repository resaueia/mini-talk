# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:58:15 by rsaueia-          #+#    #+#              #
#    Updated: 2024/03/05 16:58:27 by rsaueia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRC = client.c

SERVER_SRC = server.c

PRINTF_PATH = ft_printf

PRINTF_ARCHIVE = $(PRINTF_PATH)/ft_printf.a

CLIENT_NAME = client

SERVER_NAME = server

OBJS_SERVER = $(SERVER_SRC:.c=.o)

OBJS_CLIENT = $(CLIENT_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) -L$(PRINTF_PATH) -lft

$(SERVER_NAME): $(SERVER_SRC) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) -L$(PRINTF_PATH) -lft

$(PRINTF_ARCHIVE):
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
