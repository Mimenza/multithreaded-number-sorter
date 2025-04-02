# Define colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

# Commands
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

# Executable name
NAME		=	mns

# Files
SRC_FILES	=	00_main 01_verification 02_handleFile
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Directories
SRC_DIR = srcs/
OBJ_DIR = objs/

# RULES #
all: $(NAME)

# Compile
$(NAME):$(OBJ)
		@$(CC) $(OBJ) -o $(NAME)
		@echo "$(GREEN)EXECUTABLE HAS BEEN COMPILED!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled!$(NC)"

# Remove temporary files
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)OBJS AND DIRECTORY CLEANED!$(NC)"

# Remove temporary files and executable
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"

re: fclean all