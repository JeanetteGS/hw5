#include "Location.h"

Location::Location(){
    place = "noLocation";
}
Location::Location(string p){
    place = p;
}
string Location::getPlace(){
    return place;
}
Json::Value Location::dump2JSON(){
    Json::Value result;
    if(this->place != ""){
        result = this->place;
    }
    return result;
}