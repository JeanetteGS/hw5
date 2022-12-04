#include "Record.h"
#include "ecs36b_Common.h" 
#include "ecs36b_Exception.h" 
#include <fstream>

using namespace std; 

int main(){
    Record record1;
    Record record2;
    Record record3;
    Record record4;
    int thing_num = 0;
    int p_num = 0;

    //Record 1:   
    Time time1("Once Upon a Time");
    record1.setTime(time1);
    Person person1("Little Red Riding Hood", "Dear Little Girl");
    p_num++;
    record1.setPerson(person1, p_num);
    Thing thing1("Red Velvet Cap");
    thing_num++;
    record1.setThing(thing1, thing_num);
    cout << (record1.dump2JSON()).toStyledString()<< endl;

    //Record 2:
    thing_num = 0;
    p_num = 0;
    Time time2("One Day");
    record2.setTime(time2);
    Location location2("Little Red Riding Hood's House");
    record2.setLocation(location2);
    Person person2("Mother", " of little red riding hood");
    p_num++;
    record2.setPerson(person2, p_num);
    Thing thing2_1("piece of cake");
    thing_num++;
    record2.setThing(thing2_1, thing_num);
    Thing thing2_2("bottle of wine");
    thing_num++;
    record2.setThing(thing2_2, thing_num);
    cout << (record2.dump2JSON()).toStyledString() << endl; 

    //Record 3:
    thing_num = 0;
    p_num = 0;
    Time time3("After Entering the Woods");
    record3.setTime(time3);
    Location location3("Spot in the Woods");
    record3.setLocation(location3);
    Person person3("Wolf", "Wicked Creature");
    p_num++;
    record3.setPerson(person3, p_num);
    p_num++;
    record3.setPerson(person1, p_num);
    cout << (record3.dump2JSON()).toStyledString() << endl;

    //Record 4:
    thing_num = 0;
    p_num = 0;
    Time time4("After Wolf Meetup");
    record4.setTime(time4);
    Location location4("Under three large oak trees in woods");
    record4.setLocation(location4);
    Person person4("Grandmother", "Ill and Weak");
    p_num++;
    record4.setPerson(person4, p_num);
    cout << (record4.dump2JSON()).toStyledString() << endl;

    char f1_name[] = "Record1.json";
    char f2_name[] = "Record2.json";
    char f3_name[] = "Record3.json";
    char f4_name[] = "Record4.json";

    Json::Value e1 = record1.dump2JSON();
    Json::Value e2 = record2.dump2JSON();
    Json::Value e3 = record3.dump2JSON();
    Json::Value e4 = record4.dump2JSON();

    Json::Value r1;
    Json::Value r2;
    Json::Value r3;
    Json::Value r4;

    myJSON2File(f1_name, &e1);
    myJSON2File(f2_name, &e2);
    myJSON2File(f3_name, &e3);
    myJSON2File(f4_name, &e4);
    
    myFile2JSON(f1_name, &r1);
    myFile2JSON(f2_name, &r2);
    myFile2JSON(f3_name, &r3);
    myFile2JSON(f4_name, &r4); 

    record1.JSON2Object(r1);
    record2.JSON2Object(r2);
    record3.JSON2Object(r3);
    record4.JSON2Object(r4); 

    cout << r1.toStyledString() << endl; 
    cout << r2.toStyledString() << endl;
    cout << r3.toStyledString() << endl;
    cout << r4.toStyledString() << endl;
}