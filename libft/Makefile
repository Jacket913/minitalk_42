## PROGRAM NAME ##
NAME = libft.a

## UTILS ##
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
SILENT_FLAG 	:= --no-print-directory --silent

## COLORS ##
DEFAULT		:= \033[0m
BLACK		:= \033[0;30m
RED			:= \033[0;31m
DRED		:= \033[0;31;5m
GREEN		:= \033[0;32m
UGREEN		:= \033[4;32m
YELLOW		:= \033[;33m
BLUE		:= \033[0;34m
PURPLE		:= \033[0;35m
CYAN		:= \033[0;36m
BWHITE		:= \033[1;37m
NEW			:= \r\033[K

## DIRECTORIES ##
INCLD_DIR = include
SRC_DIR = src
OBJS_DIR = objs

## SOURCES & FILES ##
SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_split.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_split.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_printf_utils.c \
		ft_printf.c \
		get_next_line.c \
		oget_next_line.c \
		get_next_line_utils.c \
		ft_fsplit.c
INCLUDES	:=	$(INCLD_DIR)
INCLD_FLAG 	:= 	$(addprefix -I , $(INCLUDES))
OBJS 		:= 	$(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
DEPS		:= 	$(patsubst %.c,$(OBJS_DIR)/%.d,$(SRC))

## PROJECT ##
.PHONY : all clean fclean re norm
all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(NEW)$(PURPLE)[$(NAME)] $(UGREEN)Building:$(DEFAULT)$(BWHITE) $@$(DEFAULT)"
	@ar rcs $@ $(OBJS)
	@printf "\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(NEW)$(PURPLE)[$(NAME)] $(UGREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

clean: ; @printf "$(PURPLE)[$(NAME)] $(RED)Removing $(DEFAULT)$(OBJS_DIR) files\n"
	@$(RM) $(OBJS_DIR)

fclean: clean ; @printf "$(PURPLE)[$(NAME)] $(RED)Removing $(DEFAULT)$(NAME)\n"
	@$(RM) $(NAME)

re: fclean all

## NORM ##
norm:
	@norminette $(SRC_DIR) $(INCLD_DIR) | awk '/Error/ (print; found=1) END \
	(if (!found) (print "$(PURPLE)[$(NAME)] $(DEFAULT)Norm: $(BWHITE)OK$(DEFAULT)"; exit 0 ); exit 1 )'

