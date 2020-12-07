#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;

Teacher::Teacher(const char* nam, int floor_nu, int class_nu, bool fla) {   //Constructor tou teacher
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
    floor_num = floor_nu;
    class_num = class_nu;
    flag = fla;
    cout << "A New Teacher has been created! " << name << " floor " << floor_num << " classroom " << class_num << endl;
}

Teacher::~Teacher() {                                               //Destructor tou teacher
    cout << "A Teacher to be destroyed! " << name << " floor " << floor_num << " classroom " << class_num << endl;
    delete name;
}

char* Teacher::teacher_name(Teacher& tch) {                         // Sinartisi pou epistrefei to onoma tou teacher   
    return this->name;
}

int Teacher::teacher_floor(Teacher& tch) {                          // Sinartisi pou epistrefei ton orofo tou teacher
    return this->floor_num;
}

int Teacher::teacher_class(Teacher& tch) {                          // Sinartisi pou epistrefei tin taksi tou teacher
    return this->class_num;
}

bool Teacher::teacher_in(Teacher& tch) {                            // Sinartisi pou epistrefei ean einai entos i ektos taksis o teacher
    return this->flag;
}

void Teacher::teacher_set(Teacher& tch) {                           // Sinartisi pou allazei to status tou teacher (entos i ektos taksis)
    flag == true;
}

//////////////////////////////////////////////////////////////////////

Student::Student(const char* nam, int floor_nu, int class_nu, const char* locatio) {    //Constructor tou student
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
    floor_num = floor_nu;
    class_num = class_nu;
    location = new char[strlen(locatio) + 1];
    strcpy(location, locatio);
    cout << "A New Student has been created! " << name << " floor " << floor_num << " classroom " << class_num << endl;
}

Student::~Student() {   //Destructor tou teacher
    cout << "A Student to be destroyed! " << name << " floor " << floor_num << " classroom " << class_num << " location " << location << endl;
    delete name;
    delete location;
}

char* Student::student_name(Student& st) {                      // Sinartisi pou epistrefei to onoma tou student
    return this->name;
}

int Student::student_floor(Student& st) {                       // Sinartisi pou epistrefei ton orofo tou student
    return this->floor_num;
}

int Student::student_class(Student& st) {                       // Sinartisi pou epistrefei tin taksi tou teacher
    return this->class_num;
}

void Student::student_location(Student& st, const char* loc) {  // Sinartisi pou epistrefei to onoma tou student
    strcpy(this->location, loc);
}

//////////////////////////////////////////////////////////////////////

Classroom::Classroom(int Cclas) {                               // Constructor tis taskis
    Cclass = Cclas;
    size = 0;
    classroom_num = 0;
    teacher_flag = false;
    class_student = new Student*[Cclass];                       // Dilosi tou pinaka ton mathiton
    
    cout << "A New Classroom has been created!" << endl;
}

Classroom::~Classroom() {                                       // Destractor tis taksis
    for (int i = 0; i < Cclass; i++) 
        delete class_student[i];                                // Kano delete ton pinaka kai tous mathites pou exei mesa
    delete[] class_student;              
    delete teacher;
    cout << "Delete Classroom!" << endl;
}

void Classroom::enter_classroom(Student& st) {                  // Enter mathiti stin taksi
    
    st.student_location(st, "classroom");                       // Allazo tin topothesia tou
    class_student[size] = &st;                                  // Bazo stin katalilli thesi ton deikti ston mathiti
    cout << st.student_name(st) << " enters classroom!"<< endl;
    size++;                                                     // Auksano to size pou einai kai i thesi tou mathiti ston pinaka
}

void Classroom::print_classroom(int num) {                      // Ektiposi tis taksis
    cout << "People in classroom " << num << " are: " << endl;
    for (int i = 0; i < this->size; i++) 
        cout << class_student[i]->student_name(*class_student[i]) << endl;
    if (teacher != NULL)                                        // Tipono ton teacher mono otan einai != NULL diladi exei mpei stin taski
        cout << "The teacher is: " << teacher->teacher_name(*teacher) << endl;
}

void Classroom::place_teacher(Teacher& tch) {                   // Sinartisi gia tin topothetisi tou teacher
    teacher = &tch;                                             // Bazo ston deikti teacher tin dieuthinsi tou teacher tis eisodou
    teacher->teacher_set(tch);                                  // Allazo to status tou teacher se entos taksis
    teacher_flag = true;                                        // Allazo to flag tou teacher se entos taksis gia na gnorizei kai i taski pote
}                                                                               // einai mesa o teacher

