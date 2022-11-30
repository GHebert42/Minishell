
NAME 	=	minishell

#	LIBFT
FSRC	=	
F_DIR	=	libft/
F_PTH	=	$(addprefix $(F_DIR), $(FSRC))
O_DIR 	=	libft/objs/
LIBFT	=	libft/libft.a

S_DIR	=	srcs
S_OBJ	=	objs
SUBDIRS		= builtins mapping operators parsing utils

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(S_DIR)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(S_OBJ)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(S_DIR), $(S_OBJ), $(SRCS:.c=.o))

#	READLINE HEADER
RDPATH 		= readline/libreadline.a readline/libhistory.a
#	HEADER
H_DIR		= -I includes

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror 
RM 			= rm -rf

#	BUILD FOLDER
$(S_OBJ)/%.o :	$(S_DIR)/%.c
			@mkdir -p $(S_OBJ) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(H_DIR) -c $< -o $@

$(NAME): 	$(OBJS) 
		-@$(MAKE) -C $(F_DIR) -s
		-@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(RDPATH) -lcurses -lreadline -o $(NAME) 

all		:	$(NAME) 

clean	: 
				$(RM) -r $(S_OBJ)
				
fclean	:	clean
				$(RM) $(OBJ_F) $(LIBFT)
				$(RM) $(O_DIR)
				$(RM) $(NAME) 


re		:	fclean all

ref		:	fclean sub


.PHONY	:	clean fclean re sub
