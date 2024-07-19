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

int main(int argc, const char * argv[])
{
    
    
    /* Paul's own test case
     CricketTeam rajasthanRoyals;
     rajasthanRoyals.addCricketer ("Ravichandran", "Ashwin", 99);
     rajasthanRoyals.addCricketer ("Sanju", "Samson", 11);
     rajasthanRoyals.addCricketer ("Qavichandran", "Arhwin", 99);
     rajasthanRoyals.addCricketer ("Pavichandran", "Bvhwin", 99);
     rajasthanRoyals.addCricketer ("Qavichandran", "Ashwim", 98);
     rajasthanRoyals.addCricketer ("Jos", "Buttler", 63);
     rajasthanRoyals.addCricketer ("Yashavi", "Jaiswal", 19);
     rajasthanRoyals.addCricketer ("Shimron", "Hetmeyer", 189);
     rajasthanRoyals.addCricketer ("Trent", "Boult", 18);
     rajasthanRoyals.addCricketer ("Savichandran", "Ashwin", 99);
     rajasthanRoyals.addCricketer ("Yuzvendra", "Chahal", 3);
     
     
     rajasthanRoyals.addOrSubstitute("Qavichandran", "Ashwim", 100);
     rajasthanRoyals.substituteCricketer("Qavichandran", "Ashwim", 130);
     
     
     rajasthanRoyals.printCricket();
     
     cout << rajasthanRoyals.cricketerCount();
     
     return 0;
     
     
     */
    
    /*/ test 1 passed
     CricketTeam rajasthanRoyals;
     rajasthanRoyals.addCricketer ("Sanju", "Samson", 11);
     rajasthanRoyals.addCricketer ("Jos", "Buttler", 63);
     rajasthanRoyals.addCricketer ("Yashavi", "Jaiswal", 19);
     rajasthanRoyals.addCricketer ("Shimron", "Hetmeyer", 189);
     rajasthanRoyals.addCricketer ("Trent", "Boult", 18);
     rajasthanRoyals.addCricketer ("Ravichandran", "Ashwin", 99);
     rajasthanRoyals.addCricketer ("Yuzvendra", "Chahal", 3);
     
     //rajasthanRoyals.printCricket();
     //cout << rajasthanRoyals.cricketerCount() <<"   \n";
     
     for (int n = 0; n < rajasthanRoyals.cricketerCount(); n++)
     {
     string first;
     string last;
     int val;
     rajasthanRoyals.checkTeamForCricketer (n, first, last, val);
     cout << first << " " << last << " " << val << endl;
     }
     */
    
    
    /* test 2 passed
     CricketTeam mumbaiIndians;
     mumbaiIndians.addCricketer("Rohit", "Sharma", 36.25);
     mumbaiIndians.addCricketer("Suryakumar", "Yadav", 32.75);
     assert(!mumbaiIndians.rosteredOnCricketTeam ("",""));
     mumbaiIndians.addCricketer("Jasprit", "Bumrah", 29.5);
     mumbaiIndians.addCricketer("", "", 21.0);
     mumbaiIndians.addCricketer("Cameron", "Green", 24.0);
     mumbaiIndians.printCricket();
     
     
     assert(mumbaiIndians.rosteredOnCricketTeam ("", ""));
     mumbaiIndians.releaseCricketer("Jasprit", "Bumrah");
     assert(mumbaiIndians.cricketerCount() == 4
     && mumbaiIndians.rosteredOnCricketTeam("Rohit", "Sharma")
     && mumbaiIndians.rosteredOnCricketTeam ("Suryakumar", "Yadav")
     && mumbaiIndians.rosteredOnCricketTeam ("Cameron", "Green")
     && mumbaiIndians.rosteredOnCricketTeam ("", ""));
     
     */
    
    
    
    
    
    /*/ Test 3  passed
     CricketTeam mumbaiIndians;
     mumbaiIndians.addCricketer("Rohit", "Sharma", 36.25);
     mumbaiIndians.addCricketer("Suryakumar", "Yadav", 32.75);
     assert(!mumbaiIndians.rosteredOnCricketTeam ("",""));
     mumbaiIndians.addCricketer("Jasprit", "Bumrah", 29.5);
     mumbaiIndians.addCricketer("", "", 21.0);
     mumbaiIndians.addCricketer("Cameron", "Green", 24.0);
     assert(mumbaiIndians.rosteredOnCricketTeam ("", ""));
     mumbaiIndians.releaseCricketer("Jasprit", "Bumrah");
     assert(mumbaiIndians.cricketerCount() == 4 && mumbaiIndians.rosteredOnCricketTeam("Rohit", "Sharma") && mumbaiIndians.rosteredOnCricketTeam ("Suryakumar", "Yadav") && mumbaiIndians.rosteredOnCricketTeam ("Cameron","Green")
     && mumbaiIndians.rosteredOnCricketTeam ("", ""));
     //assert(mumbaiIndians.searchForCricketer ("Cameron", "Green", 26.0) == false);
     */
    
    
    /*/ Paul's Merge own test case
     CricketTeam rajasthanRoyals1;
     rajasthanRoyals1.addCricketer("Ravichandran", "Ashwin", 99);
     rajasthanRoyals1.addCricketer ("Sanju", "Samson", 11);
     rajasthanRoyals1.addCricketer ("Qavichandran", "Arhwin", 99);
     rajasthanRoyals1.addCricketer ("Pavichandran", "Bvhwin", 99);
     rajasthanRoyals1.addCricketer ("Qavichandran", "Ashwim", 98);
     rajasthanRoyals1.addCricketer ("Jos", "Buttler", 63);
     rajasthanRoyals1.addCricketer ("Yashavi", "Jaiswal", 19);
     rajasthanRoyals1.addCricketer ("Shimron", "Hetmeyer", 189);
     rajasthanRoyals1.addCricketer ("Trent", "Boult", 18);
     rajasthanRoyals1.addCricketer ("Savichandran", "Ashwin", 99);
     rajasthanRoyals1.addCricketer ("Yuzvendra", "Chahal", 3);
     
     CricketTeam rajasthanRoyals2;
     rajasthanRoyals2.addCricketer ("Sanju", "Zamson", 11);
     rajasthanRoyals2.addCricketer ("Ravichandran", "Adhwin", 97);
     
     rajasthanRoyals2.addCricketer ("Qavichandran", "Arhwin", 97);
     
     
     //rajasthanRoyals1.printCricket();
     //rajasthanRoyals2.printCricket();
     
     CricketTeam odJoined;
     
     mergeCricketers(rajasthanRoyals1, rajasthanRoyals2, odJoined);
     odJoined.printCricket();
     */
    
    //* Edwin's test case
    CricketTeam rajasthanRoyals1, rajasthanRoyals2;
    rajasthanRoyals1.addCricketer ("Trent", "Boult", 18 );
    rajasthanRoyals1.addCricketer ("Trim", "David", 8 );
    
    rajasthanRoyals1.addCricketer ("Rashid", "Khbn", 18);
    rajasthanRoyals1.addCricketer ("Rashid", "Khab", 19);
    rajasthanRoyals1.addCricketer ("Rashid", "Khac", 17);
    
    
    
    rajasthanRoyals2.addCricketer ("Trent", "Boult", 18);
    
    rajasthanRoyals2.addCricketer ("Tim", "Southee", 38);
    rajasthanRoyals2.addCricketer ("Kane" ,"Williamson", 22);
    
    CricketTeam odJoined;
    
    mergeCricketers(rajasthanRoyals1, rajasthanRoyals2, odJoined);
    //odJoined.printCricket();
    
    //delete odJoined;
    CricketTeam odResult;
    
    checkCricketers("T*","*",rajasthanRoyals1,odResult);
    odResult.printCricket();
    
    
    // return 0;
}


