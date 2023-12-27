#include "src\university.hpp"

University :: University(string name){

    this -> name = name;
}

void University :: setName(string name){

    this -> name = name;
}

void University :: setCurrentSem(string currentSem){

    this -> currentSem = currentSem;
}

string University :: getName() const{

    return name;
}

string University :: getCurrentSem() const{

    return currentSem;
}