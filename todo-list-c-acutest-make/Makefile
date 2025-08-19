# Compilateur C (MSYS2/MinGW-w64)
CC       := gcc

# Flags
CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -O2 -Iinclude
TFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -O2 -Iinclude -Ithird_party/acutest

# Dossiers
SRC_DIR   := src
INC_DIR   := include
TEST_DIR  := tests
BUILD_DIR := build
TP_DIR    := third_party/acutest

# Fichiers
APP_EXE   := $(BUILD_DIR)/todo_app.exe
TEST_EXE  := $(BUILD_DIR)/tests.exe
ACUTEST_H := $(TP_DIR)/acutest.h

# Objets
APP_OBJS  := $(BUILD_DIR)/todo.o $(BUILD_DIR)/main.o
TEST_OBJS := $(BUILD_DIR)/todo.o $(BUILD_DIR)/test_all.o

.PHONY: all deps app tests run test clean

all: deps app tests

deps: $(ACUTEST_H)

$(ACUTEST_H):
	@echo ">> Téléchargement de acutest.h"
	@curl -L --create-dirs -o $(ACUTEST_H) https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# --- Application ---
$(BUILD_DIR)/todo.o: $(SRC_DIR)/todo.c $(INC_DIR)/todo.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/todo.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

app: $(APP_EXE)

$(APP_EXE): $(APP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: app
	./$(APP_EXE)

# --- Tests (C pur avec Acutest) ---
$(BUILD_DIR)/test_all.o: $(TEST_DIR)/test_all.c $(INC_DIR)/todo.h $(ACUTEST_H) | $(BUILD_DIR)
	$(CC) $(TFLAGS) -c $< -o $@

tests: $(TEST_EXE)

$(TEST_EXE): $(TEST_OBJS)
	$(CC) $(TFLAGS) -o $@ $^

test: tests
	./$(TEST_EXE)

clean:
	@echo ">> Nettoyage"
	@rm -rf $(BUILD_DIR)
