
CC = cc 
CFLAGS= -Wall -Wextra -Werror -fsanitize=address
CFILES= new_atoi.c tooles.c test.c rules.c sorting.c sort_tooles.c
OFILES=$(CFILES:.c=.o)
NAME=test
LIBNAME=libft/libft.a ft_printf/libftprintf.a

all: $(NAME) 

$(NAME): $(OFILES) libs
	$(CC) $(CFLAGS) $(OFILES) $(LIBNAME) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<

libs:
	cd libft && make && make bonus
	cd ft_printf && make

clean:
	rm -f $(OFILES)
	cd libft && make clean
	cd ft_printf && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
	cd ft_printf && make fclean 

re: fclean all
