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

int Student::student_class(Student& st) {
    return this->class_num;
}

//////////////////////////////////////////////////////////////////////

Classroom::Classroom(int Cclas) {
    Cclass = Cclas;
    size = 0;
    classroom_num = 0;
    class_student = new Student*[Cclass];
    
    cout << "A New Classroom has been created!" << endl;
}

Classroom::~Classroom() {
    for (int i = 0; i < Cclass; i++) 
        delete class_student[i];
    delete[] class_student;
    cout << "Delete Classroom!" << endl;
}

void Classroom::enter_classroom(Student& st) {
    
    class_student[size] = &st;
    cout << st.student_name(st) << " enters classroom!"<< endl;
    size++;
}

void Classroom::print_classroom() {
    classroom_num++;
    cout << "People in classroom " << classroom_num << " are: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << class_student[i]->student_name(*class_student[i]) << endl;
    }
}

int Classroom::classroom_size() {
    return this->size;
}
//////////////////////////////////////////////////////////////////////

Corridor::Corridor(int Ccor) {
    Ccorr = Ccor;
    size = 0;
    corr_student = new Student*[Ccorr];
    cout << "A New Corridor has been created!" << endl;
}

Corridor::~Corridor() {
    for (int i = 0; i < Ccorr; i++) 
        delete corr_student[i];
    delete[] corr_student;
    cout << "Delete Corridor!" << endl;
}

void Corridor::enter_corr(Student& st) {
    
    corr_student[size] = &st;
    cout << st.student_name(st) << " enters corridor!" << endl;
    size++;
}

void Corridor::exit_corr() {
    size--;
    cout << corr_student[size]->student_name(*corr_student[size]) << " exit corridor!" << endl;
    corr_student[size] = NULL;
    
}

void Corridor::print_corr() {
    cout << "People in corridor are: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << corr_student[i]->student_name(*corr_student[i]) << endl;
    }
}

int Corridor::corr_size() {
    return this->size;
}

///////////////////////////////////////////////////////////////////////

Floor::Floor(int Cclas, int Ccor) {
    Cclass = Cclas;
    Ccorr = Ccor;
    floor_num = 0;
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
    cout << st.student_name(st) << " enters floor!" << endl;
    corridor->enter_corr(st);
    switch (st.student_class(st)) {
        case 1:
            if (classroom1->classroom_size() < Cclass) {
                corridor->exit_corr();
                this->classroom1->enter_classroom(st);
            }
            break;
        case 2:
            if (classroom2->classroom_size() < Cclass) {
                corridor->exit_corr();
                this->classroom2->enter_classroom(st);
            }
            break;
        case 3:
            if (classroom3->classroom_size() < Cclass) {
                corridor->exit_corr();
                this->classroom3->enter_classroom(st);
            }       
            break; 
        case 4:
            if (classroom4->classroom_size() < Cclass) {
                corridor->exit_corr();
                this->classroom4->enter_classroom(st);
            }
            break;
        case 5:
            if (classroom5->classroom_size() < Cclass) {
                corridor->exit_corr();
                this->classroom5->enter_classroom(st);
            }
            break;
        case 6:
            if (classroom6->classroom_size() < Cclass) {
                corridor->exit_corr();
                this->classroom6->enter_classroom(st);
            }
            break;
        }            
}

void Floor::print_floor() {
    floor_num++;
    cout << "Floor number " << floor_num << " contains: " << endl;
    corridor->print_corr();
    classroom1->print_classroom();
    classroom2->print_classroom();
    classroom3->print_classroom();
    classroom4->print_classroom();
    classroom5->print_classroom();
    classroom6->print_classroom();
}

int Floor::floor_size() {
    return corridor->corr_size();
}


///////////////////////////////////////////////////////////////////////

Stairs::Stairs(int Cstai) {
    Cstair = Cstai;
    size = 0;
    stair_student = new Student*[Cstair];
    cout << "A New Stairs has been created!" << endl;
}

Stairs::~Stairs() {
    for (int i = 0; i < Cstair; i++)
        delete stair_student[i];
    delete[] stair_student;
    cout << "Delete Stairs!" << endl;
}

void Stairs::enter_stairs(Student& st) {
    
    stair_student[size] = &st;
    cout << st.student_name(st) << " enters stairs!" << endl;
    size++;
}

void Stairs::exit_stairs() {
    
    size--;
    cout << stair_student[size]->student_name(*stair_student[size]) << " exit stairs!" << endl;
    stair_student[size] = NULL;

}

void Stairs::print_stairs() {
    cout << "People in stairs are: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << stair_student[i]->student_name(*stair_student[i]) << endl;
    }
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
    for (int i = 0; i < Cyard; i++)
        delete yard_student[i];
    delete[] yard_student;
    cout << "Delete Shoolyard!" << endl;
}

void Schoolyard::enter_schoolyard(Student &st) {
    yard_student[size] = &st;
    cout << st.student_name(st) << " enters schoolyard!" << endl;
    size++;
}

void Schoolyard::exit_schoolyard() {
    size--;
    cout << yard_student[size]->student_name(*yard_student[size]) << " exit schoolyard!" << endl;
    yard_student[size] = NULL;
}

void Schoolyard::print_yard() {
    cout << "People in schoolyard are: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << yard_student[i]->student_name(*yard_student[i]) << endl;
    }
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
    var = 0;
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
    if (stairs->stair_size() < Cstair) {
            schoolyard->exit_schoolyard();
            stairs->enter_stairs(st);
    }
    switch (st.student_floor(st)) {
        case 1:
            if (floor1->floor_size() < Ccorr) {
                stairs->exit_stairs();
                floor1->enter_floor(st);
            }    
            break;
        case 2:
            if (floor2->floor_size() < Ccorr) {
                stairs->exit_stairs();
                floor2->enter_floor(st);
            }
            break;
        case 3:
            if (floor3->floor_size() < Ccorr) {
                stairs->exit_stairs();
                floor3->enter_floor(st);
            }
            break; 
    }
    
}

void School::enter_mschool(Student* st[], int cap) {
    while (var < cap && schoolyard->schoolyard_size() < Cyard) {
        this->enter_sschool(*st[var]);
    }
}

void School::print_school() {
    cout << "School life consists of: " << endl;
    schoolyard->print_yard();
    stairs->print_stairs();
    floor1->print_floor();
    floor2->print_floor();
    floor3->print_floor();
}

int School::school_size() {
    return this->schoolyard->schoolyard_size();
}