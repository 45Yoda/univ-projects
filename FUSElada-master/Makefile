 

setup: 
	sudo cp ssmtp.conf /etc/ssmtp/
	tar xf fuse-3.4.1.tar.xz
	cp passthrough.c fuse-3.4.1/example/
	mkdir fuse-3.4.1/build
	cd fuse-3.4.1/build/ && meson ..

compile:
	cd fuse-3.4.1/build/ && ninja
	cd fuse-3.4.1/example/ &
	gcc -Wall passthrough.c `pkg-config fuse3 --cflags --libs` -o passthrough
	sudo ./passthrough -o allow_other -f fuse-3.4.1/build/example/50d858e@@passthrough@exe

clean:
	rm -rf fuse-3.4.1 passthrough

fix:
	sudo umount -f fuse-3.4.1/build/example/50d858e@@passthrough@exe
