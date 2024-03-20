# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:29:37 by ssottori          #+#    #+#              #
#    Updated: 2024/03/20 14:24:09 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

CCFLAGS = cc -Wall -Wextra -Werror -g
RM = rm -rf
NAME = pipex

SRC_DIR = src
OBJ_DIR = obj
LIBFT_D = libft
INC = inc

SRCS = pipex.c \
       utils.c \

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_D)/libft.a
LIBS = -L$(LIBFT_D) -lft

HEADERS = -I$(INC) -I$(LIBFT_D)/inc

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_D)

$(NAME): $(OBJS)
			$(CCFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)
	@echo "[$(GREEN)PIPEX$(NC)] - $<"
#	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h

%.o: %.c
			@mkdir -p $(OBJ_DIR)
	echo "[$(GREEN)PIPEX$(NC)] - $<"
	$(CCFLAGS) $(HEADERS) -c $< -o $@

clean:
	@echo "[$(RED)PIPEX$(NC)] Cleaning object files..."
			$(MAKE) -C $(LIBFT_D) clean
			@$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	@echo "[$(RED)PIPEX$(NC)] Cleaning executable file..."
			$(MAKE) -C $(LIBFT_D) fclean
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
