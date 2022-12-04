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

class Time {
    //will include once upon a time, one day, after entering woods
private:
    string event_time;
public:
    Time();
    Time(string e);
    string getE();
    Time &operator= (const Time &copy){
        event_time = copy.event_time;
        return *this;
    }
    Json::Value dump2JSON();
};