#include <iostream>
using namespace std;
#include "Aircrew.h"

// base constructor  //initorder.cpp
// give the protected variables starting values
Aircrew::Aircrew(std::string name_str) : nm(name_str), flightsTaken(0), hoursWorked(0.0) {}

// destructor
Aircrew::~Aircrew(void) {}

// base class does not know the type
// derived class overrides type()
// const std::string Aircrew::type(void)const; //pure virtual
//{
// no implementation needed because derived classes will overide
//}

// const int Aircrew::maxFlights(void) const;  //pure virtual
//{ // a virtual function
//  A pure virtual function returning the maximum number of flights a crew member can work on
//  per week.
//}
const double Aircrew::maxHours(void) const
{
    // A member function returning the maximum number of hours a crew member can work per week.
    return 60.0;
}
const std::string Aircrew::name(void) const
{
    // A member function returning the name of the aircrew.
    return nm;
}
void Aircrew::setFlights(int i) // i is a parameter passed to the functions
{
    // A member function used to set the number of flights worked.
    flightsTaken = i; // flightsTaken was protected
}
void Aircrew::setHours(double h)
{
    // A member function used to set the current number of hours worked.
    hoursWorked = h;
}
void Aircrew::print(void) const
{
    // A member function that prints the description of the aircrew on standard output (see first part of
    // the above example).
    // cout <<  type << nm << "has operated" << flightsTaken << "flights for a total of" << hoursWorked << "this week" <<endl; WRONg
    cout << type() << ": " << nm << " has operated " << flightsTaken << " flights for a total of " << hoursWorked << " hours this week" << endl;
    cout << "Available flights: " << this->maxFlights() - flightsTaken << endl;
    cout << "Available hours: " << this->maxHours() - hoursWorked << endl;
}
void Aircrew::scheduleFlight(int i, double h) const // i assume i is the number of stops
{
    // A member function that prints whether the aircrew can be scheduled for the flight specified or
    // not on standard output (see above example, starting from the line “Attempting to
    // schedule...”).
    // This function only checks and reports whether the crew member can be sheduled for that flight
    // based on their current workload and limits

    cout << "Attempting to schedule for " << i << " stop(s) " << h << " hours flight..." << endl;
    // check if intended fights number + flightsTaken <= maxFlights && intended hours number + hoursworked <= maxHours
    if ((((i + 1) + flightsTaken) <= maxFlights()) && (hoursWorked + h) <= maxHours())
    { // i + 1 because 1 flight = 0 stops, 2 flights = 1 stop
        cout << "This crew member can be scheduled" << endl;
        cout << "Done scheduling " << nm << endl;
    }
    else
    {
        cout << "This crew member should be replaced" << endl;
        cout << "Done scheduling " << nm << endl;
    }
}
Aircrew *Aircrew::makeAircrew(char ch, std::string name_str) // a static factory function, no stastic keyword
{
    // if ch is 'P', a pilot must be created.
    if (ch == 'P')
    {
        Aircrew *crew = new Pilot(name_str);
        return crew;
    }
    // if ch is 'A', an attendant must be created.
    if (ch == 'A')
    {
        Aircrew *crew = new Attendant(name_str);
        return crew;
    }
    // if ch is 'T', a taggedAttendant must be created
    if (ch == 'T')
    {
        Aircrew *crew = new TaggedAttendant(name_str);
        return crew;
    }
    else
    {
        return nullptr;
    }
}

// derived classes
// each derived class inherits all of aircrew's data members
//-rm, flightsTaken, hoursWorked
// and all the member functions

// ony need to implement pure virtual functions

// pilot
Pilot::Pilot(std::string name_str) : Aircrew(name_str) {}
const std::string Pilot::type(void) const
{ // it is returning a string that describes type
    return "Pilot";
}
const int Pilot::maxFlights(void) const
{
    return 5;
}
// attendant
Attendant::Attendant(std::string name_str) : Aircrew(name_str) {} // Aircrew is part of attendant's initializer list.
const std::string Attendant::type(void) const
{
    return "Attendant";
}
const int Attendant::maxFlights(void) const
{
    return 8;
}
// tagged attendant
TaggedAttendant::TaggedAttendant(std::string name_str) : Aircrew(name_str) {}
const std::string TaggedAttendant::type(void) const
{
    return "TaggedAttendant";
}
const int TaggedAttendant::maxFlights(void) const
{
    return 8;
}
void TaggedAttendant::scheduleFlight(int f, double h) const
{
    cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << endl;
    // check if intended fights number + flightsTaken <= maxFlights && intended hours number + hoursworked <= maxHours
    double adjustedHours = h / 2.0;
    if ((((f + 1) + flightsTaken) <= maxFlights()) && (hoursWorked + adjustedHours) <= maxHours())
    { // i + 1 because 1 flight = 0 stops, 2 flights = 1 stop
        cout << "This crew member can be scheduled" << endl;
        cout << "Done scheduling " << nm << endl;
    }
    else
    {
        cout << "This crew member should be replaced" << endl;
        cout << "Done scheduling " << nm << endl;
    }
}