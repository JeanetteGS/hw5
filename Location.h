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

class Location {
//will include woods(wolf meeting), Grandma house, half a league from village 
private:
    string place;
public:
    Location();
    Location(string p);
    string getPlace();
    Location &operator= (const Location &copy){
        place = copy.place;
        return *this;
    }
    Json::Value dump2JSON();
};