#include <iostream>
#include <string>



class Student{

    
    public:
    Student& operator=(const Student& s);
    Student();
    Student(const Student& s);
    Student(std::string newName, std::string newId, char newClassification);
    std::string getName() const;
    std::string getid() const;
    char getClassifcation() const;
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    private:

        std::string name;
        std::string id;
        char classification;

};


class Roster{

    
    public:

    Roster& operator=(const Roster& r);

    Roster(const Roster& r);
    friend std::ostream& operator<<(std::ostream& os, const Roster& roster);
    void removeStudent(int index);
    //default constructor
    Roster();

    void addStudent(const Student& student);

    //getters

    Student* getContents() const;
    int getCapacity() const;
    int getSize() const;
    
    //setters
    void setCapacity(int newCapacity);
    void setSize(int newSize);

    

    //destructor

    ~Roster();
    private:

        Student* contents;
        int size;
        int capacity;

};


class Course{

    
    public:


    friend std::ostream& operator<<(std::ostream& os, const Course& course);

    //default constructor
    Course();

    //Parameterized constructor
    Course(std::string newName, std:: string newCode, Roster newRoster);

    void setName(std:: string newName);
    void setCode(std:: string newCode);
    Roster& getRoster();
    std::string getName() const;
    std::string getCode() const;
        

    private:

        std::string name;
        std::string code;
        Roster roster;

};

