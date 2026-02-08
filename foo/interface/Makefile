DEBUG ?= 1
PREFIX ?= $(shell pwd)/../../target

TARGET = libfoo.so
PKGCONFIG = foo.pc

FOO_LIB_NAME = foo.so
FOO_LIB_PATH = $(PREFIX)/libexec

CXX ?= g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS =
CPPFLAGS = -Isrc/include -Isrc -D FOO_LIB=$(FOO_LIB_PATH)/$(FOO_LIB_NAME)

LIBS = -ldl -Wl,--as-needed 

SRC = $(wildcard src/*.cc)
OBJ = $(SRC:%.cc=%.o)

all: $(TARGET) $(PKGCONFIG)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS) -shared

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -fPIC -c $< -o $@

$(PKGCONFIG): $(PKGCONFIG).in
	sed \
		-e 's#@PREFIX@#${PREFIX}#' \
		-e 's#@FOO_LIB_NAME@#${FOO_LIB_NAME}#' \
		-e 's#@FOO_LIB_PATH@#${FOO_LIB_PATH}#' \
		$< > $@

install: all
	install -d $(PREFIX)
	install -d $(PREFIX)/lib
	install -d $(PREFIX)/include
	install -d $(PREFIX)/pkgconfig
	install -m 755 $(TARGET) $(PREFIX)/lib/
	install -m 644 src/include/*.h $(PREFIX)/include/
	install -m 644 $(PKGCONFIG) $(PREFIX)/pkgconfig/

clean:
	rm -f $(TARGET) $(OBJ) $(PKGCONFIG)

.PHONY: all clean
