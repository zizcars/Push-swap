
CC = cc 
CFLAGS= -Wall -Wextra -Werror -fsanitize=address #remove the last flage
CFILES= main.c \
		new_atoi.c \
		tooles.c \
		rules.c \
		assistant.c \
		sort_tooles.c \
		more_tooles.c \
		sort.c

BCFILES=checker_bonus.c \
		new_atoi.c \
		tooles.c \
		rules.c \
		assistant.c \
		sort_tooles.c \
		more_tooles.c\
		get_next_line.c \
		get_next_line_utils.c \

BOFILES=$(BCFILES:.c=.o) 
OFILES=$(CFILES:.c=.o)
NAME=push_swap 
BNAME=checker
LIBNAME=libft/libft.a ft_printf/libftprintf.a

all: $(NAME) 

$(NAME): $(OFILES) libs
	@$(CC) $(CFLAGS) $(OFILES) $(LIBNAME) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<

libs:
	@cd libft && make && make bonus
	@cd ft_printf && make

bonus: $(BOFILES) libs #how about use just the checker without mandantory
	@$(CC) $(CFLAGS) $(BOFILES) $(LIBNAME) -o $(BNAME)


clean:
	@rm -f $(OFILES) $(BOFILES)
	@cd libft && make clean
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean 

re: fclean all
