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

class Thing {
//will include cap, wine, piece of cake
private:
    string thingname;
    bool isThing;
public:
    Thing();
    Thing(string name);
    Thing &operator= (const Thing &copy) {
        thingname = copy.thingname;
        isThing = copy.isThing;
        return *this;
    }
    bool getBool();
    string getName();
    Json::Value dump2JSON();
};