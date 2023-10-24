CXX = g++
CXXFLAGS = -Wall
SFMLFLAGS = -lsfml-graphics -lsfml-system -lsfml-window

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TARGET = main

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(INCDIR)/*.hpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: all clean

all: $(BINDIR)/$(TARGET)
	@clear
	@./$(BINDIR)/$(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(SFMLFLAGS)

clean:
	@rm -rf $(OBJDIR)/*
	@rm -rf $(BINDIR)/*
