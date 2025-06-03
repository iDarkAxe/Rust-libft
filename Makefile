.PHONY: all clean header build-lib
# RUST PARAMS
CRATE_NAME = ft
TMP_HEADER = temp.h
HEADER = libft.h
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
header: $(TMP_HEADER)
	cbindgen --config cbindgen.toml --crate $(CRATE_NAME) --output $(TMP_HEADER) $(LANGUAGE)
	python3 process.py
	@echo "$(HEADER) generated"
	rm -f $(TMP_HEADER)

# Temporary raw header
$(TMP_HEADER):
	cbindgen --config cbindgen.toml --crate $(CRATE_NAME) --output $@ $(LANGUAGE)

build-lib:
	cargo build --release

clean:
	cargo clean
	rm -f $(HEADER) $(NAME)
