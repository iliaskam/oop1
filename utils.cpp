#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "utils.h"

using namespace std;

Teacher::Teacher(const char* nam, int floor_nu, int class_nu, bool fla) {
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
    floor_num = floor_nu;
    class_num = class_nu;
    flag = fla;
    cout << "A New Teacher has been created" << name << endl;
}

Teacher::~Teacher() {
    cout << "Deleting Teacher with name" << name << endl;
    delete name;
}

//////////////////////////////////////////////////////////////////////

Student::Student(const char* nam, int floor_nu, int class_nu, const char* locatio) {
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
    floor_num = floor_nu;
    class_num = class_nu;
    location = new char[strlen(locatio) + 1];
    strcpy(location, locatio);
    cout << "A New Student has been created with name " << name << endl;
}

Student::~Student() {
    cout << "Deleting Student with name " << name << endl;
    delete name;
    delete location;
}

char* Student::student_name(Student& st) {
    return this->name;
}

int Student::student_floor(Student& st) {
    return this->floor_num;
}

//////////////////////////////////////////////////////////////////////

Classroom::Classroom(int Cclas) {
    Cclass = Cclas;
    size = 0;
    class_student = new Student*[Cclass];
    cout << "A New Classroom has been created!" << endl;
}

Classroom::~Classroom() {
    cout << "Delete Classroom!" << endl;
    delete[] class_student;
}

void Classroom::enter_classroom(Student& st) {
    size++;
    class_student[size] = &st;
    cout << st.student_name(st) << " enters classroom!" << endl;
}

//////////////////////////////////////////////////////////////////////

Corridor::Corridor(int Ccor) {
    Ccorr = Ccor;
    size = 0;
    corr_student = new Student*[Ccorr];
    cout << "A New Corridor has been created!" << endl;
}

Corridor::~Corridor() {
    cout << "Delete Corridor!" << endl;
    delete[] corr_student;
}

void Corridor::enter_corr(Student& st) {
    size++;
    corr_student[size] = &st;
    cout << st.student_name(st) << " enters corridor!" << endl;
}

Student& Corridor::exit_corr() {
    Student& temp = *corr_student[size];
    cout << corr_student[size]->student_name(*corr_student[size]) << " exit corridor!" << endl;
    corr_student[size] = NULL;
    size--;
    return temp;
}

int Corridor::corr_size() {
    return this->size;
}

///////////////////////////////////////////////////////////////////////

Floor::Floor(int Cclas, int Ccor) {
    Cclass = Cclas;
    Ccorr = Ccor;
    classroom1 = new Classroom(Cclass);
    classroom2 = new Classroom(Cclass);
    classroom3 = new Classroom(Cclass);
    classroom4 = new Classroom(Cclass);
    classroom5 = new Classroom(Cclass);
    classroom6 = new Classroom(Cclass);
    corridor = new Corridor(Ccorr);
    cout << "A New Floor has been created!" << endl;
}

Floor::~Floor() {
    delete classroom1;
    delete classroom2;
    delete classroom3;
    delete classroom4;
    delete classroom5;
    delete classroom6;
    delete corridor;
    cout << "Delete Floor!" << endl;
}

void Floor::enter_floor(Student& st) {
    
    size++;
    cout << st.student_name(st) << " enters floor!" << endl;
    corridor->enter_corr(st);
    
            Student& temp = corridor->exit_corr();
            switch (temp.student_floor(temp)) {
                case 1:
                    classroom1->enter_classroom(temp);
                    break;
                case 2:
                    classroom2->enter_classroom(temp);
                    break;
                case 3:
                    classroom3->enter_classroom(temp);
                    break; 
                case 4:
                    classroom4->enter_classroom(temp);
                    break;
                case 5:
                    classroom5->enter_classroom(temp);
                    break;
                case 6:
                    classroom6->enter_classroom(temp);
                    break;
            }
            
}

int Floor::floor_size() {
    return this->size;
}


///////////////////////////////////////////////////////////////////////

Stairs::Stairs(int Cstai) {
    Cstair = Cstai;
    size = 0;
    stair_student = new Student*[Cstair];
    cout << "A New Stairs has been created!" << endl;
}

Stairs::~Stairs() {
    cout << "Delete Stairs!" << endl;
    delete[] stair_student;
}

void Stairs::enter_stairs(Student& st) {
    size++;
    stair_student[size] = &st;
    cout << st.student_name(st) << " enters stairs!" << endl;
}

Student& Stairs::exit_stairs() {
    
    Student& temp = *stair_student[size];
    cout << stair_student[size]->student_name(*stair_student[size]) << " exit stairs!" << endl;
    stair_student[size] = NULL;
    size--;
    return temp;
}

int Stairs::stair_size() {
    return this->size;
}
//////////////////////////////////////////////////////////////////////

Schoolyard::Schoolyard(int Cyar) {
    Cyard = Cyar;
    size = 0;
    yard_student = new Student*[Cyard];
    cout << "A New Schoolyard has been created!" << endl;
}

Schoolyard::~Schoolyard() {
    cout << "Delete Shoolyard!" << endl;
    delete[] yard_student;
}

void Schoolyard::enter_schoolyard(Student &st) {
    size++;
    yard_student[size] = &st;
    cout << st.student_name(st) << " enters schoolyard!" << endl;
}

Student& Schoolyard::exit_schoolyard() {
    Student& temp = *yard_student[size];
    cout << yard_student[size]->student_name(*yard_student[size]) << " exit schoolyard!" << endl;
    yard_student[size] = NULL;
    size--;
    return temp;
}

int Schoolyard::schoolyard_size() {
    return this->size;
}

/////////////////////////////////////////////////////////////////////////

School::School(int Cclas, int Cyar, int Cstai, int Ccor) {
    Cclass = Cclas;
    Cyard = Cyar;
    Cstair = Cstai;
    Ccorr = Ccor;
    var = 1;
    var2 =1;
    floor1 = new Floor(Cclass, Ccorr);
    floor2 = new Floor(Cclass, Ccorr);
    floor3 = new Floor(Cclass, Ccorr);
    stairs = new Stairs(Cstair);
    schoolyard = new Schoolyard(Cyard);
    cout << "A New School has been created!" << endl;
}

School::~School() {
    delete floor1;
    delete floor2;
    delete floor3;
    delete stairs;
    delete schoolyard;
    cout << "Delete School!" << endl;
}

void School::enter_sschool(Student& st) {  
    if (schoolyard->schoolyard_size() < Cyard) {
        cout << st.student_name(st) << " enters school!" << endl;
        schoolyard->enter_schoolyard(st);
        var++;
    }
    if (schoolyard->schoolyard_size() == Cyard) {
        while (stairs->stair_size() < Cstair) {
            stairs->enter_stairs(schoolyard->exit_schoolyard());
        }
    }
    if (stairs->stair_size() == Cstair) {
        var2 = 1;
        while (var2 <= Cstair && floor1->floor_size() < Ccorr && floor2->floor_size() < Ccorr && floor3->floor_size() < Ccorr) {
            var2++;
            Student& temp = stairs->exit_stairs();
            switch (temp.student_floor(temp)) {
                case 1:
                    floor1->enter_floor(temp);
                    break;
                case 2:
                    floor2->enter_floor(temp);
                    break;
                case 3:
                    floor3->enter_floor(temp);
                    break; 
            }
            
        }
    }
}

void School::enter_mschool(Student* st[], int cap) {
    while (var <= cap) {
        this->enter_sschool(*st[var]);
    }
}

int School::school_size() {
    return this->schoolyard->schoolyard_size();
}