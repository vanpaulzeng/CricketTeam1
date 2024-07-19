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
    CricketType value;
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
    // maps to(find then return member's value to paramater value, and return true. Otherwise, make no change to the
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

/*
 If a full name appears in exactly one of odOne and odTwo, then odJoined must contain an element consisting of that full name and its corresponding value.
 If a full name appears in both odOne and odTwo, with the same corresponding value in both, then odJoined must contain an element with that full name and value.
 When this function returns, odJoined must contain no elements other than those required by these rules. (You must not assume odJoined is empty when it is passed in to this function; it might not be.)
 If there exists a full name that appears in both odOne and odTwo, but with different corresponding values, then this function returns false; if there is no full name like this, the function returns true. Even if the function returns false, result must be constituted as defined by the above rules.
 */

static bool mergeCricketers(const CricketTeam & odOne,const CricketTeam & odTwo,CricketTeam & odJoined){

    int i;
    bool testResult = true;
    
    std::string firstName, lastName;
    CricketType value, team2Value;
    
    // use checkTeamForCricker to get member i, and use a for loop let i from 0 to cricketCount()
    
    
    for (i = 0; i < odOne.cricketerCount(); i++){  //add 1st team all members into joined team
        odOne.checkTeamForCricketer(i, firstName, lastName, value);
        odJoined.addCricketer(firstName, lastName, value);
    }

    firstName = "";
    lastName = "";
    for (i = 0; i < odTwo.cricketerCount(); i++){  // need to check if member already in joined team also check value with tempValue, if different value then need to return false
        odTwo.checkTeamForCricketer(i, firstName, lastName, team2Value);
        
        if (odJoined.searchForCricketer(firstName, lastName, value) == true and value!= team2Value){
            testResult = false;
            odJoined.releaseCricketer(firstName, lastName);
        }
        else
            //different name so add team 2 members into joined
            odJoined.addCricketer(firstName, lastName, team2Value);
    }
    //std::cout << testResult;
    return testResult;
}

/*
 When this function returns, odResult must contain a copy of all the elements in odOne that match the search terms; it must not contain any other elements. You can wildcard the first name, last name or both by supplying "*". (You must not assume result is empty when it is passed in to this function; it may not be.)
 */
static void checkCricketers (const std::string& fsearch,const std::string& lsearch,const CricketTeam& odOne,CricketTeam& odResult)
{
    
    int i, j , fPos = 0, lPos = 0;   // i for odOne loop, j for first or last name char loop
    //bool testResult;
    bool match = false;
    std::string firstName, lastName;
    CricketType value;
 
    // use checkTeamForCricker to get member
    
    
    for (i = 0; i < odOne.cricketerCount(); i++){  // loop from odOne members
        odOne.checkTeamForCricketer(i, firstName, lastName, value);
        
        fPos = fsearch.find("*");
        lPos = lsearch.find("*");
        //std::cout << "firstName  find * at \n"<<fPos << "  "<<lPos  ;
        
        
        if (fsearch == "*" and lsearch == "*"){  // lPos and fPos both equal 0
            odResult.addCricketer(firstName, lastName, value);
            continue; //full name match, add in result and skip to next member
        }
        
        if (firstName == fsearch and lastName == lsearch){
            odResult.addCricketer(firstName, lastName, value);
            continue; //full name match, add in result and skip to next member
        }
        
        
        
        if (lPos >= 0 || firstName == fsearch){ //need compare last by *
            for (j = 0; j < lPos; j++){  //loop inside lastName by char
                if ( lastName[j] == lsearch[j] ){ //Find lastncontinueame match members and add into odResult
                    match = true;
                    continue;
                }
                else{
                    match = false;
                } // End if last name compare
                break;  // found lastname match *
            }  //endif lastname[j] compare
            
        }  // End if *  in lastname
        
        if (match == true or firstName == fsearch ) {
            odResult.addCricketer(firstName, lastName, value);
            match = false;
            continue;  //if lastname already match, record add in, skip to next member
        }  // End if match for lastname
        
        if ( (fPos >= 0 or lastName == lsearch ) and match == false){ //need compare last by *
            for (j = 0; j < fPos; j++){  //loop inside firstName by char
                if ( firstName[j] == fsearch[j] ){ //Find lastncontinueame match members and add into odResult
                    match = true;
                    continue;
                }
                else{
                    match = false;
                } // End if first name compare
                break;  // found firstname match *
            }  //endif firstname[j] compare
            
        }  // End if *  in firstname
        
        if (match == true || lastName == lsearch) {
            odResult.addCricketer(firstName, lastName, value);
            match = false;
            continue;  //if firstname already match, record add in, skip to next member
        }  // End if match for firstname
        
        
        
        
    }  //end of member loop
    
} // end of func






 
 
#endif /* CricketTeam_h */
