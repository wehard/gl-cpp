NAME = pong

WENGINE = ../engine

SRC = main.cpp\
	player.cpp\
	ball.cpp\
	opponent.cpp\
	wall.cpp

SRCDIR = src

INCLUDE = include
WENGINCLUDE = $(WENGINE)/include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.cpp=.o)

CC = clang

CFLAGS = -std=c++17 -lstdc++ #-Wall -Wextra -Werror
LDFLAGS = -lglfw -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread

vpath %.cpp $(SRCDIR)
vpath %.h $(INCLUDE) $(WENGINCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(WENGINE)
	@printf "compiling %s\n" "$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(WENGINE)/lib/libIrrKlang.so -I $(INCLUDE) -I $(WENGINCLUDE) -I $(WENGINE)/include/ik -L$(WENGINE) -lwengine -L$(WENGINE)/lib $(LDFLAGS)

%.o: %.cpp
	@printf "compiling %s\n" "$<"
	@$(CC) -I $(INCLUDE) -I $(WENGINCLUDE) -c $< -o $@

debug:
	$(CC) -g $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) -I $(WENGINCLUDE) -L$(WENGINE) -lwengine $(LDFLAGS)

check: fclean
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) $(LDFLAGS) CXX=~/Dev/temp/build/bin/include-what-you-use

clean:
	@echo "removing objects"
	@rm -rf $(OBJS)

fclean: clean
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
