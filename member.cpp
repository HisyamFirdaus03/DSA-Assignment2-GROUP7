#include "src\member.hpp"

Member :: Member(string name, University *uni){

    this -> name = name;
    this -> uni = uni;
}

Member :: ~Member(){

    this -> uni = nullptr;
}

void Member :: setName(string name){

    this -> name = name;
}

void Member :: setUni(University *uni){

    this -> uni = uni;
}

string Member :: getName() const{

    return name;
}

string Member :: getUniName() const{

    if(uni == nullptr)
        return "";

    return uni -> getName();
}

string Member :: getCurrentSem() const{

    if(uni == nullptr)
        return "";

    return uni -> getCurrentSem();
}
