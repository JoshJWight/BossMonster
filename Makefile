.PHONY: all build clean run

all: build

build:
	@mkdir -p build
	@cd build && cmake .. && make

clean:
	@rm -rf build

run: build
	@./build/BossMonster
