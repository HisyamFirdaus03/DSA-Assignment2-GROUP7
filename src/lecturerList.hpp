#pragma once
#include "lecturer.hpp"

class LecturerList{

    private:
        Lecturer* head;
    
    public:
        LecturerList();

        ~LecturerList();

        bool isEmpty();

        void insertNode(Lecturer* node);

        Lecturer* getNode(int position);

        void listAllLecturers();

};