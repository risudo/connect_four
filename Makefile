NAME = connent_four

SRCS =	main.cpp \
		Board.cpp \
		HUM_Player.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=gnu++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

sanitize: CXXFLAGS += -fsanitize=address -g3
sanitize: re

-include $(DEPS)

.PHONY: all clean fclean re
