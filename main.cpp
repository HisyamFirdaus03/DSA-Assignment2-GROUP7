//-----------------------------------------------------------------
//TITLE: ASSIGNMENT 2 | DATA STRUCTURE AND ALGORITHM
//ADDITION: IMPLEMENTED LINKED LIST INTO THE PROGRAM
//SYSTEM: STUDENT MANAGEMENT SYSTEM
//GROUP: 07
//SECTION: 10
//GROUP MEMBERS: 1. HISYAMUDDIN FIRDAUS BIN HAMZAH | A22EC0167
//               2. NAQIB AZIM BIN SHAUN           | A22EC0090
//-----------------------------------------------------------------              
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "src\student.hpp"
#include "src\subject.hpp"
#include "src\lecturer.hpp"
#include "src\university.hpp"
#include "src\sortingsearch.hpp"
#include "src\studentList.hpp"
#include "src\lecturerList.hpp"
using namespace std;

//Array Size
#define SUBJECT_COUNT 5
#define LECTURER_COUNT 3
#define STUDENT_COUNT 7

//Input and Output File Destination
#define LECTURER_FILE "inputFile/fileLecturers.txt"
#define SUBJECT_FILE "inputFile/fileSubjects.txt"
#define STUDENT_FILE "inputFile/fileStudents.txt"
#define OUTPUT_FILE "outputFile/fileOutput.txt"

//Function Declaration
void readFile(Lecturer *lect[], Subject *sub[], Student *stu[], int &lectCount, int &subCount, int &stuCount);
void writeFile(Lecturer *lect[], Subject *sub[], Student *stu[], int lectCount, int subCount, int stuCount);
void displayStudentMenu(Student &stu);
void processStudentMenu(int input, Student &stu, Subject *subject[], int subjectCount, bool &isFinished);
void displayLecturerMenu(Lecturer &lect);
void processLecturerMenu(int input, Lecturer &lect, bool &isFinished);
void displayAvailableSubject(Subject *subject[], int subjectCount);
void displayEntranceMenu();
int userInput();
void extractMatricNo(Student *stud[], int studentMatricNo[], int stuCount);
void extractLecturerID(Lecturer *lect[], int lecturerID[], int lectCount);
void insertStudentToList(Student *stud[], StudentList &list, int stuCount);
void insertLecturerToList(Lecturer *lect[], LecturerList &list, int lectCount);

template <typename T>
T getUserKey(string message);

template <class T>
int searchUser(T arr[], int key, int size, int compare[]);

template <class T>
int searchSubject(T arr[], int key, int size, int compare[]);


