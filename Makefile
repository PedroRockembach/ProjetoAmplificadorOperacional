CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g
TARGET = main.exe

SOURCES = main.cpp \
          lib/AmplificadorOperacional/AmplificadorOperacional.cpp \
          lib/AmplificadorInversor/AmplificadorInversor.cpp \
          lib/AmplificadorNaoInversor/AmplificadorNaoInversor.cpp \
          lib/AmplificadorDiferencial/AmplificadorDiferencial.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    del /Q $(OBJECTS) $(TARGET)

.PHONY: all clean