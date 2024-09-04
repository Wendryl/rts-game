make:
	cc main.c src/*.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main
	./main
clean:
	rm ./main
