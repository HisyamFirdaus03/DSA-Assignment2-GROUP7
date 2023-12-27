#pragma once
#include "university.hpp"
#include <string>
using namespace std;

#define SIZE 10

class Member{

    private:
        University *uni;
        string name;

    public:
        Member(string name = "", University *uni = nullptr);

        ~Member();

        void setName(string name);

        void setUni(University *uni);

        string getName() const;

        string getUniName() const;

        string getCurrentSem() const;
};