// Specification file for the Object class
// Modified by: Aman Grewal
// IDE: xCode

#ifndef Object_H
#define Object_H

using std::string;
using std::ostream;

class Object;

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const Object &);

class Object
{
private:
    char value;
    bool checked;

public:
    Object() {value = '\0'; checked = false;}  // Constructor
    Object(char v, bool s) // Overloaded Constructor
    {
        value = v;
        checked = s;
    }

    // Setters and getters
    void setValue(char v) {value = v;}
    void setChecked(bool c) {checked = c;}


    char getValue() const {return value;}
    bool getChecked() const {return checked;}

};




#endif
