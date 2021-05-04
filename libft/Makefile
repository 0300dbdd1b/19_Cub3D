
BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;33m
WHITE			=	\033[1;37m
NC				=	\033[0m

GNLDIR		=	./srcs/get_next_line/
SRCDIR		=	./srcs/
INCDIR		=	./includes/
SRCNAME		= 	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strnlen.c		\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_isspace.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_strtoull.c		\
				ft_atoi_base.c 		\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c 		\
				ft_strjoin.c 		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_check_base.c		\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putnbr.c			\
				ft_putnbr_base.c	\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c 	\
				ft_putnbr_fd.c		\
				ft_putnbr_base_fd.c \
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_strcmp.c			\

GNL_SRCS		=	ft_get_next_line.c			\
					ft_get_next_line_utils.c	\

GNL			=	${addprefix ${GNLDIR}, ${GNL_SRCS}}
SRCS		= 	${addprefix ${SRCDIR}, ${SRCNAME}}

GNL_OBJS	=	${GNL:.c=.o}
OBJS		= 	${SRCS:.c=.o}

CC			= 	@gcc
CFLAGS 		=	-Wall -Werror -Wextra

.c.o        :
				@echo "${ORANGE}Compilation of $<...${NC}"
				${CC} ${CFLAGS} -I ./includes/ -c $< -o ${<:.c=.o}



NAME		= 	libft.a
$(NAME) 	: 	${OBJS} ${GNL_OBJS}
				@ar rc ${NAME} ${OBJS} ${GNL_OBJS}
				@echo "${LIGHT_GREEN}Libft.a Created.${NC}"


all:		${NAME}					## Cree la base de la Bibliotheque Statique "libft.a

clean:								## Supprime tout les .o inclus dans la bibliotheque "libft.a
			@rm -f ${OBJS} ${GNL_OBJS}
			@echo "${LIGHT_GREEN}Clean.${NC}"

fclean:								## Supprime la Bibliotheque Statique et ses fichiers objet
			@rm -f ${OBJS} ${GNL_OBJS}
			@rm -f ${NAME}
			@echo "${LIGHT_GREEN}All Clean.${NC}"

re:			fclean all   			## Supprime et recompile la Bibliotheque Smaketatique avec ses fichiers objets

x:			all clean

help:								## Liste toutes les commandes
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'


.PHONY	= 	all clean fclean re x
