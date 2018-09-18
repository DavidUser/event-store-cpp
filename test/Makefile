GTEST = ../third_party/googletest

all:
	ln -sf ${GTEST} .
	mkdir -p build; cd build; \
		cmake ..; make -j8

${GTEST}:
	git submodule update --init

test run: all
	./build/event_store_tests

clean:
	rm -rf build/*

.PHONY: all test run clean
