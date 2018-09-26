all: event_store

run: event_store
	./build/event_store

event_store: build/Makefile
	cd build; make

build/Makefile:
	mkdir -p build; cd build; cmake ..;

test:
	cd test; make test

clean:
	-rm -rf build
	-cd test; make clean

.PHONY: test
