CXX := g++
TARGET := hangman
BINDIR := .

# Root program sources
ROOT_SRCS := $(wildcard *.cpp)
ROOT_OBJS := $(patsubst %.cpp,%.o,$(ROOT_SRCS))

OBJS := $(ROOT_OBJS)

# ---- Compiler flags ----
WARNINGS := -Wall -Wextra -Wpedantic -Wshadow -Wconversion

RELEASE_FLAGS := -std=c++20 -O2 -march=native -flto $(WARNINGS)
DEBUG_FLAGS   := -std=c++20 -g -Og -DDEBUG $(WARNINGS) \
                 -fsanitize=address,undefined -fno-omit-frame-pointer

# Default is release
CXXFLAGS := $(RELEASE_FLAGS)

.PHONY: all debug release clean run

all: release

release: CXXFLAGS := $(RELEASE_FLAGS)
release: $(BINDIR)/$(TARGET)

debug: CXXFLAGS := $(DEBUG_FLAGS)
debug: $(BINDIR)/$(TARGET)

# Link step
$(BINDIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OBJS)
	@echo "Built -> $@"

# Compile rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: all
	@./$(BINDIR)/$(TARGET)

clean:
	-@rm -f $(OBJS)
	-@rm -f $(BINDIR)/$(TARGET)
	@echo "Cleaned up the ashes. Nothing but echoes remain..."

.SUFFIXES:
