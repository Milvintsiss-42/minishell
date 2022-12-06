# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 21:12:38 by ple-stra          #+#    #+#              #
#    Updated: 2022/10/06 18:45:32 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS_DIR	= srcs
GNL_DIR		= get_next_line
GNL_SRCS	= get_next_line.c get_next_line_utils.c
PTF_DIR		= ft_printf
PTF_SRCS	= ft_printf.c\
 parsing.c parse_arguments.c\
 parse_conversion_c.c parse_conversion_di.c parse_conversion_p.c\
 parse_conversion_s.c parse_conversion_uxX.c parse_conversion_utils.c\
 invalid_conversion.c is_conversion.c\
 lists.c buildstr.c free.c
SRCS		=\
 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c\
\
 ft_flags.c\
\
 ft_max_min.c\
\
 ft_strlen.c ft_strlen_c.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
 ft_free.c ft_strdup.c ft_realloc.c\
\
 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_itoa_base.c\
 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
 ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c ft_putstr.c\
\
 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
 ft_lstadd_next.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
 ft_lstsort.c\
\
 $(addprefix $(GNL_DIR)/, $(GNL_SRCS))\
\
 $(addprefix $(PTF_DIR)/, $(PTF_SRCS))

BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/objs
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC_DIR		= includes

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)

RM			= rm -rf

ifeq (disable_gnl_eof_mid_line, $(filter disable_gnl_eof_mid_line,$(MAKECMDGOALS)))
	CFLAGS	+= -D GNL_BREAK_ON_EOF_MID_LINE=0
endif

all			: $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(GNL_DIR)
	@mkdir -p $(OBJ_DIR)/$(PTF_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJ)
			ar -rc $(BUILD_DIR)/$(NAME) $(OBJ)
			ranlib $(BUILD_DIR)/$(NAME)

clean		:
			$(RM) $(OBJ_DIR)

fclean		:
			$(RM) $(BUILD_DIR)

re			: fclean all

disable_gnl_eof_mid_line:
			@echo "Watching for EOF mid line is disabled"

.PHONY: all clean fclean re\
 disable_gnl_eof_mid_line
