#pragma once
#include <string>
using namespace std;

class University{

    private:
        string name, currentSem;

    public:
        University(string name = "");

        void setName(string name);

        void setCurrentSem(string currentSem);

        string getName() const;

        string getCurrentSem() const;
};