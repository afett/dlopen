DEBUG ?= 1
PREFIX ?= ../target

export PKG_CONFIG_PATH=$(PREFIX)/pkgconfig

TARGET = bar

CXX ?= g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS = 
CPPFLAGS = -Isrc/include -Isrc  

DEPS = foo

CXXFLAGS += $(shell pkg-config --cflags $(DEPS))
LIBS = -Wl,--as-needed $(shell pkg-config --libs $(DEPS))

SRC = $(wildcard src/*.cc)
OBJ = $(SRC:%.cc=%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS) $(LIBS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -fPIC -c $< -o $@

install: all
	install -d $(PREFIX)/bin
	install -m 755 $(TARGET) $(PREFIX)/bin

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