int main(){

    Lecturer *userLect;
    Lecturer *lect[LECTURER_COUNT];

    Student *userStu;
    Student *stud[STUDENT_COUNT];

    Subject *subject[SUBJECT_COUNT];

    int lectCount = 0, subCount = 0, stuCount = 0;

    readFile(lect, subject, stud, lectCount, subCount, stuCount);

    int studentMatricNo[stuCount];
    int lecturerID[lectCount];
    //Extract Matric No and convert it into integer
    extractMatricNo(stud, studentMatricNo, stuCount);
    //Extract Lecturer ID and convert it into integer
    extractLecturerID(lect, lecturerID, lectCount);


    //Created linked list for lecturer and student object
    LecturerList lectList;
    StudentList stuList;

    //Insert the Student, Lecturer and Subject Node into the List
    //By Implementing the Linked List
    insertStudentToList(stud, stuList, stuCount);
    insertLecturerToList(lect, lectList, lectCount);

    //Display a list of students and lecturers
    cout << endl;
    stuList.listAllStudents();
    cout << endl;
    lectList.listAllLecturers();
    cout << endl;


    int select, index;
    bool isFinished = false, isUserFound = false;
    string userKey;
    while(!isUserFound){

        displayEntranceMenu();
        select = userInput();
        switch(select){
            case 1:
                userKey = getUserKey<string>("Enter your Matric No.: ");
                if(userKey.length() != 9){

                    userKey = "";
                    cout << "Invalid Matric No. Format! " << endl;
                    break;
                }
                index = searchUser<Student*>(stud, stoi(userKey.substr(5, 4)), stuCount, studentMatricNo);
                if(index < 0){

                    userKey = "";
                    cout << "Invalid Matric No.!" << endl;
                    break;
                }
                userStu = stud[index];
                isUserFound = true;
                break;

            case 2:
                userKey = getUserKey<string>("Enter your Lecturer ID: ");
                if(userKey.length() != 5){

                    userKey = "";
                    cout << "Invalid Lecturer ID. Format!" << endl;
                    break;
                }
                index = searchUser<Lecturer*>(lect, stoi(userKey.substr(2, 3)), lectCount, lecturerID);
                if(index < 0){

                    userKey = "";
                    cout << "Invalid Lecturer ID.!" << endl;
                    break;
                }
                userLect = lect[index];
                isUserFound = true;
                break;

            case 3:
                isUserFound = true;
                break;
                
            default:
                cout << "You entered an invalid input!" << endl;
                break;
        }
    }

    int userSelection;
    while(!isFinished){

        switch(select){
            case 1:
                displayStudentMenu(*userStu);
                userSelection = userInput();
                processStudentMenu(userSelection, *userStu, subject, subCount, isFinished);
                break;

            case 2:
                displayLecturerMenu(*userLect);
                userSelection = userInput();
                processLecturerMenu(userSelection, *userLect, isFinished);
                break;
            
            default:
                isFinished = true;
                break;
        }
    }

    writeFile(lect, subject, stud, lectCount, subCount, stuCount);

    //Clear all the heap memories created
    for(int i = 0; i < subCount; i++){

        delete subject[i];
    }
    
    system("pause");
    return 0;
}


void readFile(Lecturer *lect[], Subject *sub[], Student *stu[], int &lectCount, int &subCount, int &stuCount){

    string buffer;

    ifstream inputLecturerFile(LECTURER_FILE);
    getline(inputLecturerFile, buffer);
    for(int i = 0; !inputLecturerFile.eof(); i++){

        string name, lecturerID, faculty;
        inputLecturerFile >> name >> lecturerID >> faculty;
        lect[i] = new Lecturer(name, lecturerID, faculty);
        lectCount++;
    }
    inputLecturerFile.close();

    ifstream inputSubjectFile(SUBJECT_FILE);
    getline(inputSubjectFile, buffer);
    for(int i = 0; !inputSubjectFile.eof(); i++){

        string name, code;
        int credit;
        inputSubjectFile >> name >> code >> credit;
        sub[i] = new Subject(name, code, credit);
        subCount++;
    }
    inputSubjectFile.close();

    //Extract the subject code and convert the last 4 digits into integer
    int iSubjectCode[subCount];
    for(int i = 0; i < subCount; i++){

        iSubjectCode[i] = sub[i] -> convertCodeToInteger();
    }

    //Extract the lecturer ID and convert the last 3 digits into integer
    int iLecturerID[lectCount];
    for(int i = 0; i < lectCount; i++){

        iLecturerID[i] = lect[i] -> convertIDToInteger();
    }

    ifstream inputStudentFile(STUDENT_FILE);
    getline(inputStudentFile, buffer);
    for(int i = 0; !inputStudentFile.eof(); i++){

        string name, matricNo, course, lecturerID, subjectCode;
        int subjectMark, lecturerIndex, subjectIndex;
        inputStudentFile >> name >> matricNo >> course >> lecturerID;
        stu[i] = new Student(name, matricNo, course);

        lecturerIndex = searchSubject<Lecturer*>(lect, stoi(lecturerID.substr(2, 3)), lectCount, iLecturerID);
        lect[lecturerIndex] -> addStudent(stu[i]);

        for(int j = 0; (inputStudentFile.peek() != '\n') && (!inputStudentFile.eof()); j++){

            inputStudentFile >> subjectCode >> subjectMark;
            subjectIndex = searchSubject<Subject*>(sub, stoi(subjectCode.substr(4, 4)), subCount, iSubjectCode);
            stu[i] -> addSubject(sub[subjectIndex]);
            stu[i] -> addMark(subjectMark, subjectCode);
        }
        stuCount++;
    }
    inputStudentFile.close();
}

