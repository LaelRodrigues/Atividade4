RM = rm -rf 

CC=g++ 

LIB_DIR=lib
INC_DIR=include
SRC_DIR=src
OBJ_DIR=build
BIN_DIR=bin
DOC_DIR=doc
TEST_DIR=test
 
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all init clean debug doxy doc

all: init nascimentos

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

nascimentos: $(OBJ_DIR)/estatisticas.o $(OBJ_DIR)/arquivos.o $(OBJ_DIR)/taxa.o $(OBJ_DIR)/main.o  
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/nascimentos $^
	@echo "+++ [Executavel nascimentos criado em $(BIN_DIR)] +++"
	@echo "============="


$(OBJ_DIR)/estatisticas.o: $(SRC_DIR)/estatisticas.cpp $(INC_DIR)/estatisticas.h $(INC_DIR)/stats.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/arquivos.o: $(SRC_DIR)/arquivos.cpp $(INC_DIR)/arquivos.h $(INC_DIR)/stats.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/taxa.o: $(SRC_DIR)/taxa.cpp $(INC_DIR)/taxa.h $(INC_DIR)/stats.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
