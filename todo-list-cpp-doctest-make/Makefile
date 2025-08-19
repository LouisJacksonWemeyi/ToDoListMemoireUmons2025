# ===== Toolchain (MSYS2 / MinGW-w64) =====
SHELL    := /usr/bin/bash
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
LDFLAGS  := -fuse-ld=lld

# ===== Dirs =====
INCDIR   := include
SRCDIR   := src
TESTDIR  := tests
TPDIR    := third_party/doctest
TPHDR    := $(TPDIR)/doctest.h

BUILDDIR := build
BINDIR   := bin

# ===== Binaries =====
APP      := $(BINDIR)/todo.exe
TESTBIN  := $(BINDIR)/tests.exe

# ===== Sources / Objects =====
APP_SRCS := $(SRCDIR)/main.cpp $(SRCDIR)/Task.cpp $(SRCDIR)/ToDoList.cpp
APP_OBJS := $(APP_SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

TEST_SRC := $(TESTDIR)/test_all.cpp
TEST_OBJ := $(BUILDDIR)/test_all.o
CORE_OBJS:= $(BUILDDIR)/Task.o $(BUILDDIR)/ToDoList.o

# ===== Phony =====
.PHONY: all app test run clean

all: $(APP) $(TESTBIN)

app: $(APP)
test: $(TESTBIN)
	PATH="/c/msys64/ucrt64/bin:$$PATH" ./$(TESTBIN) --success=1

run: $(APP)
	PATH="/c/msys64/ucrt64/bin:$$PATH" ./$(APP)

# ===== Link (pré-unlink pour éviter verrouillage) =====
$(APP): $(APP_OBJS) | $(BINDIR)
	@if [ -f "$@" ]; then rm -f "$@" || { echo ">>> $@ verrouillé (ferme l’appli / antivirus / OneDrive)"; exit 1; }; fi
	$(CXX) -v $(CXXFLAGS) -o $@ $(APP_OBJS) $(LDFLAGS)

$(TESTBIN): $(TEST_OBJ) $(CORE_OBJS) $(TPHDR) | $(BINDIR)
	@if [ -f "$@" ]; then rm -f "$@" || { echo ">>> $@ verrouillé (ferme l’appli / antivirus / OneDrive)"; exit 1; }; fi
	$(CXX) $(CXXFLAGS) -I$(TPDIR) -o $@ $(TEST_OBJ) $(CORE_OBJS) $(LDFLAGS)


# ===== Compile (sources app) =====
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# ===== Compile (tests) =====
$(BUILDDIR)/test_all.o: $(TEST_SRC) $(INCDIR)/Task.h $(INCDIR)/ToDoList.h $(TPHDR) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -I$(TESTDIR) -I$(TPDIR) -c $< -o $@

# ===== Third-party: doctest (header-only) =====
$(TPHDR):
	@echo ">> Téléchargement de doctest.h"
	@mkdir -p $(TPDIR)
	@if command -v curl >/dev/null 2>&1; then \
	  curl -L -o $(TPHDR) https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h ; \
	elif command -v wget >/dev/null 2>&1; then \
	  wget -O $(TPHDR) https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h ; \
	else \
	  echo "ERREUR: curl ou wget requis pour récupérer doctest.h"; \
	  exit 1; \
	fi
	@echo ">> doctest.h -> $(TPHDR)"

# ===== Dirs =====
$(BINDIR) $(BUILDDIR):
	mkdir -p $@

# ===== Clean =====
clean:
	rm -rf $(BUILDDIR) $(BINDIR) third_party