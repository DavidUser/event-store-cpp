all: event_store

run: event_store
	./build/event_store

event_store: build/Makefile
	cd build; make

build/Makefile:
	mkdir -p build; cd build; cmake ..;

clean:
	-rm -rf build
