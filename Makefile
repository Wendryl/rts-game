make:
	cc main.c src/*.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o build/main
	./build/main
clean:
	rm ./build/main
