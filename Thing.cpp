#include "Thing.h"

Thing::Thing(){
    thingname = "Nothing";
    isThing = false;
}
Thing::Thing(string name){
    thingname = name;
    isThing = true;
}
bool Thing::getBool(){
    return isThing;
}
string Thing::getName(){
    return thingname;
}
Json::Value Thing::dump2JSON(){
    Json::Value result;
    if(this->isThing){
        result = this->thingname;
    }
    return result; 
}