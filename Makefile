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
	wall.cpp\
	collider.cpp

SRCDIR = src

INCLUDE = include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.cpp=.o)

CC = clang

CFLAGS = -std=c++17 -lstdc++ #-Wall -Wextra -Werror
LDFLAGS = -lglfw3 -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread

vpath %.cpp $(SRCDIR)
vpath %.h $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "compiling %s\n" "$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCLUDE) $(LDFLAGS)

%.o: %.cpp
	@printf "compiling %s\n" "$<"
	@$(CC) -I $(INCLUDE) -c $< -o $@


debug:
	$(CC) -g $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCLUDE) $(LDFLAGS)

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
