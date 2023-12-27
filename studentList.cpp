#include "src\studentList.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

StudentList :: StudentList(){

    head = nullptr;
}

StudentList :: ~StudentList(){

    Student* delNode = nullptr, *currNode = head;
    while(currNode){

        delNode = currNode;
        currNode = currNode -> next;
        delete delNode;
    }
}

bool StudentList :: isEmpty(){

    return (head == nullptr);
}

void StudentList :: insertNode(Student* node){

    Student* currNode = head, *prevNode = nullptr;
    while(currNode){

        prevNode = currNode;
        currNode = currNode -> next;
    }

    if(isEmpty()){

        head = node;
        node -> next = nullptr;
    }
    else{

        prevNode -> next = node;
        node -> next = nullptr;
    }
}

Student* StudentList :: getNode(int position){
    
    Student* currNode = head;
    int index = 0;
    while(currNode && position > index){

        currNode = currNode -> next;
        index++;
    }
    return currNode;
}

void StudentList :: listAllStudents(){

    Student *currNode = head;

    cout << left << fixed;
    cout << "Student: \n" 
         << setw(10) << "Name" 
         << setw(14) << "Matric No." 
         << setw(10) << "Course"
         << setw(10) << "CGPA" << endl;

    while(currNode){

        cout << setw(10) << currNode -> getName() 
             << setw(14) << currNode -> getMatricNo() 
             << setw(10) << currNode -> getCourse() 
             << setw(10) << setprecision(2) << currNode -> getCGPA() << endl;
        currNode = currNode -> next;
    }
}
