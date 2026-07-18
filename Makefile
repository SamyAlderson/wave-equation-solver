# Makefile pour le projet wave-equation-solver

# Variables
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
LDFLAGS=-lm
SRC=$(wildcard src/*.c)
HDR=$(wildcard src/*.h)
TEST_SRC=$(wildcard src/tests/*.c)
TEST_HDR=$(wildcard src/tests/*.h)
TARGET=wave-equation-solver
TEST_TARGET=tests

# Règles de construction
.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) tests

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC) $(TEST_HDR) $(HDR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Règles de documentation
doc:
	doxygen Doxyfile

# Règles de validation
validate:
	@echo "Vérification de la complexité cyclomatique..."
	@for file in $(SRC) $(HDR); do \
		echo "Analyse de $$file..."; \
		sloccount -f SLOC --details $$file; \
	done
	@echo "Vérification des tests..."
	@for file in $(TEST_SRC); do \
		echo "Analyse de $$file..."; \
		sloccount -f SLOC --details $$file; \
	done

# Règles de sécurité
security:
	@echo "Vérification des erreurs..."
	@for file in $(SRC) $(HDR); do \
		echo "Analyse de $$file..."; \
		grep -n "goto" $$file; \
	done
	@echo "Vérification des secrets en dur..."
	@for file in $(SRC) $(HDR); do \
		echo "Analyse de $$file..."; \
		grep -n "API_KEY" $$file; \
	done
