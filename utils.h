
class Teacher {
    char* name;
    int floor_num;
    int class_num;
    bool flag;

    public:

        Teacher(const char* nam, int floor_nu, int class_num, bool fla);
        ~Teacher();
        char* teacher_name(Teacher& tch);
        int teacher_floor(Teacher& tch);
        int teacher_class(Teacher& tch);
        bool teacher_in(Teacher& tch);
        void teacher_set(Teacher& tch);
};

class Student {
    char* name;
    int floor_num;
    int class_num;
    char* location;

    public:

        Student(const char* nam, int floor_nu, int class_num, const char* locatio);
        ~Student();
        char* student_name(Student& st);
        int student_floor(Student& st);
        int student_class(Student& st);
        void student_location(Student& st, const char* loc);
        
};

class Classroom {
    int Cclass;
    int size;
    int classroom_num;
    bool teacher_flag;
    Teacher* teacher;
    Student** class_student;

    public:
 
        Classroom(int Cclass);
        ~Classroom();
        void enter_classroom(Student& st);
        void print_classroom(int num);
        void place_teacher(Teacher& tch);
        bool teacher_in();
        int classroom_size();
};

class Corridor {
    int Ccorr;
    int size;
    Student** corr_student;

    public:

        Corridor(int Ccorr);
        ~Corridor();
        void enter_corr(Student& st);
        void exit_corr();
        void print_corr();
        int corr_size();
};

class Floor {
    int Cclass;
    int Ccorr;
    int size;
    int floor_num;
    Classroom* classroom1;
    Classroom* classroom2;
    Classroom* classroom3;
    Classroom* classroom4;
    Classroom* classroom5;
    Classroom* classroom6;
    Corridor* corridor;

    public:

        Floor(int Cclass, int Ccorr);
        ~Floor();
        void enter_floor(Student& st);
        void print_floor(int num);
        void place_teacher_floor(Teacher& tch);
        int floor_size();
};

class Stairs {
    int Cstair;
    int size;
    Student** stair_student;

    public:

        Stairs(int Cstair);
        ~Stairs(); 
        void enter_stairs(Student &st);
        void exit_stairs();
        void print_stairs();
        int stair_size();
};

class Schoolyard {
    int Cyard;
    int size;
    Student** yard_student;

    public:

        Schoolyard(int Cyar);
        ~Schoolyard();
        void enter_schoolyard(Student &st);
        void exit_schoolyard();
        void print_yard();
        int schoolyard_size();
};

class School {
    int Cclass;
    int Cyard;
    int Cstair;
    int Ccorr;
    int var;
    int students_in;
    Floor* floor1;
    Floor* floor2;
    Floor* floor3;
    Stairs* stairs;
    Schoolyard* schoolyard;
    
    public:

        School(int Cclas, int Cyar, int Cstai, int Ccor);
        ~School();
        void enter_sschool(Student &st);
        void enter_mschool(Student* st[], int cap);
        void print_school();
        void place_teacher_school(Teacher &tch);
        int school_size();
};