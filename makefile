CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Wconversion #-O3 
LDFLAGS = -lmpg123 -lao
 

SRCDIR := src
INCDIR := $(SRCDIR)/headers
BUILDDIR := build

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
EXEC = Clonify


all: $(EXEC) 

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp 
	-@mkdir -p $(BUILDDIR)
	-@echo "Generating $@"
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(EXEC): $(OBJECTS)
	-@echo "Linking    $(EXEC)"
	-@for i in *.o ; do if [ $$i != "*.o" ] ; then mv $$i $(BUILDDIR) ; fi ; done
	-@$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

clean:
	-@rm $(BUILDDIR)/*.o $(EXEC)
