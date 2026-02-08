PREFIX = ./target

COMPONENTS = \
	foo/interface \
	foo/lib \
	bar \

all: bar

foo/lib: foo/interface
	make -C $@ install

foo/interface:
	make -C $@ install

bar: foo/interface foo/lib
	make -C $@ install

clean:
	rm -rf $(PREFIX); \
	for c in $(COMPONENTS); \
	do \
		make -C "$${c}" clean;\
	done;

run: all
	LD_LIBRARY_PATH=$(PREFIX)/lib ./$(PREFIX)/bin/bar

.PHONY: $(COMPONENTS) clean run
