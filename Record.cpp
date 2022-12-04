#include "Record.h"

void Record::setPerson(Person p, int p_num) {
    people[p_num -1] = p;
}        
void Record::setThing(Thing thing, int thing_num) {
    things[thing_num - 1] = thing;
}
void Record::setLocation(Location pl){
    place = pl;
}
void Record::setTime(Time t){
    time = t;
}
Json::Value Record::dump2JSON() {
    Json::Value result;
        
    if (people[0].getisPerson())
        result["Person 1"] = this-> people[0].dump2JSON();
    if (people[1].getisPerson())
        result["Person 2"] = this-> people[1].dump2JSON();
    if (people[2].getisPerson())
        result["Person 3"] = this-> people[2].dump2JSON();
    if (things[0].getBool())
        result["Item 1"] = this-> things[0].dump2JSON();
    if (things[1].getBool())
        result["Item 2"] = this-> things[1].dump2JSON();
    if (things[2].getBool())
        result["Item 3"] = this-> things[2].dump2JSON();
    result ["Location"] = this-> place.dump2JSON();
    result["When"] = this-> time.dump2JSON(); 
    return result;
}
bool Record::JSON2Object(Json::Value arg_jv){
    if(arg_jv != ""){
        return true;
    }
    return false;
}