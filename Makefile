NAME = philo

SRCDIR = src
OBJDIR = obj
INCDIR = include
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

SRC = main.c parse.c utils.c data_init.c safe_functions.c mtx_set_get.c simulation.c sync_utils.c monitoring.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

################################################################################
#                                PROGRESS BAR                                  #
################################################################################

CNT = /tmp/.philo_cnt
RESET := $(shell echo 0 > $(CNT))
C = \033[1;36m
Y = \033[1;33m
R = \033[1;31m
B = \033[1m
X = \033[0m

define progress
n=$$(($$(cat $(CNT)) + 1)); echo $$n > $(CNT); \
t=$(1); pct=$$((n * 100 / t)); f=$$((n * 20 / t)); \
bar=""; i=0; \
while [ $$i -lt $$f ]; do bar="$${bar}█"; i=$$((i+1)); done; \
while [ $$i -lt 20 ]; do bar="$${bar}░"; i=$$((i+1)); done; \
printf "\r\033[K $(C)🔧 [$(NAME)] $(Y)$$bar $(B)$$pct%%$(X)"
endef

################################################################################
#                                   RULES                                      #
################################################################################

all: $(NAME)
	@if [ $$(cat $(CNT)) -gt 0 ]; then printf "\n"; fi
	@printf " $(C)✅ [$(NAME)] $(B)Build complete$(X)\n"



$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR_B):
	@mkdir -p $(OBJDIR_B)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call progress,$(words $(SRC)))

clean:
	@printf "$(R)🗑️  [$(NAME)] Cleaned$(X)\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
