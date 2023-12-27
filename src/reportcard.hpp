#pragma once
#include "subject.hpp"
#include <string>
using namespace std;

#define MAX_SUBJECT 10

class ReportCard{

    private:
        Subject *subject[MAX_SUBJECT];
        int subjectMark[MAX_SUBJECT];
        int subjectCount;

    public:
        ReportCard();

        int getSubjectCount() const;

        int calculateTotalCredit();

        void displaySubject();

        void displayGradeList();

        void displayReportCard();

        string determineGrade(int mark);

        double determineSubjectPointer(int mark);

        double calculateCGPA();

        void addSubject(Subject *sub);

        void addMark(int mark, string code);

        Subject** getSubjects();
};