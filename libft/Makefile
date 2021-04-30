CC=		gcc

NAME=	libft.a

CFLAGS=	-Werror -Wextra -Wall

FILES=	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strnlen.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strlcpy.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_utoa.c\
		ft_utoa_base.c\
		ft_lutoa.c\
		ft_lutoa_base.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c

BONUS=	ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstmap_bonus.c

OBJ=	$(FILES:.c=.o)

B_OBJ=	$(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

bonus: $(OBJ) $(B_OBJ)
	ar rc $(NAME) $(OBJ) $(B_OBJ)
	ranlib $(NAME)
