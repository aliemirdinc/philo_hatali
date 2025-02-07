NAME		= philo
BONUS_NAME	=
CFLAGS		= -Wall -Wextra -Werror
VALGRIND	= @valgrind --leak-check=full --show-leak-kinds=all

SRCS		= input_process/control_input.c input_process/init_inputs.c \
				cleanup.c init_philo.c init_simulation.c \
				philo_routine.c philo.c start_simulation.c \
				utils_for_time.c utils.c

OBJS		= input_process/control_input.o input_process/init_inputs.o \
				cleanup.o init_philo.o init_simulation.o \
				philo_routine.o philo.o start_simulation.o \
				utils_for_time.o utils.o

BONUS_SRCS	=
BONUS_OBJS	=

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET_COLOUR= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	cc $(CFLAGS) $(BONUS_SRCS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus