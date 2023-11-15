#include "container.h"
#include <iostream>
#include <string>

//default constructor
Roster::Roster(){
    
    capacity = 5;
    size = 0;
    contents = new Student[capacity];
    
}

//copy constructor
Roster::Roster(const Roster& r){

size = r.size;
capacity = r.capacity;
contents = new Student[capacity];
for(int i = 0; i<size; i++){
        contents[i] = r.contents[i];
    }

}

Roster& Roster::operator=(const Roster& r) {
        if (this != &r) {  
            size = r.size;
            capacity = r.capacity;
            delete [] contents;
            contents = new Student[capacity];
            for(int i = 0;i<size;i++){
                contents[i]=r.contents[i];
            }
        }
        return *this;
    }



//destruction operator
Roster::~Roster(){
    delete [] contents;
}

//get capacity of roster
int Roster::getCapacity() const{
    return capacity;
}

//get size of roster
int Roster::getSize() const{
    return size;
}
//set capacity of roster
void Roster::setCapacity(int newCapacity){

this->capacity = newCapacity;
}

void Roster::setSize(int newSize){
    this-> size = newSize;
}



void Roster::addStudent(const Student& student){
    if(size < capacity){
        
    contents[size] = student;
    size++;
    }
    else{
        capacity+=5;
        Student* newContents = new Student[capacity];

        for(int i = 0;i<size;i++){
            newContents[i]=contents[i];
        }
        
        delete[] contents;

        contents = newContents;
        
    }
}

void Roster::removeStudent(int index){
    for(int i = index; i<capacity-1; i++){
        contents[i] = contents[i+1];
    }

    size--;
}

std::ostream& operator<<(std::ostream& os, const Roster& r){
    for(int i=0; i<r.getSize(); i++){
       os <<i<<"......."<<r.contents[i] << std::endl;
    }
    return os;
}





Course::Course(){

    name = "null";
    code = "null";
    roster = Roster();
}

std::ostream& operator<<(std::ostream& os, const Course& course){

    os << course.getName() << std::endl;

    os << "Roster:" <<std::endl<<std::endl<<course.roster;

    return os;
}

Course::Course(std::string newName, std::string newCode, Roster newRoster){

    name = newName;
    code = newCode;
    roster = newRoster;
}

void Course::setName(std:: string newName){
    name = newName;
}


void Course::setCode(std:: string newCode){
    code = newCode;
}


Roster& Course::getRoster(){
    return this-> roster;
}

    std::string Course::getName() const{
        return name;
    }
    std::string Course::getCode() const{
        return code;
    }



Student::Student(){
    name = "null";
    id = "null";
    classification = '0';
}

Student::Student(const Student& s){
        name = s.name;
        id = s.id;
        classification = s.classification;
}

Student& Student::operator=(const Student& s) {
        if (this != &s) {  // Self-assignment check
            name = s.name;
            id = s.id;
            classification = s.classification;
        }
        return *this;
    }

Student::Student(std::string newName, std::string newId, char newClassification){
    this->name = newName;
    this->id = newId;
    this->classification = newClassification;
}

std::string Student::getName() const{
    return name;
}


std::string Student::getid() const{
    return id;
}


char Student::getClassifcation() const{
    return classification;
}

std::ostream& operator<<(std::ostream& os, const Student& student){
    os << student.getName();

    return os;
}