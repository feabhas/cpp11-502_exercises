TARGET = cpp11-502.exe

CFLAGS   = -Wall -O0 -g -std=c99 
CPPFLAGS = -Wall -Wextra -O0 -g -std=c++17 

LNFLAGS  = -Wall -static -lpthread 

SRCDIR   = src
OBJDIR   = debug
BINDIR   = debug

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LNFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

run:
	$(BINDIR)/$(TARGET)

clean:
	$(RM) $(OBJECTS) $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"
