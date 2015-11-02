#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Vehicle {
protected :
    string license ;
    int year ;
public :
    Vehicle ( const string & myLicense , const int myYear )
        :license ( myLicense ), year ( myYear ) {}
    virtual const string getDesc () = 0;
    const string & getLicense () const { return license ;}
    const int getYear () const { return year ;}
};
class car : public Vehicle{
    string style;
public:
    car( const string & myLicense , const int myYear , const string & myStyle )
         :Vehicle(myLicense, myYear), style(myStyle){}
    const string &getStyle() {return style;}
    string years = std::to_string(year);
    const string getDesc() {return license; return years;}

} ;

