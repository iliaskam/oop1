erg1: erg1_main.o erg1_utils.o
	g++ erg1_main.o erg1_utils.o -o erg1

erg1_main.o: erg1_main.cpp
	g++ -c erg1_main.cpp

erg1_utils.o: erg1_utils.cpp erg1_utils.h
	g++ -c erg1_utils.cpp

clean:
	rm *.o erg1