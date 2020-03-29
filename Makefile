NAME = pong

SRC = shader.cpp\
	main.cpp\
	entity.cpp\
	camera.cpp\
	renderer.cpp

SRCDIR = src

INCLUDE = include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

CC = g++

CFLAGS = #-Wall -Wextra -Werror
LDFLAGS = -lglfw3 -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) $(LDFLAGS)

clean:
	@echo "removing objects"

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
