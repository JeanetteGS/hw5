#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <string>

#include "json/json.h"
#include "json/reader.h"
#include "json/writer.h"
#include "json/value.h"

using namespace std; 

class Person {
    //will include Wolf, LRRH, Grandmother, mother
private:
    string name;
    string description;
    bool isPerson;
public:
    Person();
    Person(string n, string d);
    void setName(string n);
    void setDescription(string d);
    string getName();
    string getDescription();
    bool getisPerson();
    Person &operator= (const Person &copy) {
        name = copy.name;
        description = copy.description;
        isPerson = copy.isPerson;
        return *this;
    }
    Json::Value dump2JSON();    
};