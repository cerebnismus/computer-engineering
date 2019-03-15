#  Main targets can be executed directly, and they are:
#
#     build                    build a specific configuration
#     clean                    remove built files from a configuration
#     clobber                  remove all built files
#     all                      build all configurations
#     help                     print help mesage
#
# Environments
CC=gcc
CFLAGS= -Wall -Wextra -O2 -g
LIBPATH= -Llib
USERLIBS= -lfdr
BIN=bin
INCL=include
LIB=lib
SRC=src
TARGET=main
CP=cp
#
all: mkbin compile run
#	
compile: main.o helper.o
	$(CC) $(CFLAGS) $(LIBPATH) $(LIB)/main.o $(LIB)/yardimci.o $(USERLIBS) -o $(BIN)/$(TARGET) 
#
run: 
	clear
	./$(BIN)/$(TARGET)
#	
main.o: src/main.c include/jrb.h include/jval.h include/helper.h
	$(CC) -I $(INCL) -c $(SRC)/main.c -o $(LIB)/main.o
helper.o: src/helper.c
	$(CC) -I $(INCL) -c $(SRC)/helper.c -o $(LIB)/helper.o
#
.PHONY: mkbin
mkbin:
	mkdir -p bin
#
.PHONY: clean
clean:
	rm -f $(BIN)/*
	rm -f $(LIB)/*.o
#
#
# help: .help-post
#
# .help-pre:
# Add your pre 'help' code here...
#
# .help-post: .help-impl
# Add your post 'help' code here...
#
# include project implementation makefile
# include nbproject/Makefile-impl.mk
#
# include project make variables
# include nbproject/Makefile-variables.mk
#
#