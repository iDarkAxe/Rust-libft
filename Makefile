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

all:
	$(MAKE) build-lib
	$(MAKE) header
	gcc --std=c11 -I ./ -o $(NAME) src/code.c  target/release/libft.so

# Build the header for the c files
header:
	cbindgen --crate $(CRATE_NAME) --output $(HEADER) $(LANGUAGE)

build-lib:
	cargo build --release
