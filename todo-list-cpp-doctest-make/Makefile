# ===== Toolchain (MSYS2 / MinGW-w64) =====
BASH := /usr/bin/bash
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
LDFLAGS  := -fuse-ld=lld

# ===== Profilage (activer avec PROFILE=1) =====
ifeq ($(PROFILE),1)
  # Rapport détaillé des passes du compilateur
  CXXFLAGS += -ftime-report

  # Trace de temps du linker (si supporté par LLD)
  LDFLAGS  += -Wl,--time-trace -Wl,--time-trace-file=$(BUILDDIR)/link-time-trace.json

  # Détection: si /usr/bin/time existe -> format custom; sinon fallback sur builtin "time -p"
  ifneq ($(shell command -v /usr/bin/time 2>/dev/null),)
    TIMECMD := /usr/bin/time -f "[time] %E real, %U user, %S sys"
  else
    TIMECMD := time -p
  endif
else
  TIMECMD :=
endif

# ===== Dirs =====
INCDIR   := include
SRCDIR   := src
TESTDIR  := tests
TPDIR    := third_party/doctest
TPHDR    := $(TPDIR)/doctest.h

BUILDDIR := build
BINDIR   := bin
LOGDIR   := $(BUILDDIR)/logs

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
.PHONY: all app test run clean profile

all: $(APP) $(TESTBIN)

app: $(APP)
test: $(TESTBIN)
	PATH="/c/msys64/ucrt64/bin:$$PATH" ./$(TESTBIN) --success=1

run: $(APP)
	PATH="/c/msys64/ucrt64/bin:$$PATH" ./$(APP)

# ===== Link (pré-unlink pour éviter verrouillage) =====
$(APP): $(APP_OBJS) | $(BINDIR)
	@if [ -f "$@" ]; then rm -f "$@" || { echo ">>> $@ verrouillé (ferme l’appli / antivirus / OneDrive)"; exit 1; }; fi
	$(BASH) -lc 'start=$$(date +%s); \
		$(CXX) -v $(CXXFLAGS) -o $@ $(APP_OBJS) $(LDFLAGS); st=$$?; \
		end=$$(date +%s); echo "[time] link $@ : $$((end-start)) s"; exit $$st'

$(TESTBIN): $(TEST_OBJ) $(CORE_OBJS) $(TPHDR) | $(BINDIR)
	@if [ -f "$@" ]; then rm -f "$@" || { echo ">>> $@ verrouillé (ferme l’appli / antivirus / OneDrive)"; exit 1; }; fi
	$(BASH) -lc 'start=$$(date +%s); \
		$(CXX) $(CXXFLAGS) -I$(TPDIR) -o $@ $(TEST_OBJ) $(CORE_OBJS) $(LDFLAGS); st=$$?; \
		end=$$(date +%s); echo "[time] link $@ : $$((end-start)) s"; exit $$st'

# ===== Compile (sources app) =====
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(BASH) -lc 'start=$$(date +%s); \
		$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@; st=$$?; \
		end=$$(date +%s); echo "[time] compile $< : $$((end-start)) s"; exit $$st'

# ===== Compile (tests) =====
$(BUILDDIR)/test_all.o: $(TEST_SRC) $(INCDIR)/Task.h $(INCDIR)/ToDoList.h $(TPHDR) | $(BUILDDIR)
	$(BASH) -lc 'start=$$(date +%s); \
		$(CXX) $(CXXFLAGS) -I$(INCDIR) -I$(TESTDIR) -I$(TPDIR) -c $< -o $@; st=$$?; \
		end=$$(date +%s); echo "[time] compile $< : $$((end-start)) s"; exit $$st'


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
$(BINDIR) $(BUILDDIR) $(LOGDIR):
	mkdir -p $@

# ===== Clean =====
clean:
	rm -rf $(BUILDDIR) $(BINDIR) third_party

# ===== Profiling helper =====
# Build complet avec profilage et capture des rapports dans build/logs/
profile: | $(LOGDIR)
	@echo "== Build avec profilage =="
	$(MAKE) clean all PROFILE=1 2> $(LOGDIR)/compile_times_stderr.log || exit $$?
	@echo "== Rapports =="
	@echo " - GCC (passes & timings)  : $(LOGDIR)/compile_times_stderr.log"
	@echo " - Link time trace (JSON)  : $(BUILDDIR)/link-time-trace.json (si supporté)"
