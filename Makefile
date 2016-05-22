 all:
	g++ *.cpp -std=c++0x -o lab4
	./lab4 0
	./lab4 1000000
	./lab4 123456
	./lab4 31
	./lab4 10001
	./lab4 17

