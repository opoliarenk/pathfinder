NAME = pathfinder

DIROBJ = obj

SRC = src/main.c \
	src/mx_err_num.c \
	src/mx_line_value.c \
	src/mx_matrix.c \
	src/mx_num_of_isl.c \
	src/mx_print_erinfile.c \
	src/mx_error_input.c \
	src/mx_find_route.c \
	src/mx_square_mas.c \
	src/mx_printerr.c \
	src/mx_fill_list.c \
	src/mx_push_2_0.c \
	src/mx_all_path.c \
	src/mx_route_c.c \
	src/mx_print_all.c \
	src/mx_sort_my_list.c \
	src/mx_copy_char.c \
	src/mx_copy_int.c \

OUT = main.o \
	mx_err_num.o \
	mx_line_value.o \
	mx_matrix.o \
	mx_num_of_isl.o \
	mx_print_erinfile.o \
	mx_error_input.o \
	mx_find_route.o \
	mx_square_mas.o \
	mx_printerr.o \
	mx_fill_list.o \
	mx_push_2_0.o \
	mx_all_path.o \
	mx_route_c.o \
	mx_print_all.o \
	mx_sort_my_list.o \
	mx_copy_char.o \
	mx_copy_int.o \

CLANG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = inc/pathfinder.h \

LIBMX = libmx

LIBMX.A =./libmx/libmx.a

all: install uninstall

install:
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@make install -C $(LIBMX)
	@clang $(CLANG) $(SRC) $(LIBMX.A) -o $(NAME) -I $(INC)

uninstall:
	@rm -rf $(DIROBJ)
	@make uninstall -C $(LIBMX)

clean:
	@make clean -C $(LIBMX)
	@rm -rf $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(OUT)

reinstall: clean all
	@make reinstall -C $(LIBMX)
