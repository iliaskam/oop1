
class Teacher {
    char* name;
    int floor_num;
    int class_num;
    bool flag;

    public:

        Teacher(const char* nam, int floor_nu, int class_num, bool fla);
        ~Teacher();
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
};

class Classroom {
    int Cclass;
    int size;
    int classroom_num;
    Student** class_student;

    public:
 
        Classroom(int Cclass);
        ~Classroom();
        void enter_classroom(Student& st);
        void print_classroom();
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
        void print_floor();
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
    Stairs* stairs;
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
        int school_size();
};