#include "Person.h"

Person::Person() {
    name = "Dummy";
    description = "Dummy Description";
    isPerson = false;
}
Person::Person(string n, string d){
    name = n;
    description = d;
    isPerson = true;
}
void Person::setName(string n){
    name = n;
}
void Person::setDescription(string d){
    description = d; 
}
string Person::getName(){
    return name;
}
string Person::getDescription(){
    return description;
}
bool Person::getisPerson(){
    return isPerson;
}
Json::Value Person::dump2JSON(){
    Json::Value result;
    if (this->isPerson)
    {
      result["Name"] = this->name;
      result["Description"] = this->description;
    }
    return result; 
}