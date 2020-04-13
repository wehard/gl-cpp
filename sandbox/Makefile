NAME = pong

WGL = ../engine

SRC = main.cpp\
	player.cpp\
	ball.cpp\
	opponent.cpp\
	wall.cpp

SRCDIR = src

INCLUDE = include
WGLINCLUDE = $(WGL)/include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.cpp=.o)

CC = clang

CFLAGS = -std=c++17 -lstdc++ #-Wall -Wextra -Werror
LDFLAGS = -lwgl -lglfw -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread

vpath %.cpp $(SRCDIR)
vpath %.h $(INCLUDE) $(WGLINCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "compiling %s\n" "$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCLUDE) -I $(WGLINCLUDE) -L$(WGL) -lwgl $(LDFLAGS)

%.o: %.cpp
	@printf "compiling %s\n" "$<"
	@$(CC) -I $(INCLUDE) -I $(WGLINCLUDE) -c $< -o $@


debug:
	$(CC) -g $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) -I $(WGLINCLUDE) $(LDFLAGS)

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
