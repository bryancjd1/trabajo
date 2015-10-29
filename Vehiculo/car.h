class Car : public Vehicle {
string style ;

public :
    Car( const string & myLicense , const int myYear , const string & myStyle )
        : Vehicle ( myLicense , myYear ), style ( myStyle ) {}
    const string getDesc ()
        {return stringify ( year ) + ’ ’ + style + ": " + license ;}
    const string & getStyle () { return style ;}
};
