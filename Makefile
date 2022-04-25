CLIENT = client
SERVER = server

CLIENT_B = client_b
SERVER_B = server_b

FILES_S = server.c  ft_printf.c utils.c
FILES_C = client.c ft_atoi.c ft_printf.c utils.c
FILES_S_B = server_bonus.c  ft_printf_bonus.c utils_bonus.c
FILES_C_B = client_bonus.c ft_atoi_bonus.c ft_printf_bonus.c utils_bonus.c

OBJ_SERVER = $(FILES_S:.c=.o)
OBJ_CLIENT = $(FILES_C:.c=.o)
OBJ_SERVER_B = $(FILES_S_B:.c=.o)
OBJ_CLIENT_B = $(FILES_C_B:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: 		$(CLIENT) $(SERVER)


$(CLIENT): 	$(OBJ_CLIENT) client.h
			$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER): 	$(OBJ_SERVER) server.h
			$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT_B): 	$(OBJ_CLIENT_B) client_bonus.h
			$(CC) $(CFLAGS) $(OBJ_CLIENT_B) -o $(CLIENT_B)

$(SERVER_B): 	$(OBJ_SERVER_B) server_bonus.h
			$(CC) $(CFLAGS) $(OBJ_SERVER_B) -o $(SERVER_B)

bonus: 		$(CLIENT_B) $(SERVER_B)

clean:
			$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)

fclean:		clean
			$(RM) server client client_b server_b

re: 		fclean all


.PHONY:		all re clean fclean
