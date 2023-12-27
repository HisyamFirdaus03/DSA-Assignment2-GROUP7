#pragma once
#include <string>
using namespace std;

class Subject{

    private:
        string name, code;
        int credit;

    public:
        Subject(string name = "", string code = "", int credit = 0);

        void setName(string name);

        void setCode(string code);

        void setCredit(int credit);

        string getName() const;

        string getCode() const;

        int getCredit() const;

        int convertCodeToInteger();
};