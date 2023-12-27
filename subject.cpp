#include "src\subject.hpp"

Subject :: Subject(string name, string code, int credit){

    this -> name = name;
    this -> code = code;
    this -> credit = credit;
}

void Subject :: setName(string name){

    this -> name = name;
}

void Subject :: setCode(string code){

    this -> code = code;
}

void Subject :: setCredit(int credit){

    this -> credit = credit;
}

string Subject :: getName() const{

    return name;
}

string Subject :: getCode() const{

    return code;
}

int Subject :: getCredit() const{

    return credit;
}

int Subject :: convertCodeToInteger(){

    int iCode = stoi(code.substr(4, 4));
    return iCode;
}

