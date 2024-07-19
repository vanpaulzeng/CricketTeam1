
#include <stdio.h>
#include <string>
#include <iostream>
#include "CricketTeam.h"

using namespace std;

//constructor
CricketTeam::CricketTeam() {
    head = nullptr;
    tail = nullptr;
}



//copy constructor  will implment a deep copy, means copy every node value into a current team
CricketTeam::CricketTeam(const CricketTeam & rhs) {
    Node *p, *np, *nprev = nullptr;
    p = rhs.head;
    np = new Node;

    
    while ( p != nullptr){
        if (p == rhs.head){
            head = np;
            nprev = head;
            
        }

        np->firstName = p->firstName;
        np->lastName = p->lastName;
        np->value = p->value;
        np->next = nullptr;
        np->prev = nprev;
        np = new Node;
        p = p-> next;  // p move forward in rhs
        nprev->next = np;  //nprev move forward in copied team(current or this)
    }
    tail = np;
}


//Assigement will implment
// const LinkedList& LinkedList::operator=(const LinkedList& rhs)
const CricketTeam& CricketTeam::operator=(const CricketTeam& rhs)
{
    if (this == &rhs) return *this;
    CricketTeam temp = rhs;
    tradeCricketTeams(temp);
    return *this;
}


//denstructor
CricketTeam::~CricketTeam() {
    Node *p;
    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}


bool CricketTeam::noTeam() const{
    if (head == nullptr) return true;
    else return false;
}

int CricketTeam::cricketerCount() const{
    Node *p;
    int numOfNodes = 0;
    p = head;
    while (p != nullptr){
        numOfNodes++;
        //cout << numOfNodes;
        p = p->next;
    }
    return numOfNodes;
}


// If the full name (both the first and last name) is not equal
// to any full name currently in the list then add it and return
// true. Elements should be added according to their last name.
// Elements with the same last name should be added according to
// their first names. Otherwise, make no change to the list and
// return false (indicating that the name is already in the
// list).  Quite difficult
bool CricketTeam::addCricketer(string firstName, string lastName, CricketType value){
    Node *p,*temp=nullptr, *np;
    int compareLast=0, compareFirst=0;
    
    p = head;
    temp = p; //Save previous pointer as temp
    
    if (p == nullptr){  //empty, add in as head and tail
        np = new Node;
        np->firstName = firstName;
        np->lastName = lastName;
        np->value = value;
        np->next = nullptr;
        np->prev = nullptr;
        head = np;
        tail = np;
        
        return true;
        
    }
    
    
    while (p != nullptr){  //start to match by Lastname, then Firstname
        //cerr << "we had \n";
        //this->printCricket();
        //cerr << lastName<< "   input   " << firstName <<"\n";
        
        
        
        // if p->lastname > lastname, then comparelast will > 0, add node in front of p
        compareLast = strcmp(p->lastName.c_str(), lastName.c_str());
        compareFirst = strcmp(p->firstName.c_str(), firstName.c_str());
        
        if (compareLast < 0){ //Move ahead by lastname
            if (p != tail){  //loop until tail
                temp = p;  //remember the previous node to temp before every p move ahead
                p = p->next;  //make sure next pointer move safe, if p is tail, do not move
                continue;
            }
        }
        
        if(compareLast == 0 and compareFirst == 0){
            //cout << " The name: " << firstName <<" "<<lastName <<" already in the list!\n";
            return false;
        }
        
        if(compareLast == 0 and compareFirst < 0){ // Find Lastname then move ahead by firstname
            if (p != tail){  //loop until tail
                temp = p;  //remember the previous node to temp before every p move ahead
                p = p->next;  //make sure next pointer move safe, if p is tail, do not move
                continue;
            }
            
            else if(compareLast == 0 and compareFirst > 0){ // Find Lastname and reach the 1st greater Firstname, need to add ahead p
                if (p==head){ //head will use different add method, add np as new head
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    np->next = p;
                    np->prev = nullptr;  //head's prev is null
                    p->prev = np;
                    head = np;   //point new head to np
                    
                    return true;
                    
                }
                else{  // this will be same Lastname, and compareFirst <0, add ahead p, no need to update tail
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    np->next = p;
                    np->prev = temp;  //remeber we use temp to point previous of p
                    temp->next = np;
                    p->prev = np;  //p->next will stay the same as before
                    
                    return true;
                }
            }
        }
            
            //reach tail or firstname is just before p, add node ahead p
            
            if (compareLast >=0 and compareFirst >= 0){  //reach the right position, add np before p
                if (p==head){ // handle p = head, add new node np as head
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    np->next = p;
                    np->prev = nullptr;  //head's prev is null
                    p->prev = np;
                    head = np;   //point new head to np
                    
                }
                else{  //add np before p, but np is not a head
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    temp->next = np;   //temp is previous p, add np between temp and p
                    np->next = p;
                    np->prev = temp;
                    p->prev = np;
                    
                    
                }
                return true;
                
            }
            
            
            if (compareLast <0){  //lastname just pass p order, add np after p
                if (p == tail){  //check tail and make new tail as np
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    np->next = nullptr;
                    np->prev = p;
                    p->next = np;  //p->prev stay as same
                    tail = np;
                    
                    return true;
                }
                
            }
            else{  //just reach next lastname p, add np before p
                if (p == head){
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    np->next = p;
                    np->prev = nullptr;
                    p->prev = np;
                    head = np; //need to update head now
                    return true;
                    
                }
                else{ //add as a normal node ahead p
                    np = new Node;
                    np->firstName = firstName;
                    np->lastName = lastName;
                    np->value = value;
                    np->next = p;
                    np->prev = temp;
                    temp->next = np;
                    
                    return true;
                }
            }
        }
    return false;

}



