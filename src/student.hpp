#pragma once
#include "member.hpp"
#include "reportcard.hpp"

class Student : public Member{

    private:
        string matricNo, course;
        ReportCard reportCard;

    public:
        Student* next;
        
        Student(string name = "", string matricNo = "", string course = "", University *uni = nullptr);

        void setMatricNo(string matricNo);

        void setCourse(string course);

        string getMatricNo() const;

        string getCourse() const;

        int getSubjectCount() const;

        int convertMatricToInteger();

        double getCGPA();

        void addSubject(Subject *sub);

        void addMark(int mark, string code);

        void displaySubject();

        void displayGradeList();

        void displayReportCard();

        Subject** getSubjects();
};
