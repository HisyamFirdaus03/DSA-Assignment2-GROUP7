#include "src\lecturer.hpp"
#include "src\sortingsearch.hpp"
#include <iostream>
#include <iomanip>

Lecturer :: Lecturer(string name, string lecturerID, string faculty, University *uni) : Member(name, uni){

    this -> lecturerID = lecturerID;
    this -> faculty = faculty;
    studentCount = 0;
    next = nullptr;
}

void Lecturer :: setLecturerID(string lecturerID){

    this -> lecturerID = lecturerID;
}

void Lecturer :: setFaculty(string faculty){

    this -> faculty = faculty;
}

string Lecturer :: getLecturerID() const{

    return lecturerID;
}

string Lecturer :: getFaculty() const{

    return faculty;
}

int Lecturer :: getStudentCount() const{

    return studentCount;
}


void Lecturer :: addStudent(Student *stu){

    student[studentCount] = stu;
    studentCount++;
}

//Quick Sort is implemented to sort the students by matric no
void Lecturer :: listAllStudents(){

    int iMatricNo[10];
    for(int i = 0; i < studentCount; i++){

        iMatricNo[i] = student[i] -> convertMatricToInteger();
    }  

    quickSort<Student*, int>(student, 0, studentCount - 1, iMatricNo);

    cout << endl;
    cout << "List of students" << endl;
    cout << left << fixed;
    cout << setw(16) << "Name" << ": " << getName() << endl;
    cout << setw(16) << "Lecturer ID" << ": " << lecturerID << endl;
    cout << setw(16) << "Faculty" << ": " << faculty << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(4) << "No." << setw(12) << "Matric No." << setw(30) << "Name";
    cout << setw(4) << "CGPA" << endl;
    cout << "--------------------------------------------------" << endl;
    for(int i = 0; i < studentCount; i++){

        cout << setw(4) << setprecision(0) << i + 1 << setw(12) << student[i] -> getMatricNo();
        cout << setw(30) << setprecision(0) << student[i] -> getName();
        cout << setw(4) << setprecision(2) << student[i] -> getCGPA() << endl;

    }
    cout << "--------------------------------------------------" << endl;

}

//Extract the 3 digits at the end of the Lecturer ID and convert it to integer
//So that they can be compared and sorted more easily
int Lecturer :: convertIDToInteger(){

    int id = stoi(lecturerID.substr(2, 3));
    return id;
}

//Return the student class array by pointer
Student** Lecturer :: getStudents(){

    return student;
}
