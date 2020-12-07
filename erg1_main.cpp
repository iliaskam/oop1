#include <iostream>
#include <cstdlib>
#include <ctime>
#include "erg1_utils.h"

using namespace std;

void fill_arrays(Student* s_array[], Teacher* t_array[]);

int main(int argc, char* argv[]) {
    
    int Cclass = atoi (argv[1]);
	int Cyard = atoi (argv[2]);
	int Cstair = atoi (argv[3]);
	int Ccorr = atoi (argv[4]);

	School* school;
    school = new School(Cclass, Cyard, Cstair, Ccorr);
    
    int stud_num = 36;
	int teach_num = 18; 
	Student* mul_stud[stud_num];
	Teacher* teacher_array[teach_num];
	fill_arrays(mul_stud, teacher_array);
	

	int sum_s = 0, sum_t = 0, rand_temp_s, rand_temp_t;
	srand(time(0));

	while(sum_s < stud_num && sum_t < teach_num && school->school_full() == false) {
		rand_temp_s = rand() % 36 + 1;
		if ((sum_s + rand_temp_s) > 36) {
			rand_temp_s = 36 - sum_s;
		}
		school->enter_mschool(mul_stud, rand_temp_s);  // Mpainei toulaxiston enas mathitis
		sum_s = sum_s + rand_temp_s;
		for (int j = 1; j <= rand() % 18; j++) {
			rand_temp_t = rand() % 17;
			if (teacher_array[rand_temp_t] != NULL) {
				school->place_teacher_school(*teacher_array[rand_temp_t]);
				sum_t++;
				teacher_array[rand_temp_t] = NULL;
			}
		}
	}
	school->print_school();

	delete school;
	for (int w = sum_s; w < 36; w++) 	
        delete mul_stud[w - 1];
	for (int i = 0; i < 18; i++)
			delete teacher_array[i];	

	return  0;
}

void fill_arrays(Student* s_array[], Teacher* t_array[]) {

	srand(time(0));

	s_array[0] = new Student("Stephan", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[1] = new Student("Kylo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[2] = new Student("Kostis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[3] = new Student("Giorgos", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[4] = new Student("Aneits", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[5] = new Student("Roulis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[6] = new Student("Soulis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[7] = new Student("Eleni", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[8] = new Student("Makis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[9] = new Student("Ilias", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[10] = new Student("Apostolis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[11] = new Student("Alex", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[12] = new Student("Kiki", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[13] = new Student("Aris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[14] = new Student("Maverick", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[15] = new Student("Lampis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[16] = new Student("Dimitris", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[17] = new Student("Tolis", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[18] = new Student("Thomas", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[19] = new Student("Sofia", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[20] = new Student("Eirini", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[21] = new Student("Popi", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[22] = new Student("Koula", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[23] = new Student("Marios", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[24] = new Student("Robert", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[25] = new Student("Tony", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[26] = new Student("Timo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[27] = new Student("Theo", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[28] = new Student("David", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[29] = new Student("James", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[30] = new Student("Serge", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[31] = new Student("Jack", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[32] = new Student("Ethan", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[33] = new Student("Mason", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[34] = new Student("Robin", rand() % 3 + 1, rand() % 6 + 1, "Out of school");
	s_array[35] = new Student("Emma", rand() % 3 + 1, rand() % 6 + 1, "Out of school");

	t_array[0] = new Teacher("Puff", 1, 1, false);
	t_array[1] = new Teacher("Liam", 1, 2, false);
	t_array[2] = new Teacher("Oliver", 1, 3, false);
	t_array[3] = new Teacher("Owen", 1, 4, false);
	t_array[4] = new Teacher("Violet", 1, 5, false);
	t_array[5] = new Teacher("Finn", 1, 6, false);
	t_array[6] = new Teacher("Michael", 2, 1, false);
	t_array[7] = new Teacher("Hazel", 2, 2, false);
	t_array[8] = new Teacher("Axel", 2, 3, false);
	t_array[9] = new Teacher("Saint", 2, 4, false);
	t_array[10] = new Teacher("Allan", 2, 5, false);
	t_array[11] = new Teacher("Logan", 2, 6, false);
	t_array[12] = new Teacher("Luca", 3, 1, false);
	t_array[13] = new Teacher("Diego", 3, 2, false);
	t_array[14] = new Teacher("Felix", 3, 3, false);
	t_array[15] = new Teacher("Margot", 3, 4, false);
	t_array[16] = new Teacher("Stella", 3, 5, false);
	t_array[17] = new Teacher("Graham", 3, 6, false);
}