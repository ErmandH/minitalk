SV = server
CLI = client

SV_BONUS = bonus/server
CLI_BONUS = bonus/client

MAN = mandatory
BNS = bonus

SV_SRC = $(MAN)/servers/server.c $(MAN)/servers/utils.c $(MAN)/error.c
CLI_SRC = $(MAN)/cli/client.c $(MAN)/cli/utils.c $(MAN)/error.c

SV_SRC_BONUS = $(BNS)/servers/server_bonus.c $(BNS)/servers/utils_bonus.c \
				$(BNS)/error_bonus.c

CLI_SRC_BONUS = $(BNS)/cli/client_bonus.c $(BNS)/cli/utils_bonus.c \
				$(BNS)/error_bonus.c

SV_OBJ = $(SV_SRC:.c=.o)
CLI_OBJ = $(CLI_SRC:.c=.o)

SV_OBJ_BONUS = $(SV_SRC_BONUS:.c=.o)
CLI_OBJ_BONUS = $(CLI_SRC_BONUS:.c=.o)


CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(SV) $(CLI)

$(SV): $(SV_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 

$(CLI): $(CLI_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 

bonus : $(SV_BONUS) $(CLI_BONUS)
	
$(SV_BONUS): $(SV_OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLI_BONUS): $(CLI_OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(SV_OBJ) $(CLI_OBJ) $(SV_OBJ_BONUS) $(CLI_OBJ_BONUS)

fclean: clean
	rm -f $(SV) $(CLI)

norm:
	norminette -R CheckForbiddenSourceHeader $(SV_SRC) $(CLI_SRC) minitalk.h

re: fclean all