void writeFile(Lecturer *lect[], Subject *sub[], Student *stu[], int lectCount, int subCount, int stuCount){

    double iStudentCGPA[stuCount];
    ofstream outputFile(OUTPUT_FILE);

    outputFile << left << fixed << setprecision(2);
    outputFile << "Lecturer: \n" 
               << setw(10) << "Name" 
               << setw(14) << "LecturerID" 
               << setw(10) << "Faculty" << endl;
    for(int i = 0; i < lectCount; i++){

        outputFile << setw(10) << lect[i] -> getName() 
                   << setw(14) << lect[i] -> getLecturerID() 
                   << setw(10) << lect[i] -> getFaculty() << endl;
    }
    outputFile << endl;

    //Extract student's CGPA and convert it to integer
    for(int i = 0; i < stuCount; i++){

        iStudentCGPA[i] = stu[i] -> getCGPA();
    }

    //Sort the students by CGPA
    improvedSelectionSort<Student*, double>(stu, stuCount, iStudentCGPA);

    outputFile << "Student: \n" 
               << setw(10) << "Name" 
               << setw(14) << "Matric No." 
               << setw(10) << "Course"
               << setw(10) << "CGPA" << endl;
    for(int i = 0; i < stuCount; i++){

        outputFile << setw(10) << stu[i] -> getName() 
                   << setw(14) << stu[i] -> getMatricNo() 
                   << setw(10) << stu[i] -> getCourse() 
                   << setw(10) << stu[i] -> getCGPA() << endl;
    }
    outputFile << endl;

    outputFile << "Subject: \n" 
               << setw(20) << "Name" 
               << setw(10) << "Code" 
               << setw(10) << "Credit" << endl;
    for(int i = 0; i < subCount; i++){

        outputFile << setw(20) << sub[i] -> getName() 
                   << setw(10) << sub[i] -> getCode() 
                   << setw(10) << sub[i] -> getCredit() << endl;
    }
    outputFile << endl;

    outputFile.close();
}

void displayEntranceMenu(){

    cout << endl;
    cout << "University's Student Management System" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Login as: " << endl;
    cout << "1. Student " << endl;
    cout << "2. Lecturer " << endl;
    cout << "3. Exit " << endl;
    cout << endl;
}

void displayStudentMenu(Student &stu){

    cout << endl;
    cout << "Welcome to the Student's Menu" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << left << fixed;
    cout << setw(16) << "Name" << ": " << stu.getName() << endl;
    cout << setw(16) << "Matric No." << ": " << stu.getMatricNo() << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Select functions below: " << endl;
    cout << "1. Display subjects " << endl;
    cout << "2. Display grade list " << endl;
    cout << "3. Display report card " << endl;
    cout << "4. Add subject " << endl;
    cout << "5. Exit " << endl;
    cout << endl;
}

void processStudentMenu(int input, Student &stu, Subject *subject[], int subjectCount, bool &isFinished){

    int userKey;
    Subject *addedSub;
    switch(input){

        case 1:
            stu.displaySubject();
            break;

        case 2:
            stu.displayGradeList();
            break;
        
        case 3:
            stu.displayReportCard();
            break;

        case 4:
            displayAvailableSubject(subject, subjectCount);
            userKey = getUserKey<int>("Enter the number that corresponds with the subject to be added: ");
            if(userKey < 1 || userKey > subjectCount){
                
                cout << "Invalid input number!" << endl;
                break;
            }
            addedSub = subject[userKey - 1];
            stu.addSubject(addedSub);
            break;

        case 5:
            isFinished = true;
            break;

        default:
            cout << "You entered an invalid input!" << endl;
            break;
    }
}

void displayLecturerMenu(Lecturer &lect){

    cout << endl;
    cout << "Welcome to the Lecturer's Menu" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << left << fixed;
    cout << setw(16) << "Name" << ": " << lect.getName() << endl;
    cout << setw(16) << "Lecturer ID" << ": " << lect.getLecturerID() << endl;
    cout << setw(16) << "Faculty" << ": " << lect.getFaculty() << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Select functions below: " << endl;
    cout << "1. List all students " << endl;
    cout << "2. Add student mark" << endl;
    cout << "3. Exit " << endl;
    cout << endl;
}

