#include "src\student.hpp"
#include <iostream>
#include <iomanip>

Student :: Student(string name, string matricNo, string course, University *uni) : Member(name, uni){

    this -> matricNo = matricNo;
    this -> course = course;
    next = nullptr;
}

void Student :: setMatricNo(string matricNo){

    this -> matricNo = matricNo;
}

void Student :: setCourse(string course){

    this -> course = course;
}

string Student :: getMatricNo() const{

    return matricNo;
}

string Student :: getCourse() const{

    return course;
}

int Student :: getSubjectCount() const{

    return reportCard.getSubjectCount();
}

//Extract the 4 digits at the end of the Matric No. and convert it to integer
//So that they can be compared and sorted more easily
int Student :: convertMatricToInteger(){

    int matric = stoi(matricNo.substr(6, 4));

    return matric;
}

double Student :: getCGPA(){

    return reportCard.calculateCGPA();
}

void Student :: addSubject(Subject *sub){

    reportCard.addSubject(sub);
}

void Student :: addMark(int mark, string code){

    reportCard.addMark(mark, code);
}

void Student :: displaySubject(){

    cout << endl;
    cout << left;
    cout << setw(16) << "Name" << ": " << getName() << endl;
    cout << setw(16) << "Matric No." << ": " << matricNo << endl;
    reportCard.displaySubject();
}

void Student :: displayGradeList(){

    cout << endl;
    cout << left;
    cout << setw(16) << "Name" << ": " << getName() << endl;
    cout << setw(16) << "Matric No." << ": " << matricNo << endl;
    reportCard.displayGradeList();
}

void Student :: displayReportCard(){

    cout << endl;
    cout << left;
    cout << setw(16) << "Name" << ": " << getName() << endl;
    cout << setw(16) << "Matric No." << ": " << matricNo << endl;
    reportCard.displayReportCard();
}

//Return the subject class array by pointer
Subject** Student :: getSubjects(){

    return reportCard.getSubjects();
}

