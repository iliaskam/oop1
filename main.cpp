#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "utils.h"

using namespace std;

int main() {
    
    int Cclass = 3, Cyard = 15, Cstair = 10, Ccorr = 10;
    School school(Cclass, Cyard, Cstair, Ccorr);
    srand(time(0));
    /*Student st0("Sotiris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
    school.enter_sschool(st0);*/

    int stud_sum = 30;
	Student* mul_stud[stud_sum];
	mul_stud[0] = new Student("Stephan", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[1] = new Student("Sotis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[2] = new Student("Kostis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[3] = new Student("Giorgos", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[4] = new Student("Aneits", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[5] = new Student("Roulis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[6] = new Student("Soulis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[7] = new Student("Eleni", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[8] = new Student("Makis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[9] = new Student("Ilias", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[10] = new Student("Apostolis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[11] = new Student("Alex", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[12] = new Student("Kiki", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[13] = new Student("Aris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[14] = new Student("Geo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[15] = new Student("Lampis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[16] = new Student("Dimitris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[17] = new Student("Tolis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[18] = new Student("Thomas", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[19] = new Student("Sofia", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[20] = new Student("Eirini", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[21] = new Student("Popi", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[22] = new Student("Koula", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[23] = new Student("Marios", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[24] = new Student("Robert", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[25] = new Student("Tony", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[26] = new Student("Timo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[27] = new Student("Theo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[28] = new Student("David", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[29] = new Student("James", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	
	

	int i = 1;
	while(school.school_size() < Cyard && i <= stud_sum) {
		school.enter_mschool(mul_stud, stud_sum);
		i++;
	}
	school.print_school();

	return  0;
}