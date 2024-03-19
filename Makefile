default_target: all

all: clean
		mkdir build && \
		cd build && \
		cmake .. && \
		cmake --build .

install: all
		mkdir -p ~/.config/jotty
		mkdir -p ~/.local/bin
		cp ./jotty.conf ~/.config/jotty/jotty.conf
		cp ./build/jotty ~/.local/bin/jotty

clean:
		rm -rf ./build/
