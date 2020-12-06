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
    cout << "A New Teacher has been created! " << name << endl;
}

Teacher::~Teacher() {
    cout << "Deleting Teacher with name " << name << endl;
    delete name;
}

char* Teacher::teacher_name(Teacher& tch) {
    return this->name;
}

int Teacher::teacher_floor(Teacher& tch) {
    return this->floor_num;
}

int Teacher::teacher_class(Teacher& tch) {
    return this->class_num;
}

bool Teacher::teacher_in(Teacher& tch) {
    return this->flag;
}

void Teacher::teacher_set(Teacher& tch) {
    flag == true;
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
    delete teacher;
    cout << "Delete Classroom!" << endl;
}

void Classroom::enter_classroom(Student& st) {
    
    class_student[size] = &st;
    cout << st.student_name(st) << " enters classroom!"<< endl;
    size++;
}

void Classroom::print_classroom(int num) {
    cout << "People in classroom " << num << " are: " << endl;
    for (int i = 0; i < this->size; i++) 
        cout << class_student[i]->student_name(*class_student[i]) << endl;
    if (teacher != NULL)
        cout << "The teacher is: " << teacher->teacher_name(*teacher) << endl;
}

void Classroom::place_teacher(Teacher& tch) {
    teacher = &tch;
    teacher->teacher_set(tch);
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

void Floor::print_floor(int num) {
    cout << "Floor number " << num << " contains: " << endl;
    corridor->print_corr();
    int i = 1;
    classroom1->print_classroom(i++);
    classroom2->print_classroom(i++);
    classroom3->print_classroom(i++);
    classroom4->print_classroom(i++);
    classroom5->print_classroom(i++);
    classroom6->print_classroom(i++);
}

void Floor::place_teacher_floor(Teacher& tch) {
    switch (tch.teacher_class(tch)) {
        case 1:
            classroom1->place_teacher(tch);
            break;
        case 2:
            classroom2->place_teacher(tch);
            break;
        case 3:
            classroom3->place_teacher(tch);
            break; 
        case 4:
            classroom4->place_teacher(tch);
            break;
        case 5:
            classroom5->place_teacher(tch);
            break;
        case 6:
            classroom6->place_teacher(tch);
            break;
    }
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
    students_in = 0;
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
    students_in = students_in + cap;
    while (var < students_in && schoolyard->schoolyard_size() < Cyard) {
        this->enter_sschool(*st[var]);
    }
}

void School::print_school() {
    cout << "School life consists of: " << endl;
    schoolyard->print_yard();
    stairs->print_stairs();
    int i = 1;
    floor1->print_floor(i++);
    floor2->print_floor(i++);
    floor3->print_floor(i++);
}

void School::place_teacher_school(Teacher &tch) {
    switch (tch.teacher_floor(tch)) {
        case 1:
            if (tch.teacher_in(tch) == false)
                floor1->place_teacher_floor(tch);
            break;
        case 2:
            if (tch.teacher_in(tch) == false) 
                floor2->place_teacher_floor(tch);
            break;
        case 3:
            if (tch.teacher_in(tch) == false) 
                floor3->place_teacher_floor(tch);
            break; 
    }
}

int School::school_size() {
    return this->schoolyard->schoolyard_size();
}