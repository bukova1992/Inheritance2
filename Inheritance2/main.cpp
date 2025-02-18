#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define delimiter "\n--------------------------------------------------------"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
    std::string last_name;
    std::string first_name;
    unsigned int age;
public:
    const std::string& get_last_name()const
    {
        return last_name;
    }
    const std::string& get_first_name()const
    {
        return first_name;
    }
    const unsigned int get_age()const
    {
        return age;
    }
    void set_last_name(const std::string& last_name)
    {
        this->last_name = last_name;
    }
    void set_first_name(const std::string& first_name)
    {
        this->first_name = first_name;
    }
    void set_age(unsigned int age)
    {
        this->age = age;
    }
    Human(HUMAN_TAKE_PARAMETERS)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_age(age);
        cout << "HConstructor:\t" << this << endl;
    }

    virtual ~Human()
    {
        cout << "Hdestructor:\t" << this << endl;
    }
    virtual void info()const
    {
        cout << last_name << " " << first_name << " " << age << " y/o " << endl;

    }
    virtual std::ostream& info(std::ostream& os)const
    {
        return os << last_name << " " << first_name << " " << age << " y/o ";

    }
};

std::ostream& operator <<(std::ostream& os, const Human& obj)
{
    return obj.info(os);
}

#define STUDENT_TAKE_PARAMETERS const std ::string& speciality, const std ::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
    std::string speciality;
    std::string group;
    double rating;
    double attendance;
public:
    const std::string& get_speciality()const
    {
        return speciality;

    }
    const std::string& get_group()const
    {
        return group;

    }
    double get_rating()const
    {
        return rating;

    }
    double get_attendance()const
    {
        return attendance;

    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void set_group(const std::string& group)
    {
        this->group = group;
    }
    void set_rating(double rating)
    {
        this->rating = rating;
    }
    void set_attendance(double attendance)
    {
        this->attendance = attendance;
    }
    Student
    (
        HUMAN_TAKE_PARAMETERS,
        STUDENT_TAKE_PARAMETERS
    ) :Human(HUMAN_GIVE_PARAMETERS)
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);
        cout << "SConstructor:\t " << this << endl;
    }
    ~Student()
    {
        cout << "SDestructor:\t" << this << endl;
    }
    void info()const override
    {
        Human::info();
        cout << speciality << " " << group << " " << rating << " " << attendance << endl;
    }
    std::ostream& info(std::ostream& os)const override
    {
        Human::info(os);
        return Human::info(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
    }
};

class Teacher : public Human
{
    std::string speciality;
    unsigned int experience;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
    unsigned int get_experience()const
    {
        return experience;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void set_experience(unsigned int experience)
    {
        this->experience = experience;
    }
    Teacher(HUMAN_TAKE_PARAMETERS, const std::string& speciality, unsigned int experience) :Human(HUMAN_GIVE_PARAMETERS)
    {
        set_speciality(speciality);
        set_experience(experience);
        cout << "TConstructor:\t" << this << endl;
    }
    ~Teacher()
    {
        cout << "TDestructor:\t" << this << endl;
    }
    void info()const
    {
        Human::info();
        cout << speciality << " " << experience << " " << "years" << endl;
    }
    std::ostream& info(std::ostream& os)const
    {
        return Human::info(os) << " " << speciality << " " << experience << " " << "years";
    }
};

class Graduate :public Student
{
    std::string subject;
public:
    const std::string& get_subject()const
    {
        return subject;
    }
    void set_subject(const std::string& subject)
    {
        this->subject = subject;
    }
    Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :
        Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
    {
        set_subject(subject);
        cout << "GConstructor:\t" << this << endl;

    }
    ~Graduate()
    {
        cout << "GDestructor:\t" << this << endl;
    }
    void info() const override
    {
        Student::info();
        cout << subject << endl;
    }
    std::ostream& info(std::ostream& os) const override
    {
        return Student::info(os) << " " << subject;
    }
};

void Print(Human* group[], const int n)
{
    cout << delimiter << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *group[i] << endl;
        cout << delimiter << endl;

    }
}

void Clear(Human* group[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        delete group[i];
    }
}

void Save(Human* group[], const int n, const std::string& filename)
{
    std::ofstream fout(filename);
    for (int i = 0; i < n; i++)
    {
        fout << *group[i] << endl;
    }
    fout.close();
    std::string cmd = "notepad " + filename;
    system(cmd.c_str());
}

//#define INHERITANCE_CHECK

void main()
{
    setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
    Human human("Vercetty", "Tommy", 30);
    human.info();

    Student student("Pinkam", "Jessie", 22, "Chemistry", "WW_220", 70, 97);
    student.info();

    Teacher teacher("White", "Walter", 50, "Chemistry", 25);
    teacher.info();
#endif // INHERITANCE_CHECK
    // Generalization
    Human* group[] =
    {
      new Student("Pinkam", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
      new Teacher("White", "Walter", 50, "Chemistry", 25),
      new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 80, 90, "How to catch Heisenberg"),
      new Student("Vercetty", "Tommy", 30, "Theft", "Vice" ,97, 98)
    };

    Print(group, sizeof(group) / (sizeof(group)[0]));
    Save(group, sizeof(group) / (sizeof(group)[0]), "group.txt");


    Clear(group, sizeof(group) / (sizeof(group)[0]));


}