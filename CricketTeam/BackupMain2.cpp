//
//  main.cpp
//  CricketTeam
//
//  Created by Admin on 2024-07-10.
//

#include <iostream>
#include <string>
#include "CricketTeam.h"
#include <type_traits>
#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }



using namespace std;



// Edwin's final test case

static_assert(std::is_default_constructible<CricketTeam>::value, "Map must be default-constructible.");
static_assert(std::is_copy_constructible<CricketTeam>::value,
"Map must be copy-constructible.");
void ThisFunctionWillNeverBeCalled() {
CHECKTYPE(&CricketTeam::operator=, CricketTeam&
(CricketTeam::*)(const CricketTeam&));
CHECKTYPE(&CricketTeam::noTeam, bool
(CricketTeam::*)() const);
CHECKTYPE(&CricketTeam::cricketerCount, int
(CricketTeam::*)() const);
CHECKTYPE(&CricketTeam::addCricketer, bool (CricketTeam::*)
(const std::string&, const std::string&, const CricketType&));
CHECKTYPE(&CricketTeam::substituteCricketer, bool
(CricketTeam::*)(const std::string&, const std::string&,
const CricketType&));
CHECKTYPE(&CricketTeam::addOrSubstitute, bool

(CricketTeam::*)(const std::string&, const std::string&,
const CricketType&));
CHECKTYPE(&CricketTeam::releaseCricketer, bool (CricketTeam::*)
(const std::string&, const std::string&));
CHECKTYPE(&CricketTeam::rosteredOnCricketTeam, bool
(CricketTeam::*)(const std::string&, const std::string&)
const);
CHECKTYPE(&CricketTeam::searchForCricketer, bool (CricketTeam::*)
(const std::string&, const std::string&, CricketType&) const);
CHECKTYPE(&CricketTeam::checkTeamForCricketer, bool (CricketTeam::*)
(int, std::string&, std::string&, CricketType&)
const);
CHECKTYPE(&CricketTeam::tradeCricketTeams, void
(CricketTeam::*)(CricketTeam&));
CHECKTYPE(mergeCricketers, bool (*)(const CricketTeam&, const
CricketTeam&, CricketTeam&));
CHECKTYPE(checkCricketers, void (*)(const std::string&,
const std::string&, const CricketTeam&, CricketTeam&));
}
//int main2() {}



#include "CricketTeam.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void test() {
CricketTeam pakistanCricket;
assert(pakistanCricket.addCricketer("Mohammad", "Rizwan",
"mohammadr@pakistancricket.com"));
assert(pakistanCricket.addCricketer("Babar", "Azam",
"babara@pakistancricket.com"));

    pakistanCricket.printCricket();
    
    
assert(pakistanCricket.cricketerCount() == 2);
string first, last, e;
assert(pakistanCricket.checkTeamForCricketer(0, first, last, e) && e == "babara@pakistancricket.com");
assert(pakistanCricket.checkTeamForCricketer(1, first, last, e) && (first == "Mohammad" && e == "mohammadr@pakistancricket.com"));
return;
}
int main2() {
test();
cout << "Passed all tests" << endl;
return 0;
}





