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
    
    
    /* Edwin's merge test case 1 passed
    CricketTeam rajasthanRoyals1, rajasthanRoyals2, rajasthanRoyals3;
    
     
    
    rajasthanRoyals1.addCricketer ("Trent", "Boult" ,18);
    rajasthanRoyals1.addCricketer ("Tim", "David", 8);
    rajasthanRoyals1.addCricketer ( "Rashid", "Khan" ,19);
    
    rajasthanRoyals2.addCricketer ("Trent", "Boult", 18 );
    rajasthanRoyals2.addCricketer ( "Tim", "Southee" ,38);
    rajasthanRoyals2.addCricketer ("Kane" ,"Williamson", 22);
    
    CricketTeam odJoined;
    
    mergeCricketers(rajasthanRoyals1, rajasthanRoyals2, odJoined);
    odJoined.printCricket();
    
     */
    
    
    /* Edwin's merge test case 2 passed

    rajasthanRoyals1.addCricketer ("Quinton", "DeCock" ,12);
    rajasthanRoyals1.addCricketer ("Faf", "DuPlessis" ,17);
    rajasthanRoyals1.addCricketer ("Kagiso", "Rabada", 25);

    rajasthanRoyals2.addCricketer ("Faf", "DuPlessis", 13);
    rajasthanRoyals2.addCricketer ("Virat", "Kohli" ,18);
    
    CricketTeam odJoined;
    
    mergeCricketers(rajasthanRoyals1, rajasthanRoyals2, odJoined);
    odJoined.printCricket();
     
     */
     
     
     /*/* Edwin's check test case 1, passed
      CricketTeam rajasthanRoyals1, rajasthanRoyals2;
      
      rajasthanRoyals1.addCricketer ( "Rahul", "Dravid", 15);
      rajasthanRoyals1.addCricketer ("David", "Miller", 13);
      rajasthanRoyals1.addCricketer ( "Rahul", "Tewatia", 9 );
      rajasthanRoyals1.addCricketer ("David", "Wiese", 96);
     
     
      CricketTeam odResult;
    
    checkCricketers("David","*",rajasthanRoyals1,odResult);
    odResult.printCricket();
    */
    
    
    
    // Edwin's check test 2  passed
    CricketTeam rajasthanRoyals3;
    CricketTeam odResult2;
    
    rajasthanRoyals3.addCricketer ( "Darren", "Bravo", 46);
    rajasthanRoyals3.addCricketer ("Dwayne", "Bravo", 47);
    rajasthanRoyals3.addCricketer ( "Kieron", "Pollard", 55 );
    rajasthanRoyals3.addCricketer ( "Nicolas", "Pooran", 29);
   
   
   
  
  checkCricketers("*","*",rajasthanRoyals3,odResult2);
  odResult2.printCricket();
  
     
    

    
    
    
    
    // return 0;
}


