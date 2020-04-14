NAME = libwengine.a

SRC = shader.cpp\
	entity.cpp\
	camera.cpp\
	renderer.cpp\
	wgl.cpp\
	wgl_input.cpp\
	obj_loader.cpp\
	mesh.cpp\
	collider.cpp\
	framebuffer.cpp\
	textured_quad.cpp

SRCDIR = src

INCLUDE = include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.cpp=.o)

CC = clang

CFLAGS = -std=c++17 -lstdc++ #-Wall -Wextra -Werror
LDFLAGS = -lglfw -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread

vpath %.cpp $(SRCDIR)
vpath %.h $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "compiling %s\n" "$(NAME)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "done\n" "$(NAME)"


%.o: %.cpp
	@printf "compiling %s\n" "$<"
	@$(CC) -g -I $(INCLUDE) -c $< -o $@


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
