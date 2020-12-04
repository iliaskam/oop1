#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "utils.h"

using namespace std;

int main() {
    
    int Cclass = 5, Cyard = 15, Cstair = 10, Ccorr = 10;
    School school(Cclass, Cyard, Cstair, Ccorr);
    srand(time(0));
    /*Student st0("Sotiris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
    school.enter_sschool(st0);*/

    int stud_sum = 30;
	Student* mul_stud[stud_sum];
	Student st1("Sotis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[1] = &st1;
	Student st2("Kostis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[2] = &st2;
	Student st3("Giorgos", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[3] = &st3;
	Student st4("Aneits", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[4] = &st4;
	Student st5("Roulis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[5] = &st5;
	Student st6("Soulis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[6] = &st6;
	Student st7("Eleni", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[7] = &st7;
	Student st8("Makis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[8] = &st8;
	Student st9("Ilias", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[9] = &st9;
	Student st10("Apostolis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[10] = &st10;
	Student st11("Alex", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[11] = &st11;
	Student st12("Kiki", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[12] = &st12;
	Student st13("Aris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[13] = &st13;
	Student st14("Geo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[14] = &st14;
	Student st15("Lampis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[15] = &st15;
	Student st16("Dimitris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[16] = &st16;
	Student st17("Tolis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[17] = &st17;
	Student st18("Thomas", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[18] = &st18;
	Student st19("Sofia", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[19] = &st19;
	Student st20("Eirini", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[20] = &st20;
	Student st21("Popi", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[21] = &st21;
	Student st22("Koula", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[22] = &st22;
	Student st23("Marios", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[23] = &st23;
	Student st24("Robert", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[24] = &st24;
	Student st25("Tony", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[25] = &st25;
	Student st26("Timo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[26] = &st26;
	Student st27("Theo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[27] = &st27;
	Student st28("David", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[28] = &st28;
	Student st29("James", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[29] = &st29;
	Student st30("Stephan", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[30] = &st30;

	int i = 1;
	while(school.school_size() < Cyard && i <= stud_sum) {
		school.enter_mschool(mul_stud, stud_sum);
		i++;
	}

	return  0;
}