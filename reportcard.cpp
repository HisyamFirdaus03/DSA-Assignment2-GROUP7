#include "src\reportcard.hpp"
#include "src\sortingsearch.hpp"
#include <iostream>
#include <iomanip>

ReportCard :: ReportCard(){

    subjectCount = 0;
}

int ReportCard :: getSubjectCount() const{
    
    return subjectCount;
}

int ReportCard :: calculateTotalCredit(){

    int totalCredit = 0;
    for(int i = 0; i < subjectCount; i++){

        totalCredit += subject[i] -> getCredit();
    }

    return totalCredit;
}

//Improved Selection Sort
void ReportCard :: displaySubject(){

    int credit[subjectCount];
    for(int i = 0; i < subjectCount; i++){

        credit[i] = subject[i] -> getCredit();
    }

    improvedSelectionSort<Subject*, int>(subject, subjectCount, credit);

    cout << left;
    cout << "--------------------------------------------------" << endl;
    cout << setw(4) << "No." << setw(30) << "Subject Name" << setw(12) << "Code";
    cout << setw(4) << "Credit" << endl;
    cout << "--------------------------------------------------" << endl;
    for(int i = 0; i < subjectCount; i++){
        
        cout << left;
        cout << setw(4) << i + 1 << setw(30) << subject[i] -> getName() << " ";
        cout << setw(12)  << subject[i] -> getCode() << "  ";
        cout << setw(4) << subject[i] -> getCredit() << "  ";
        cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Total Credit : " << calculateTotalCredit() << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

}

//Improved Selection Sort is implemented to sort the grade list according to the grades
void ReportCard :: displayGradeList(){

    improvedSelectionSort<Subject*, int>(subject, subjectCount, subjectMark);

    cout << left;
    cout << "--------------------------------------------------" << endl;
    cout << setw(4) << "No." << setw(30) << "Subject Name" << setw(4) << "Grade";
    cout << setw(4) << "Credit" << endl;
    cout << "--------------------------------------------------" << endl;
    for(int i = 0; i < subjectCount; i++){

        cout << setw(4) << i + 1 << setw(30) << subject[i] -> getName() << " ";
        cout << setw(4) << determineGrade(subjectMark[i]) << "  ";
        cout << setw(4) << subject[i] -> getCredit() << "  ";
        cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Total Credit : " << calculateTotalCredit() << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

}

//Improved Selection Sort is implemented to sort the report card according to the student's CGPA
void ReportCard :: displayReportCard(){

    improvedSelectionSort<Subject*, int>(subject, subjectCount, subjectMark);

    cout << left << fixed;
    cout << "--------------------------------------------------" << endl;
    cout << setw(4) << "No." << setw(16) << "Subject Name" << setw(10) << "Grade";
    cout << setw(10) << "Pointer" << setw(8) << "Credit" << endl;
    cout << "--------------------------------------------------" << endl;
    for(int i = 0; i < subjectCount; i++){

        cout << setw(4) << i + 1 << "  " << setw(16) << subject[i] -> getName();
        cout << setw(6) << determineGrade(subjectMark[i]) << "  ";
        cout << setw(10) << setprecision(2) << determineSubjectPointer(subjectMark[i]);
        cout << setw(8) << setprecision(2) << subject[i] -> getCredit();
        cout << endl;
    }
    cout << left;
    cout << "--------------------------------------------------" << endl;
    cout << setw(16) << setprecision(0) << "Total Credit" << ": " << calculateTotalCredit() << endl;
    cout << setw(16) << setprecision(2) << "CGPA" << ": " << calculateCGPA() << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;
}//sort

string ReportCard :: determineGrade(int mark){

    if(mark >= 90) return "A+";
    if(mark >= 80) return "A";
    if(mark >= 75) return "A-";
    if(mark >= 70) return "B+";
    if(mark >= 65) return "B";
    if(mark >= 60) return "B-";
    if(mark >= 55) return "C+";
    if(mark >= 50) return "C";
    if(mark >= 45) return "C-";
    if(mark >= 40) return "D+";
    if(mark >= 35) return "D";
    if(mark >= 30) return "D-";
    return "E";
}

double ReportCard :: determineSubjectPointer(int mark){

    if(mark >= 80) return 4.00;
    if(mark >= 75) return 3.67;
    if(mark >= 70) return 3.33;
    if(mark >= 65) return 3.00;
    if(mark >= 60) return 2.67;
    if(mark >= 55) return 2.33;
    if(mark >= 50) return 2.00;
    if(mark >= 45) return 1.67;
    if(mark >= 40) return 1.33;
    if(mark >= 35) return 1.00;
    if(mark >= 30) return 0.67;
    return 0.00;
}

//Calculate the total CGPA by summing the subject pointers
//and divide it by the total number of subjects taken by the student.
double ReportCard :: calculateCGPA(){

    double sumPointer = 0;

    if(subjectCount == 0)
        return 0;

    for(int i = 0; i < subjectCount; i++){

        sumPointer += determineSubjectPointer(subjectMark[i]);

    }

    return sumPointer / subjectCount;
}

void ReportCard :: addSubject(Subject *sub){
    
    //Check whether there the entered subject already exist 
    //If yes, then the function terminates without adding another duplicate.
    //Otherwise the function will add the new subject.
    for(int i = 0; i < subjectCount; i++){

        if(subject[i] == sub) return;
    }

    subject[subjectCount] = sub;
    subjectMark[subjectCount] = 0;
    subjectCount++;
}

//Binary Search is implemented to find the index of the subject to insert the mark based on its corresponding subject
void ReportCard :: addMark(int mark, string code){

    string subjectCode[subjectCount];
    for(int i = 0; i < subjectCount; i++){

        subjectCode[i] = subject[i] -> getCode();
    }

    int index = binarySearch<string>(subjectCode, code, subjectCount);
    subjectMark[index] = mark;
}

//Return the subject class array by pointer
Subject** ReportCard :: getSubjects(){

    return subject;
}