void CricketTeam::printCricket(){
    Node *p;
    p=head;
    while (p != nullptr){
        cout << p->lastName<<" "<< p->firstName << "  "<<p->value <<"  \n";
        p = p->next;
    }
}


// If the full name is equal to a full name currently in the
// list, then make that full name no longer map to the value it
// currently maps to, but instead map to the value of the third
// parameter; return true in this case. Otherwise, make no
// change to the list and return false.
bool CricketTeam::substituteCricketer(const std::string &firstName, const std::string &lastName, const CricketType & value){
    Node *p;
    p=head;
    while (p != nullptr){
        if ((p->lastName+p->firstName) == lastName+firstName){
            p->value = value;
            return true;
        }
        p = p->next;
    }
    //cout <<"false \n";
    return false;

}


// If full name is equal to a name currently in the list, then
// make that full name no longer map to the value it currently
// maps to, but instead map to the value of the third parameter;
// return true in this case. If the full name is not equal to
// any full name currently in the list then add it and return
// true. In fact, this function always returns true.

bool CricketTeam::addOrSubstitute(const std::string& firstName, const std::string& lastName, const CricketType& value){
    Node *p;
    p=head;
    while (p != nullptr){
        if ((p->lastName+p->firstName) == lastName+firstName){
            p->value = value;
            return true;
        }
        p = p->next;
    }

    this->addCricketer(firstName, lastName, value);
    
    return true;
}


// If the full name is equal to a full name currently in the
// list, remove the full name and value from the list and return
// true. Otherwise, make no change to the list and return
// false.

bool CricketTeam::releaseCricketer(const std::string& firstName, const std::string& lastName){
    Node *p, *killMe;
    
    p = head;

    while (p != nullptr){
        if (p->next != nullptr && (p->next->lastName+p->next->firstName) == lastName+firstName){
            break;
        }
        p = p->next;
    }
    
    if (p != nullptr){
        killMe = p->next;
        p->next = killMe->next;
        delete killMe;
        return true;
    }


    return false;

}


// Return true if the full name is equal to a full name
// currently in the list, otherwise false.

bool CricketTeam::rosteredOnCricketTeam(const std::string& firstName, const std::string& lastName) const{
    Node *p;
    p=head;
    while (p != nullptr){
        if ((p->lastName+p->firstName) == lastName+firstName){
            return true;
           // cout << "find name->"<<lastName+firstName<<"\n";
        }
        p = p->next;
    }

    
    return false;
}

// If the full name is equal to a full name currently in the
// list, set value to the value in the list that that full name
// maps to, and return true. Otherwise, make no change to the
// value parameter of this function and return false.

bool CricketTeam::searchForCricketer(const std::string& firstName, const std::string& lastName, CricketType& value) const{
    Node *p;
    p=head;
    while (p != nullptr){
        if ((p->lastName+p->firstName) == lastName+firstName){
            value = p->value;
            return true;
        }
        p = p->next;
    }
    return false;

}


// If 0 <= i < size(), copy into firstName, lastName and value
// parameters the corresponding information of the element at
// position i in the list and return true. Otherwise, leave the
// parameters unchanged and return false. (See below for details
// about this function.)

bool CricketTeam::checkTeamForCricketer(int i, std::string& firstName, std::string& lastName, CricketType & value) const{
    int nodeSeq = 0;
    Node *p;
    p=head;
    while (p != nullptr){
        if ( i == nodeSeq){
            firstName = p->firstName;
            lastName = p->lastName;
            value = p->value;
            return true;
        }
        nodeSeq ++;
        
        p = p->next;
    }
    return false;

    
}

// Exchange the contents of this list with the other one.

void CricketTeam::tradeCricketTeams(CricketTeam& other){
    Node *p, *prev=nullptr,  *pOther;
    pOther = other.head;
    p = head;
    while (pOther != nullptr){
        p->firstName = pOther->firstName;
        p->lastName = pOther->lastName;
        p->value = pOther->value;
        if (p != tail){
            //Since the prev and next links do does not change, no need to update
            prev = p;       //remember the previous p node which can be used as tail after loop
            p = p->next;  //move forward by pOther sequence til end
            pOther = pOther->next;
            
        }
        else { //Need more nodes
            p = new Node;
            prev->next = p;
            p->prev = prev;
            p->next = nullptr;
            tail = p;
        }
    }  // current list is longer than other, need recycle left nodes
    tail = prev;  // make new tail
    tail->next = nullptr;
    
    while (p != nullptr){
        prev = p;
        p = p->next;
        delete prev;  //delete the left nodes to prevent memory leak
    }
}



//void checkCricketers (const std::string& fsearch,const std::string& lsearch,const CricketTeam& odOne,CricketTeam& odResult){
//    cout <<"Non-member func \n";
//




