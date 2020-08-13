# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wacame <wacame@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 20:21:19 by wacame            #+#    #+#              #
#    Updated: 2020/08/10 20:44:34 by wacame           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = flags.c \
			ft_addsymb.c \
			ft_ls.c \
			ft_strncut.c \
			ft_strencut.c \
			init.c \
			print.c \
			print_2.c \
			print_total.c \
			push_back.c \
			recursion.c \
			restruct.c \
			sort.c \
			struct_filenames.c \
			whats_specific.c \
			
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re