bool Classroom::teacher_in() {                                  // Sinartisi pou epistrefei to status tou teacher mesa apo tin classroom
    return this->teacher_flag;
}

int Classroom::classroom_size() {                               // Sinartisi pou epistrefei to plithos ton mathiton pou einai mesa stin taksi
    return this->size;
}
//////////////////////////////////////////////////////////////////////

Corridor::Corridor(int Ccor) {                                  // Construstor tou diadromou
    Ccorr = Ccor;
    size = 0;
    corr_student = new Student*[Ccorr];                         // Dilosi tou pinaka ton mathiton
    cout << "A New Corridor has been created!" << endl;
}

Corridor::~Corridor() {                                         // Destructor tou diadromou
    for (int i = 0; i < Ccorr; i++) 
        delete corr_student[i];                                 // Kano delete ton pinaka kai tous mathites pou exei mesa
    delete[] corr_student;
    cout << "Delete Corridor!" << endl;
}

void Corridor::enter_corr(Student& st) {                        // enter mathiti ston diadromo
    
    st.student_location(st, "corridor");                        // Allazo tin topothesia tou
    corr_student[size] = &st;                                   // Bazo stin katalilli thesi ton deikti ston mathiti
    cout << st.student_name(st) << " enters corridor!" << endl;
    size++;                                                    // Auksano to size pou einai kai i thesi tou mathiti ston pinaka
}

void Corridor::exit_corr() {                                   // exit mathiti apo diadromo
    size--;                                                    // Meiono to size pou einai kai i thesi tou mathiti ston pinaka
    cout << corr_student[size]->student_name(*corr_student[size]) << " exit corridor!" << endl;
    corr_student[size] = NULL;                                 // Kano to deikti pou deixnei sto mathiti pou kanei exit na deixnei null
    
}

void Corridor::print_corr() {                                  // Ektiposi diadromou
    cout << "People in corridor are: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << corr_student[i]->student_name(*corr_student[i]) << endl;
    }
}

int Corridor::corr_size() {                                     // Sinartisi pou epistrefei to size tou diadromou
    return this->size;
}

///////////////////////////////////////////////////////////////////////

Floor::Floor(int Cclas, int Ccor) {                            // Constructor tou orofou 
    Cclass = Cclas;
    Ccorr = Ccor;
    classroom1 = new Classroom(Cclass);                         // Kalo ton constructor kai desmeuo xoro gia kathe mia taksi apo tis 6 
    classroom2 = new Classroom(Cclass);
    classroom3 = new Classroom(Cclass);
    classroom4 = new Classroom(Cclass);
    classroom5 = new Classroom(Cclass);
    classroom6 = new Classroom(Cclass);
    corridor = new Corridor(Ccorr);                             // Kalo ton constructor kai desmeuo xoro gia ton diadromo
    cout << "A New Floor has been created!" << endl;
}

Floor::~Floor() {                                               // Destructor tou orofou
    delete classroom1;                                          // Kalo destructor ton takseon kai tou diadromou
    delete classroom2;
    delete classroom3;
    delete classroom4;
    delete classroom5;
    delete classroom6;
    delete corridor;
    cout << "Delete Floor!" << endl;
}

void Floor::enter_floor(Student& st) {                          // enter mathiti ston orofo
    cout << st.student_name(st) << " enters floor!" << endl;
    corridor->enter_corr(st);                                   // O orofos den exei diko tou xoro ara kaloume tin enter tou diadromou
    switch (st.student_class(st)) {                             // Analoga tin taski pou thelei na paei o mathitis kaloume to sosto case
        case 1:                                                         // an den exei mpei teacher kai o mathitis xoraei stin taksi kaloume enter taksis, exit diadromou
            if (classroom1->classroom_size() < Cclass && classroom1->teacher_in() == false) {
                corridor->exit_corr();
                this->classroom1->enter_classroom(st);
            }
            break;
        case 2:
            if (classroom2->classroom_size() < Cclass && classroom2->teacher_in() == false) {
                corridor->exit_corr();
                this->classroom2->enter_classroom(st);
            }
            break;
        case 3:
            if (classroom3->classroom_size() < Cclass && classroom3->teacher_in() == false) {
                corridor->exit_corr();
                this->classroom3->enter_classroom(st);
            }       
            break; 
        case 4:
            if (classroom4->classroom_size() < Cclass && classroom4->teacher_in() == false ) {
                corridor->exit_corr();
                this->classroom4->enter_classroom(st);
            }
            break;
        case 5:
            if (classroom5->classroom_size() < Cclass && classroom5->teacher_in() == false ) {
                corridor->exit_corr();
                this->classroom5->enter_classroom(st);
            }
            break;
        case 6:
            if (classroom6->classroom_size() < Cclass && classroom6->teacher_in() == false ) {
                corridor->exit_corr();
                this->classroom6->enter_classroom(st);
            }
            break;
        }            
}

