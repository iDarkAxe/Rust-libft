# RUST PARAMS
CRATE_NAME = ft
HEADER = my_header.h
LANGUAGE = --lang c #if C++, desactivate it 

# Platform	Pattern for lib created
# Windows	*.dll
# OS X	lib*.dylib
# Linux	lib*.so


# C PARAMS
NAME = executable
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	$(MAKE) build-lib
	$(MAKE) header
	$(CC) --std=c11 $(CFLAGS) -I ./ -o $(NAME) src/code.c  target/release/libft.so

# Build the header for the c files
header:
	cbindgen --crate $(CRATE_NAME) --output $(HEADER) $(LANGUAGE)

build-lib:
	cargo build --release
