#include "src\lecturerList.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

LecturerList :: LecturerList(){

    head = nullptr;
}

LecturerList :: ~LecturerList(){

    Lecturer* delNode = nullptr, *currNode = head;
    while(currNode){

        delNode = currNode;
        currNode = currNode -> next;
        delete delNode;
    }
}

bool LecturerList :: isEmpty(){

    return (head == nullptr);
}

void LecturerList :: insertNode(Lecturer* node){

    Lecturer* currNode = head, *prevNode = nullptr;
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

Lecturer* LecturerList :: getNode(int position){
    
    Lecturer* currNode = head;
    int index = 0;
    while(currNode && position > index){

        currNode = currNode -> next;
        index++;
    }
    return currNode;
}

void LecturerList :: listAllLecturers(){

    Lecturer* currNode = head;

    cout << left << fixed;
    cout << "Lecturer: \n" 
         << setw(10) << "Name" 
         << setw(14) << "Lecturer ID" 
         << setw(10) << "Faculty" << endl;

    while(currNode){

        cout << setw(10) << currNode -> getName() 
             << setw(14) << currNode -> getLecturerID() 
             << setw(10) << currNode -> getFaculty() << endl;
        currNode = currNode -> next;
    }
}
