NAME = pong

SRC = shader.cpp\
	main.cpp\
	entity.cpp\
	camera.cpp\
	renderer.cpp\
	wgl.cpp\
	wgl_input.cpp\
	player.cpp\
	ball.cpp\
	opponent.cpp\
	obj_loader.cpp\
	mesh.cpp\
	wall.cpp

SRCDIR = src

INCLUDE = include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

CC = clang

CFLAGS = -std=c++17 -lstdc++ #-Wall -Wextra -Werror
LDFLAGS = -lglfw3 -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) $(LDFLAGS)

debug:
	$(CC) -g $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) $(LDFLAGS)

check: fclean
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) $(LDFLAGS) CXX=~/Dev/temp/build/bin/include-what-you-use

clean:
	@echo "removing objects"

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
