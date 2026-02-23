NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

################################################################################
#                                PROGRESS BAR                                  #
################################################################################

CNT = /tmp/.libft_cnt
RESET := $(shell echo 0 > $(CNT))
C = \033[1;35m
Y = \033[1;33m
B = \033[1m
X = \033[0m

define progress
n=$$(($$(cat $(CNT)) + 1)); echo $$n > $(CNT); \
t=$(words $(SRC)); pct=$$((n * 100 / t)); f=$$((n * 20 / t)); \
bar=""; i=0; \
while [ $$i -lt $$f ]; do bar="$${bar}█"; i=$$((i+1)); done; \
while [ $$i -lt 20 ]; do bar="$${bar}░"; i=$$((i+1)); done; \
printf "\r\033[K $(C)📚 [libft] $(Y)$$bar $(B)$$pct%%$(X)"
endef

################################################################################
#                                   RULES                                      #
################################################################################

all: $(NAME)
	@if [ $$(cat $(CNT)) -gt 0 ]; then printf "\n"; fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call progress)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
