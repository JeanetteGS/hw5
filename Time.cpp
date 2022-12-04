#include "Time.h"

Time::Time(){
    event_time = "no time";
}
Time::Time(string e){
    event_time = e;
}
string Time::getE(){
    return event_time;
}
Json::Value Time::dump2JSON(){
    Json::Value result;
    if(this->event_time != ""){
        result = this->event_time;
    }
    return result;
} 