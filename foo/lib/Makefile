DEBUG ?= 1
PREFIX ?= ../../target

export PKG_CONFIG_PATH=$(PREFIX)/pkgconfig

TARGET = $(shell pkg-config --variable foo_lib_name foo)
TARGET_PATH = $(shell pkg-config --variable foo_lib_path foo)

CXX ?= g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS = 
CPPFLAGS = -Isrc/include -Isrc  

CXXFLAGS += $(shell pkg-config --cflags foo)

SRC = $(wildcard src/*.cc)
OBJ = $(SRC:%.cc=%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS) -shared $(LIBS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -fPIC -c $< -o $@

install: all
	install -d $(TARGET_PATH)
	install -m 755 $(TARGET) $(TARGET_PATH)

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
