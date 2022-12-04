#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <string>

#include "json/json.h"
#include "json/reader.h"
#include "json/writer.h"
#include "json/value.h"

#include "Person.h"
#include "Thing.h"
#include "Location.h"
#include "Time.h" 

using namespace std;

class Record { //will take four objects(Person, Thing, thing, location, Time)
private:
    Person people[3];
    Thing things[3];
    Location place;
    Time time;
public:
    void setPerson(Person p, int p_num);
    void setThing(Thing thing, int thing_num);
    void setLocation(Location pl);
    void setTime(Time t);
    Json::Value dump2JSON(); 
    bool JSON2Object(Json::Value arg_jv); 
};