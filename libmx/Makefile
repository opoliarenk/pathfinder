NAME = libmx.a

DIROBJ = obj

SRC = src/mx_printchar.c \
  src/mx_strlen.c \
  src/mx_printstr.c \
  src/mx_printint.c \
  src/mx_strnew.c \
  src/mx_del_strarr.c \
  src/mx_strdel.c \
  src/mx_strdup.c \
  src/mx_strcpy.c \
  src/mx_strcmp.c \
  src/mx_count_substr.c \
  src/mx_count_words.c \
  src/mx_strsplit.c \
  src/mx_file_to_str.c \
  src/mx_count_arr.c \
  src/mx_is_digit.c \
  src/mx_is_digit_str.c \
  src/mx_atoi.c \
  src/mx_atoi_new.c \
  src/mx_is_digit_n.c \
  src/mx_is_alfa.c \
  src/mx_strncpy.c \
  src/mx_while_delim.c \
  src/mx_isfile.c \

OUT = mx_printchar.o \
  mx_strlen.o \
  mx_printstr.o \
  mx_printint.o \
  mx_strnew.o \
  mx_del_strarr.o \
  mx_strdel.o \
  mx_strdup.o \
  mx_strcpy.o \
  mx_strcmp.o \
  mx_count_substr.o \
  mx_count_words.o \
  mx_strsplit.o \
  mx_file_to_str.o \
  mx_count_arr.o \
  mx_is_digit.o \
  mx_is_digit_str.o \
  mx_atoi.o \
  mx_atoi_new.o \
  mx_is_digit_n.o \
  mx_is_alfa.o \
  mx_strncpy.o \
  mx_while_delim.o \
  mx_isfile.o \

CLANG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = ./inc/libmx.h

all: install clean

install: 
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@ar -rc $(NAME) $(OUT)
	@mv $(OUT) $(DIROBJ)

uninstall:
	@rm -rf $(DIROBJ)

clean:
	@rm -rf $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(OUT)

reinstall: clean all
