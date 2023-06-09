# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/02/27 20:51:01 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := minitalk

# Dirs ==========================================

SRC_DIR := src
INC_DIR := include
LIB_DIR := lib
BIN_DIR := .

# Exes ==========================================

CLIENTEXE :=	$(BIN_DIR)/client

SERVEREXE :=	$(BIN_DIR)/server

# Compilation ====================================

CC := cc
LDFLAGS ?= 
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR)

# Src files ======================================

HEADERS := 	$(INC_DIR)/ft_printf.h\
		$(INC_DIR)/libft.h\
		$(INC_DIR)/minitalk.h\

UTILSFILES := 	$(SRC_DIR)/base_conversion.c\
		$(SRC_DIR)/utils.c\
		$(SRC_DIR)/utils2.c\

CLIENTFILES := 	$(SRC_DIR)/client.c\

SERVERFILES := 	$(SRC_DIR)/server.c\

BONUS_CLIENTFILES := 	$(SRC_DIR)/client_bonus.c\

BONUS_SERVERFILES := 	$(SRC_DIR)/server_bonus.c\

# Make all ========================================

all : $(NAME)

$(NAME): client server

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Objects ========================================

UTILSOBJS :=	$(UTILSFILES:.c=.o)

CLIENTOBJS :=	$(CLIENTFILES:.c=.o)

SERVEROBJS :=	$(SERVERFILES:.c=.o)

BONUS_CLIENTOBJS :=	$(BONUS_CLIENTFILES:.c=.o)

BONUS_SERVEROBJS :=	$(BONUS_SERVERFILES:.c=.o)

# Libs ==========================================

LIBFT := $(LIB_DIR)/libft/libft.a

PRINTF := $(LIB_DIR)/libftprintf/libftprintf.a

$(LIBFT) :
	make -C lib/libft -f Makefile

$(PRINTF) :
	make -C lib/libftprintf -f Makefile

# Recipes ========================================

client : $(UTILSOBJS) $(CLIENTOBJS) $(LIBFT) $(PRINTF)
	$(CC) $(LDFLAGS) -o $(CLIENTEXE) $^

server : $(UTILSOBJS) $(SERVEROBJS) $(LIBFT) $(PRINTF)
	$(CC) $(LDFLAGS) -o $(SERVEREXE) $^

bonus_client : $(UTILSOBJS) $(BONUS_CLIENTOBJS) $(LIBFT) $(PRINTF)
	$(CC) $(LDFLAGS) -o $(CLIENTEXE) $^

bonus_server : $(UTILSOBJS) $(BONUS_SERVEROBJS) $(LIBFT) $(PRINTF)
	$(CC) $(LDFLAGS) -o $(SERVEREXE) $^

bonus : bonus_client bonus_server

# Cleanup ========================================

clean:
	make -C lib/libft -f Makefile clean
	make -C lib/libftprintf -f Makefile clean
	rm -rf $(UTILSOBJS) $(CLIENTOBJS) $(SERVEROBJS)
	rm -rf $(BONUS_CLIENTOBJS) $(BONUS_SERVEROBJS)

fclean : clean
	make -C lib/libft -f Makefile fclean
	make -C lib/libftprintf -f Makefile fclean
	rm -rf $(CLIENTEXE) $(SERVEREXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re

