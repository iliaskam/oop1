#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "utils.h"

using namespace std;

int main() {
    
    int Cclass = 3, Cyard = 15, Cstair = 10, Ccorr = 10;
	School* school;
    school = new School(Cclass, Cyard, Cstair, Ccorr);
    srand(time(0));
    /*Student st0("Sotiris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
    school.enter_sschool(st0);*/

    int stud_num = 30;
	int teach_num = 18; 
	Student* mul_stud[stud_num];
	mul_stud[0] = new Student("Stephan", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	mul_stud[1] = new Student("Kylo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
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
	mul_stud[14] = new Student("Maverick", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
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
	
	Teacher* teacher[teach_num];
	teacher[0] = new Teacher("Puff", 1, 1, false);
	teacher[1] = new Teacher("Liam", 1, 2, false);
	teacher[2] = new Teacher("Oliver", 1, 3, false);
	teacher[3] = new Teacher("Owen", 1, 4, false);
	teacher[4] = new Teacher("Violet", 1, 5, false);
	teacher[5] = new Teacher("Finn", 1, 6, false);
	teacher[6] = new Teacher("Michael", 2, 1, false);
	teacher[7] = new Teacher("Hazel", 2, 2, false);
	teacher[8] = new Teacher("Axel", 2, 3, false);
	teacher[9] = new Teacher("Saint", 2, 4, false);
	teacher[10] = new Teacher("Allan", 2, 5, false);
	teacher[11] = new Teacher("Logan", 2, 6, false);
	teacher[12] = new Teacher("Luca", 3, 1, false);
	teacher[13] = new Teacher("Diego", 3, 2, false);
	teacher[14] = new Teacher("Felix", 3, 3, false);
	teacher[15] = new Teacher("Margot", 3, 4, false);
	teacher[16] = new Teacher("Stella", 3, 5, false);
	teacher[17] = new Teacher("Graham", 3, 6, false);

	int sum_s = 0, sum_t = 0, rand_temp_s, rand_temp_t;
	
	while(sum_s < stud_num && sum_t < teach_num) {
		rand_temp_s = rand() % 30 + 1;
		if ((sum_s + rand_temp_s) > 30) {
			rand_temp_s = 30 - sum_s;
		}
		school->enter_mschool(mul_stud, rand_temp_s);  // Mpainei toulaxiston enas mathitis
		sum_s = sum_s + rand_temp_s;
		for (int j = 1; j <= rand() % 18; j++) {
			rand_temp_t = rand() % 17;
			if (teacher[rand_temp_t] != NULL) {
				school->place_teacher_school(*teacher[rand_temp_t]);
				sum_t++;
				teacher[rand_temp_t] = NULL;
			}
		}
	}
	school->print_school();

	delete school;
	for (int w = sum_s; w < 30; w++) 	
        delete mul_stud[w - 1];
	for (int i = 0; i < 18; i++)
			delete teacher[i];	

	return  0;
}