void processLecturerMenu(int input, Lecturer &lect, bool &isFinished){

    Subject **sub;
    Subject *selectedSubject;
    Student **stu = lect.getStudents();
    Student *selectedStudent;

    string userKey;
    int userSelection;
    int studentCount = lect.getStudentCount();
    int studentMatricNo[studentCount], index, addedMark, subjectCount;

    for(int i = 0; i < studentCount; i++){

        studentMatricNo[i] = stu[i] -> convertMatricToInteger();
    }

    switch(input){

        case 1:
            lect.listAllStudents();
            break;

        case 2:
            lect.listAllStudents();
            userKey = getUserKey<string>("Enter The Student's Matric No.: ");
            if(userKey.length() != 9){

                userKey = "";
                cout << "Invalid Matric No.!" << endl;
                break;
            }
            index = searchUser<Student*>(stu, stoi(userKey.substr(6, 4)), studentCount, studentMatricNo);
            if(index < 0){

                cout << "Invalid Matric No.!" << endl;
                break;
            }
            selectedStudent = stu[index];
            subjectCount = selectedStudent -> getSubjectCount();
            sub = selectedStudent -> getSubjects();

            selectedStudent -> displaySubject();
            userSelection = getUserKey<int>("Enter the number that corresponds with the subject to add the mark: ");
            if(userSelection < 0 || userSelection > subjectCount){
                
                cout << "Invalid input number!" << endl;
                break;
            }
            selectedSubject = sub[userSelection - 1];
            
            addedMark = getUserKey<int>("Enter the mark: ");
            if(addedMark < 0 || addedMark > 100){
                
                cout << "Invalid input number!" << endl;
                break;
            }
            selectedStudent -> addMark(addedMark, selectedSubject -> getCode());
            break;

        case 3:
            isFinished = true;
            break;

        default:
            cout << "You entered an invalid input!" << endl;
            break;
    }
}

int userInput(){

    int userInput;
    cout << "Enter your input : ";
    cin >> userInput;
    return userInput;
}

template <typename T>
T getUserKey(string message){

    T userKey;
    cout << message;
    cin >> userKey;
    return userKey;
}

//Implement Binary Search to search the user based on the key entered
//whether the user entered a lecturer ID for lecturer
//or a matric no for student
template <class T>
int searchUser(T arr[], int key, int size, int compare[]){
    
    improvedSelectionSort<T, int>(arr, size, compare);
    int index = binarySearch<int>(compare, key, size);
    return index;
}

//Implement Binary Search to search the subject based on the key entered
//The function require the user to enter the code of the subject and it will return the index of the subject
template <class T>
int searchSubject(T arr[], int key, int size, int compare[]){
    
    improvedSelectionSort<T, int>(arr, size, compare);
    int index = binarySearch<int>(compare, key, size);
    return index;
}

void displayAvailableSubject(Subject *subject[], int subjectCount){

    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << left << fixed;
    cout << "Available Subjects" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Select subjects below (Enter the number as the input): " << endl;
    for(int i = 0; i < subjectCount; i++){

        cout << setw(4) << i + 1;
        cout << setw(16) << subject[i] -> getName();
        cout << setw(4) << subject[i] -> getCode() << endl;
    }
    cout << endl;
}

void extractMatricNo(Student *stud[], int studentMatricNo[], int stuCount){
   
    for(int i = 0; i < stuCount; i++){

        studentMatricNo[i] = stud[i] -> convertMatricToInteger();
    }
}

void extractLecturerID(Lecturer *lect[], int lecturerID[], int lectCount){

    for(int i = 0; i < lectCount; i++){

        lecturerID[i] = lect[i] -> convertIDToInteger();
    }
}

void insertStudentToList(Student *stud[], StudentList &list, int stuCount){

    for(int i = 0; i < stuCount; i++){

        list.insertNode(stud[i]);
    }
}

void insertLecturerToList(Lecturer *lect[], LecturerList &list, int lectCount){

    for(int i = 0; i < lectCount; i++){

        list.insertNode(lect[i]);
    }
}



