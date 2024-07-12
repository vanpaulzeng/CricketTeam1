//
//  main.cpp
//  CricketTeam
//
//  Created by Admin on 2024-07-10.
//

#include <iostream>
#include <string>
#include "CricketTeam.h"

using namespace std;

int main(int argc, const char * argv[]) {


    CricketTeam rajasthanRoyals;
    rajasthanRoyals.addCricketer ("Sanju", "Samson", 11);
    rajasthanRoyals.addCricketer ("Jos", "Buttler", 63);
    rajasthanRoyals.addCricketer ("Yashavi", "Jaiswal", 19);
    rajasthanRoyals.addCricketer ("Shimron", "Hetmeyer", 189);
    rajasthanRoyals.addCricketer ("Trent", "Boult", 18);
    rajasthanRoyals.addCricketer ("Ravichandran", "Ashwin", 99);
    rajasthanRoyals.addCricketer ("Yuzvendra", "Chahal", 3);
    
    rajasthanRoyals.printCricket();
    
    cout << rajasthanRoyals.cricketerCount();
    
    /*
    for (int n = 0; n < rajasthanRoyals.cricketerCount(); n++)
    {
    string first;
    string last;
        
    //    cout << rajasthanRoyals.
        
    int val;
    //rajasthanRoyals.checkTeamForCricketer (n, first, last, val);
    //cout << first << " " << last << " " << val << endl;
    }
*/














    return 0;
}
