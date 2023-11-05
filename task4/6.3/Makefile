all:
	gcc -fPIC -c calc.c 
	gcc -shared calc.o -o calc.so
	gcc main.c -o calc -ldl