//
//  CricketTeam.h
//  CricketTeam
//
//  Created by Admin on 2024-07-10.
//

#ifndef CricketTeam_h
#define CricketTeam_h


typedef std::int32_t CricketType; // This can change to other types such as double and int, not just string

struct Node {
    std::string firstName;
    std::string lastName;
    CricketType number;
    Node *next;
    Node *prev;
};


class CricketTeam
{
private:
    Node *head , *tail;
    
    
public:
CricketTeam(); // Create an empty CricketTeam list, constructor
  
//copy constructor
CricketTeam(const CricketTeam& rhs);

//destructor
~CricketTeam();
    
// assignment operator
CricketTeam& operator=(const CricketTeam& rhs);

    
    
bool noTeam() const; // Return true if the CricketTeam list is empty, otherwise false.

int cricketerCount() const; // Return the number of matches on the CricketTeam list.
    
bool addCricketer(std::string firstName, std::string lastName, CricketType value);
// If the full name (both the first and last name) is not equal
// to any full name currently in the list then add it and return
// true. Elements should be added according to their last name.
// Elements with the same last name should be added according to
// their first names. Otherwise, make no change to the list and
// return false (indicating that the name is already in the
// list).

bool substituteCricketer(const std::string &firstName, const std::string &lastName, const CricketType & value);
// If the full name is equal to a full name currently in the
// list, then make that full name no longer map to the value it
// currently maps to, but instead map to the value of the third
// parameter; return true in this case. Otherwise, make no
// change to the list and return false.
bool addOrSubstitute(const std::string& firstName, const std::string& lastName, const CricketType& value);
// If full name is equal to a name currently in the list, then
// make that full name no longer map to the value it currently
// maps to, but instead map to the value of the third parameter;
// return true in this case. If the full name is not equal to
// any full name currently in the list then add it and return
// true. In fact, this function always returns true.
bool releaseCricketer(const std::string& firstName, const std::string& lastName);
// If the full name is equal to a full name currently in the
// list, remove the full name and value from the list and return
// true. Otherwise, make no change to the list and return
// false.
bool rosteredOnCricketTeam(const std::string& firstName, const std::string& lastName) const;
// Return true if the full name is equal to a full name
// currently in the list, otherwise false.
bool searchForCricketer(const std::string& firstName, const std::string& lastName, CricketType& value) const;
// If the full name is equal to a full name currently in the
// list, set value to the value in the list that that full name
// maps to, and return true. Otherwise, make no change to the
// value parameter of this function and return false.
bool checkTeamForCricketer(int i, std::string& firstName, std::string& lastName, CricketType & value) const;
// If 0 <= i < size(), copy into firstName, lastName and value
// parameters the corresponding information of the element at
// position i in the list and return true. Otherwise, leave the
// parameters unchanged and return false. (See below for details
// about this function.)
void tradeCricketTeams(CricketTeam& other);
// Exchange the contents of this list with the other one.
    void printCricket();
    // print list

// Non-member function virtual define
//bool& mergeCricketers(const CricketTeam & odOne,const CricketTeam & odTwo,CricketTeam & odJoined);

};

// Non-member function
//bool mergeCricketers(const CricketTeam & odOne,const CricketTeam & odTwo,CricketTeam & odJoined);

//void checkCricketers (const std::string& fsearch,const std::string& lsearch,const CricketTeam& odOne,CricketTeam& odResult);

bool mergeCricketers(const CricketTeam & odOne,const CricketTeam & odTwo,CricketTeam & odJoined){

    int i, j;
    
    std::string firstName, lastName;
    CricketType value;
    
    // use checkTeamForCricker to get member
    
    
    for (i = 1; i <= odOne.cricketerCount(); i++){
        if (odOne.checkTeamForCricketer(i, firstName, lastName, value) == true){
            odJoined.addCricketer(firstName, lastName, value);
        }
    }
    return true;
}





#endif /* CricketTeam_h */
