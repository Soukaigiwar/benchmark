# Nome do Arquivo: makefile
# Autor: SoukaigWar (Sergio Mello)
# Data: 04/03/2024
# Descrição: Testa o tempo de execução do algorítmo no arquivo teste.c

SRC_NAME = benchmark

OUT_DIR = ./build

EXE_NAME = $(OUT_DIR)/$(SRC_NAME)

CFLAGS = -Wall -Wextra -O2

ifdef RUNS
override RUNS := $(RUNS)
else
override RUNS := 1
endif

all: $(EXE_NAME)
	du -b $(EXE_NAME)

$(EXE_NAME): $(SRC_NAME).c teste.c
	mkdir -p $(OUT_DIR)
	gcc $(CFLAGS) $^ -o $@

run: $(EXE_NAME)
	$(EXE_NAME) -r $(RUNS)

clean:
	rm -rf $(OUT_DIR)