void Floor::print_floor(int num) {                                  // Ektiposi orofou kai ton sistatikon tou
    cout << "Floor number " << num << " contains: " << endl;
    corridor->print_corr();                                         
    int i = 1;                                                      // Dino se kathe print taksis san orisma ton aritmo tis gia na ton tiposo
    classroom1->print_classroom(i++);
    classroom2->print_classroom(i++);
    classroom3->print_classroom(i++);
    classroom4->print_classroom(i++);
    classroom5->print_classroom(i++);
    classroom6->print_classroom(i++);
}

void Floor::place_teacher_floor(Teacher& tch) {                      // Klisi tis place teacher apo ton orofo tou teacher
    switch (tch.teacher_class(tch)) {                                // Analoga tin taksi tou kathigiti mpaino sto sosto case 
        case 1:                                                             // kai kalo place teacher tis taksis
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

int Floor::floor_size() {                                           // Epistrefei to megethos tou orofou diladi tou  diadromou
    return corridor->corr_size();
}


///////////////////////////////////////////////////////////////////////

Stairs::Stairs(int Cstai) {                                         // Constructor tou stairs       
    Cstair = Cstai;
    size = 0;
    stair_student = new Student*[Cstair];                           // Dilosi tou pinaka ton mathiton 
    cout << "A New Stairs has been created!" << endl;
}

Stairs::~Stairs() {                                                 // Destructor tou stairs
    for (int i = 0; i < Cstair; i++)
        delete stair_student[i];                                    // Kano delete tous mathites mesa sto stairs
    delete[] stair_student;
    cout << "Delete Stairs!" << endl;
}

void Stairs::enter_stairs(Student& st) {                            // enter gia to stairs   
    
    st.student_location(st, "stairs");                              // Allazo tin topothesia tou
    stair_student[size] = &st;                                      // Bazo stin katalilli thesi ton deikti ston mathiti
    cout << st.student_name(st) << " enters stairs!" << endl;
    size++;                                                         // Auksano to size pou einai kai i thesi tou mathiti ston pinaka
}

void Stairs::exit_stairs() {                                        // exit gia ton mathiti apo to stairs
    
    size--;                                                         // Meiono to size pou einai kai i thesi tou mathiti ston pinaka
    cout << stair_student[size]->student_name(*stair_student[size]) << " exit stairs!" << endl;
    stair_student[size] = NULL;                                     // Kano null ton deikti ston mathiti pou kanei exit

}

void Stairs::print_stairs() {                                       // print tou stairs
    cout << "People in stairs are: " << endl;
    for (int i = 0; i < this->size; i++) {                          // Tipono tou mathites sto klimakostasio
        cout << stair_student[i]->student_name(*stair_student[i]) << endl;
    }
}

int Stairs::stair_size() {                                          // Sinartisi pou epistrefei to megethos tou stairs
    return this->size;
}
//////////////////////////////////////////////////////////////////////

Schoolyard::Schoolyard(int Cyar) {                                  // Constructor tou schoolyard
    Cyard = Cyar;
    size = 0;
    yard_student = new Student*[Cyard];                             // Dilosi tou pinaka ton mathiton 
    cout << "A New Schoolyard has been created!" << endl;
}

Schoolyard::~Schoolyard() {                                         // Destructor tou school
    for (int i = 0; i < Cyard; i++)
        delete yard_student[i];                                     // Kano delete tous mathites mesa sto schoolyard
    delete[] yard_student;
    cout << "Delete Shoolyard!" << endl;
}

void Schoolyard::enter_schoolyard(Student &st) {                    // enter gia to schoolyard
    st.student_location(st, "schoolyard");                          // Allazo tin topothesia tou mathiti
    yard_student[size] = &st;                                       // Bazo stin katalilli thesi ton deikti ston mathiti
    cout << st.student_name(st) << " enters schoolyard!" << endl;
    size++;                                                         // Auksano to size pou einai kai i thesi tou mathiti ston pinaka
}

void Schoolyard::exit_schoolyard() {                                // exit gia ton mathiti apo to schoolyard
    size--;                                                         // Meiono to size pou einai kai i thesi tou mathiti ston pinaka
    cout << yard_student[size]->student_name(*yard_student[size]) << " exit schoolyard!" << endl;
    yard_student[size] = NULL;                                      // Kano to deikti tou mathiti pou kanei exit null
}

void Schoolyard::print_yard() {                                     // Ektiposi tou schoolyard kai ton mathiton tou
    cout << "People in schoolyard are: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << yard_student[i]->student_name(*yard_student[i]) << endl;
    }
}

int Schoolyard::schoolyard_size() {                                  // Sinartisi pou epistrefei to size tou schoolyard           
    return this->size;
}

/////////////////////////////////////////////////////////////////////////

School::School(int Cclas, int Cyar, int Cstai, int Ccor) {          // Constructor tou school              
    Cclass = Cclas;
    Cyard = Cyar;
    Cstair = Cstai;
    Ccorr = Ccor;
    var = 0;                                                        // Metavliti pou auksanei me tin eisodo mathiti gia na diavazo ton sosto mathiti
    students_in = 0;                                                // Metavliti pou krataei pou mathites exoun mpei
    floor1 = new Floor(Cclass, Ccorr);                              // Kalo ton constructor orofon, klimakostasiou kai aulis
    floor2 = new Floor(Cclass, Ccorr);
    floor3 = new Floor(Cclass, Ccorr);
    stairs = new Stairs(Cstair);
    schoolyard = new Schoolyard(Cyard);
    cout << "A New School has been created!" << endl;
}

School::~School() {                                                 // Destructor tou school
    delete floor1;                                                  // Kalo destructor orofon, klimakostasiou kai aulis
    delete floor2;
    delete floor3;
    delete stairs;
    delete schoolyard;
    cout << "Delete School!" << endl;
}

void School::enter_sschool(Student& st) {                           // enter enos mathiti stin auli
    if (schoolyard->schoolyard_size() < Cyard) {                    // An o mathitis xoraei mpainei stin auli 
        cout << st.student_name(st) << " enters school!" << endl;
        schoolyard->enter_schoolyard(st);
    } else {   
        this->full = true;                                          // An o mathitis den xoraei epistrefo oti to sxoleio gemise
        return;
    }
    if (stairs->stair_size() < Cstair) {                            // An o mathitis xoraei mpainei stin auli
            schoolyard->exit_schoolyard();
            stairs->enter_stairs(st);
    } else {
        return;                                                     // An o mathitis den xoraei epistrefo gia ton epomeno mathiti
    }
    switch (st.student_floor(st)) {                                 // Analoga ton orofo pou thelei na paei o mathitis mpaino sto sosto case
        case 1:
            if (floor1->floor_size() < Ccorr) {                     // An xoraei ston orofo kalo exit klimakostasiou kai enter orofou
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

void School::enter_mschool(Student* st[], int cap) {                // enter pollaplon mathiton pairno ton pinaka mathiton kai kalo gia kathe enan tin enter tou sxoleiou enos mathiti
    students_in = students_in + cap;                                // Metavliti pou krataei to sinolo mathiton tou sxoleiou             
    while (var < students_in && schoolyard->schoolyard_size() < Cyard) {
        this->enter_sschool(*st[var]);
        var++;                                                      // Metavliti pou auksanei gia na pairno enan ksexoristo mathiti tou pinaka kathe fora
    }
}

void School::print_school() {                                       // Ektiposi sxoleiou kai sistatikon tou
    cout << "School life consists of: " << endl;
    schoolyard->print_yard();
    stairs->print_stairs();
    int i = 1;                                                      // Dino stous orofous orisma ton arithmo tous gia na ton tiposoun
    floor1->print_floor(i++);
    floor2->print_floor(i++);
    floor3->print_floor(i++);
}

void School::place_teacher_school(Teacher &tch) {                   // Place tou teacher ston sosto orofo an den exei mpei idi
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

int School::school_size() {                                          // Sinartisi epistrefei to megethos tou school diladi tis aulis
    return this->schoolyard->schoolyard_size();
}

bool School::school_full() {                                         // Sinartisi pou epistefei an to sxoleio gemise 
    return this->full;
}