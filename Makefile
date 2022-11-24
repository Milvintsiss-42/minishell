# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 15:36:23 by ple-stra          #+#    #+#              #
#    Updated: 2022/11/24 02:24:45 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS_DIR	= srcs
SRCS		= main.c \
	$(addprefix cli/, \
		input.c \
		logo.c \
	) \
	$(addprefix common/, \
		commands_utils.c \
		commands_free.c \
		clear_prg_data.c \
		errors.c \
		path_utils.c \
		env_info_utils.c \
		env_modify_utils.c \
		env_cpy_and_free.c \
		get_pwd.c \
	) \
	$(addprefix execution/, \
		execution.c \
		launch_commands.c \
		processes.c \
		pipe_utils.c \
		here_doc.c \
		prompt_here_docs.c \
		redirections.c \
		$(addprefix builtins/, \
			builtins.c \
			cd_builtin.c \
			pwd_builtin.c \
			env_builtin.c \
			echo_builtin.c \
			exit_builtin.c \
			unset_builtin.c \
			export_builtin.c \
			export-unset_utils.c \
		) \
		$(addprefix testing/, \
			execution_testing.c \
			execution_testing_first_pipeline.c \
			execution_testing_second_pipeline.c \
			execution_testing_third_pipeline.c \
			execution_testing_fourth_pipeline.c \
			execution_testing_fifth_pipeline.c \
			execution_testing_sixth_pipeline.c \
			execution_testing_export.c \
			execution_testing_unset.c \
			execution_testing_env.c \
			execution_testing_exit.c \
		) \
	) \
	$(addprefix parsing/, \
		$(addprefix commands/, \
			args.c \
			cmd_generator.c \
			cmd_translator.c \
			command_nu.c \
			file_handling.c \
			is_command_separator.c \
		) \
		$(addprefix lexer/, \
			lexer.c \
			quotes_handling.c \
		) \
		$(addprefix tokenizer/, \
			free_all.c \
			lst_tokens.c \
			skip_quotes.c \
			tokenizer.c \
		) \
		$(addprefix validation/, \
			validation.c \
		) \
		free_parsing.c \
		is_separator.c \
		parsing.c \
	) \
	$(addprefix signals/, \
		signals.c \
	)
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/objs
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC			= -I./includes -I./$(LIBFT_DIR)/includes -I./\
 -I$(RL_DIR)/include

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/build/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR)/build -lft

# Directory used for readline with a basic installation via Brew
RL_DIR		= /usr/local/opt/readline

CC			= cc
CFLAGS		= -Wall -Wextra
LFLAGS		= $(LIBFT_FLAGS) \
 -L$(RL_DIR)/lib -lreadline
ifneq (nWerror, $(filter nWerror,$(MAKECMDGOALS)))
	CFLAGS	+= -Werror
endif
ifeq (sanitize, $(filter sanitize,$(MAKECMDGOALS)))
	CFLAGS 	+= -fsanitize=address
endif
ifeq (g3, $(filter g3,$(MAKECMDGOALS)))
	CFLAGS 	+= -g3
endif
ifeq (debug, $(filter debug,$(MAKECMDGOALS)))
	CFLAGS	+= -D KDEBUG=1
endif
ifeq (debug_exec, $(filter debug_exec,$(MAKECMDGOALS)))
	CFLAGS	+= -D KDEBUG_EXEC=1
endif

GIT_SUBM	= $(shell \
 sed -nE 's/path = +(.+)/\1\/.git/ p' .gitmodules | paste -s -)
RM			= rm -rf

all			: $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(GIT_SUBM): %/.git: .gitmodules
ifneq (noconnection, $(filter noconnection,$(MAKECMDGOALS)))
	@git submodule init
	@git submodule update $*
endif

$(LIBFT)	:
ifeq (,$(wildcard $(LIBFT)))
			@echo "building libft..."
			@$(MAKE) -sC $(LIBFT_DIR) all disable_gnl_eof_mid_line
endif

rmlibft		:
			@echo "deleting libft build..."
			@$(MAKE) -sC $(LIBFT_DIR) fclean

$(NAME)		: $(GIT_SUBM) $(LIBFT) $(OBJ)
			$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LFLAGS)
			
clean		:
			$(RM) $(OBJ_DIR)
			$(RM) $(OBJBNS_DIR)

fclean		:
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)

fcleanall	: rmlibft
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)

re			: fclean all

nWerror		:
			@echo "WARN: Compiling without Werror flag!"
sanitize	:
			@echo "WARN: Compiling with fsanitize flag!"
g3			:
			@echo "WARN: Compiling with g3 flag!"
debug		:
			@echo "WARN: debug is enabled"
debug_exec	:
			@echo "WARN: debug_exec is enabled"
noconnection:
			@echo "WARN: Fetching submodules disabled!"

.PHONY: \
 all clean fclean fcleanall re rmlibft\
 nWerror sanitize debug g3 debug_exec noconnection
