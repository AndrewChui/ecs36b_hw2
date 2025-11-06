//
// scheduling.cpp
//

#include "Aircrew.h"
#include <iostream>
using namespace std;

int main()
{
  char ch;
  string s;
  int f_done, f_sched;
  double h_done, h_sched;
  cin >> ch >> s >> f_done >> h_done >> f_sched >> h_sched;
  while (cin)
  {
    Aircrew *p = Aircrew::makeAircrew(ch,s);
    if (p != nullptr )
    {
      p->setFlights(f_done);
      p->setHours(h_done);

      p->print();
      p->scheduleFlight(f_sched, h_sched);
      delete p;
    }
    else
    {
      cout << "unknown aircrew type " << ch << endl;
    }
    cin >> ch >> s >> f_done >> h_done >> f_sched >> h_sched;
  }
}
