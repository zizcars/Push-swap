
CC = cc 
CFLAGS= -Wall -Wextra -Werror -fsanitize=address
CFILES= new_atoi.c tooles.c main.c rules.c sorting.c
OFILES=$(CFILES:.c=.o)
NAME=push_swap
LIBNAME=libft/libft.a ft_printf/libftprintf.a

all: $(NAME) 

$(NAME): $(OFILES) libs
	$(CC) $(CFLAGS) $(OFILES) $(LIBNAME) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< 

##################### DELETE ########################
# CTEST= test.c new_atoi.c tooles.c rules.c
# OTEST=$(CTEST:.c=.o)

# test: $(OTEST) libs
# 	$(CC) $(CFLAGS) $(OTEST) $(LIBNAME) -o test
#################################################
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
