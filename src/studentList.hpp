#pragma once
#include "student.hpp"

class StudentList{

    private:
        Student* head;
    
    public:
        StudentList();

        ~StudentList();

        bool isEmpty();

        void insertNode(Student* node);

        Student* getNode(int position);

        void listAllStudents();

};