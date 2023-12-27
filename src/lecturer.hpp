#pragma once
#include "member.hpp"
#include "student.hpp"

class Lecturer : public Member{

    private:
        string lecturerID, faculty;
        Student* student[SIZE];
        int studentCount;

    public:
        Lecturer *next;

        Lecturer(string name = "", string lecturerID = "", string faculty = "", University *uni = nullptr);

        void setLecturerID(string lecturerID);

        void setFaculty(string faculty);

        string getLecturerID() const;

        string getFaculty() const;

        int getStudentCount() const;

        void addStudent(Student *stu);

        void listAllStudents();

        int convertIDToInteger();

        Student** getStudents();
};