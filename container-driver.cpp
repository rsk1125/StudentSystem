#include <iostream>
#include <string>
#include <iomanip>
#include "container.h"
using namespace std;
  

//function to print menu and get user option

int menu(int& option){
    cout<<"==========|    System    |=========="<<endl;
    cout<<"||                                ||"<<endl;
    cout<<"|| Options:                       ||"<<endl;
    cout<<"||                                ||"<<endl;
    cout<<"|| 1 - Create a course            ||"<<endl;
    cout<<"|| 2 - Remove a course            ||"<<endl;
    cout<<"|| 3 - List all courses           ||"<<endl;
    cout<<"|| 4 - Enroll student in course   ||"<<endl;
    cout<<"|| 5 - Remove student from course ||"<<endl;
    cout<<"|| 6 - Exit                       ||"<<endl;
    cout<<"===================================="<<endl;

    cout<<"Enter an option:";
    cin>>option;
    while((option != 1) && (option != 2) && (option != 3) && (option !=4) && (option !=5) && (option !=6)){

        cout<<endl<<"Enter a valid option:";
        cin>>option;
    }
    return option;
}


int main()
{

std::string tempName;
std::string tempId;
char tempClassification;

//create a static array to hold courses
int courseCap = 5;
Course courseArray[courseCap];
int select;

//create option and count variables
    int option = 0;
    int numCourseItems = 0;

//display menu
while(option != 6){
    menu(option);

    //create course
    if(option == 1){
        if(numCourseItems == courseCap){
            cout<<"You have reached the maximum amount ("<<courseCap<<") of courses that can be added"<<endl;
                
            
        
        }
        else{
        numCourseItems++;
        std::string name;
        std::string code;
        cout<<"Enter the course name: ";
        cin>>name;
        courseArray[numCourseItems-1].setName(name);
        cout<<"Enter the course code: ";
        cin>>code;
        courseArray[numCourseItems-1].setCode(code);
        }
        }

    if(option == 2){
        cout<<"Enter the number of the course you want to delete:"<<endl<<endl;

        if(numCourseItems != 0){

        for(int i = 0; i<numCourseItems; i++){
            cout<<i<<"......."<<(courseArray[i].getName())<<endl;
        }
        cin>>select;
        courseArray[select].setName("");
        courseArray[select].setCode("");
        }
        else{
            cout<<"No courses to delete";
        }
        
    
    
    
    }


    if(option == 3){
        cout<<"Here is every course:"<<endl<<endl;

        for(int i = 0; i<numCourseItems; i++){
            cout<<"Course: "<<(courseArray[i])<<endl;
        }

        
    
    
    
    }

    if(option == 4){
        if(numCourseItems!=0){
        cout<<"Enter the name of the student: ";

        cin>>tempName;

        cout<<endl<<"Enter the id of the student: ";

        cin>>tempId;

        cout<<endl<<"Enter the classification of the student: ";

        cin>>tempClassification;

        Student studentToAdd(tempName, tempId, tempClassification);
        cout<<endl<<"Select class to enroll "<<tempName<<" in: "<<endl;
        for(int i = 0; i<numCourseItems; i++){
           cout<<i<<"......."<<(courseArray[i].getName())<<endl;
        }

        
        cin>>select;

        courseArray[select].getRoster().addStudent(studentToAdd);

        
        
        
        }
        
    else{
        cout<<"Create at least one class before enrolling a student"<<endl;
    }
    
    
    }

    if(option == 5){
         if(numCourseItems != 0){
            cout<<endl<<"Choose a course to remove student from:"<<endl;

        for(int i = 0; i<numCourseItems; i++){
            cout<<i<<"......."<<(courseArray[i].getName())<<endl;
        }

        cin>>select;
        int tempSelect = select;
        cout<<endl<<"Enrolled Students: "<<endl<<(courseArray[select].getRoster())<<endl;

        cout<<"Select a student to uneroll: ";
        cin>>tempSelect;
        courseArray[select].getRoster().removeStudent(tempSelect);


    
}
else{
    cout<<endl<<"There are no courses to unenroll students from"<<endl<<endl;
}
    
}
}
    return 0;


}