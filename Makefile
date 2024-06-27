## PROGRAM NAME ##
NAMEC		:= client
NAMES		:= server
NAMECB		:= client_bonus
NAMESB		:= server_bonus


## UTILS ##
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g3
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf

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
SRC_DIR 	:= src
INCLD_DIR 	:= include
OBJS_DIR 	:= objs
LIBFT_DIR 	:= libft

## SOURCES & FILES ##
INCLUDES	:= ${INCLD_DIR}/ \
	${LIBFT_DIR}/${INCLD_DIR}/ \
INCLUDES 	:= ${strip ${INCLUDES}}

INCLD_FLAG 	:= ${addprefix -I , ${INCLUDES}}
LIBFT		:= ${LIBFT_DIR}/libft.a

LIB 		:= ${LIBFT}
LIB 		:= ${strip ${LIB}}

SRCC_FILE := client.c
SRCS_FILE := server.c
# SRCCB_FILE := ${NAMECB}.c
# SRCSB_FILE := ${NAMESB}.c

SRCC 		:= ${strip ${SRCC_FILE}}
OBJSC 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRCC_FILE}}

SRCS 		:= ${strip ${SRCS_FILE}}
OBJSS 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_FILE}}

# SRCCB 		:= ${strip ${SRCCB_FILE}}
# OBJSCB 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRCCB_FILE}}

# SRCSB 		:= ${strip ${SRCSB_FILE}}
# OBJSSB 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRCSB_FILE}}

#DEPS		:= ${patsubst %.c,${OBJS_DIR}/%.d,${SRC}}

## PROJECT ##
.PHONY: all clean fclean re cleanlib fcleanlib relib norm
all: ${NAMEC} ${NAMES}

${NAMEC}: ${LIB} ${OBJSC}
	@printf "${NEW}${PURPLE}[${NAMEC}] ${UGREEN}Compiling:${DEFAULT}${BWHITE} $@${DEFAULT}."
	@${CC} ${CFLAGS} ${OBJSC} ${LIB} ${INCLD_FLAG} -o $@
	@printf "\n"

${NAMES}: ${LIB} ${OBJSS}
	@printf "${NEW}${PURPLE}[${NAMES}] ${UGREEN}Compiling:${DEFAULT}${BWHITE} $@${DEFAULT}."
	@${CC} ${CFLAGS} ${OBJSS} ${LIB} ${INCLD_FLAG} -o $@
	@printf "\n"

-include ${DEPS}
${OBJS_DIR}/%.o: ${SRC_DIR}/%.c
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Compiling:${DEFAULT}. $<"
	@mkdir -p ${OBJS_DIR}
	@${CC} ${DEP_FLAGS} ${CFLAGS} ${INCLD_FLAG} -c $< -o $@

clean:
	@printf "${PURPLE}[Minitalk] ${RED}Cleaning ${DEFAULT}${OBJS_DIR} files.\n"
	@${RM} ${OBJS_DIR}

fclean: clean
	@printf "${PURPLE}[Minitalk] ${RED}Cleaning ${DEFAULT}Minitalk.\n"
	@${RM} ${NAMEC} ${NAMES} ${NAMECB} ${NAMESB}

re: fclean all

## LIBFT RULES ##
${LIBFT}:
	@make -C ${LIBFT_DIR} ${MAKE_FLAG}

cleanlib:
	@make -C ${LIBFT_DIR} clean ${MAKE_FLAG}

fcleanlib:
	@make -C ${LIBFT_DIR} fclean ${MAKE_FLAG}
	@printf "${DRED}[${LIBFT_DIR}] Lib has been wiped clean.\n"

relib:
	@make -C ${LIBFT_DIR} re ${MAKE_FLAG}

## NORM ##
norm: ; @make -C $(LIBFT_DIR) norm $(MAKE_FLAG)
	@norminette $(SRC_DIR) $(INCLD_DIR) | awk '/Error/ {print; found=1} END \
	{if (!found) {print "$(PURPLE)[Minitalk] $(DEFAULT)Norm: $(BWHITE)OK$(DEFAULT)"; exit 0 }; exit 1 }'
