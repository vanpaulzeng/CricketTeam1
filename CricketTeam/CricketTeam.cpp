//
//  CricketTeam.cpp
//  CricketTeam
//
//  Created by Admin on 2024-07-10.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "CricketTeam.h"

using namespace std;

CricketTeam::CricketTeam() {
    head = nullptr;
    tail = nullptr;
}

bool CricketTeam::noTeam(){
    if (head == nullptr) return true;
    else return false;
}

int CricketTeam::cricketerCount(){
    Node *p;
    int numOfNodes = 0;
    p = head;
    while (p != nullptr){
        numOfNodes++;
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
        np->number = value;
        np->next = nullptr;
        head = np;
        tail = np;

        return true;

    }

    
    while (p != nullptr){
//         cout << "we had \n";
//         this->printCricket();
//         cout << lastName<< "   input   " << firstName <<"\n";
        
        
        
        // if p->lastname > lastname, then comparelast will > 0, add node in front of p
        compareLast = strcmp(p->lastName.c_str(), lastName.c_str());
        compareFirst = strcmp(p->firstName.c_str(), firstName.c_str());
        
        if (compareLast < 0){ //Move ahead by lastname
            if (p != tail){  //loop until tail
                temp = p;  //remember the previous node to temp for every p move ahead
                if (p != tail) p = p->next;  //make sure next pointer move safe, if p is tail, do not move
                continue;
            }
        }
        
        if(compareLast == 0 and compareFirst == 0){
            cout << " The name: " << firstName <<" "<<lastName <<" already in the list!\n";
            return false;
        }
        
        if(compareLast == 0 and compareFirst < 0){ // move ahead by firstname
            temp = p;
            if (p != tail) p = p->next;  //make sure next pointer move safe, if p is tail, do not move
        }
        
        else if(compareLast == 0 and compareFirst > 0){ //
            if (p==head){ //head will use different add method, add np as new head
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = p;
                head = np;
                
                return true;

            }
            else{  // add ahead p
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = p;
                temp->next = np;
                
                return true;


            }
            
        
        }
        
        //reach tail or firstname is just before p, add node ahead p
        
        if (compareLast >=0 and compareFirst >= 0){  //add before here
            if (p==head){ // add as head
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = p;
                head = np;  //update new head as np

            }
            else{  //add np before p
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = p;
                temp->next = np;

            }
            return true;
            
        }
        
        
        if (compareLast <0){  //lastname just pass p order, add np after p
            if (p == tail){  //check tail and make new tail as np
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = nullptr;
                p->next = np;
                tail = np;
                
                return true;
            }
            
        }
        else{  //just reach lastname p order, add np before p
            np = new Node;
            np->firstName = firstName;
            np->lastName = lastName;
            np->number = value;
            np->next = p;
            temp->next = np;
            return true;
        }
        
    }

    return false;
}


void CricketTeam::printCricket(){
    Node *p;
    p=head;
    while (p != nullptr){
        cout << p->lastName<<" "<< p->firstName << "  "<<p->number <<"  \n";
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
            p->number = value;
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
            p->number = value;
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
            p->number = value;
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
            p->firstName = firstName;
            p->lastName = lastName;
            p->number = value;
        }
        nodeSeq ++;
        
        p = p->next;
    }
    return false;

    
}

// Exchange the contents of this list with the other one.

void CricketTeam::tradeCricketTeams(CricketTeam& other){
    Node *p, *pOther;
    pOther = other.head;
    p = head;
    while (pOther != nullptr){
        p->firstName = pOther->firstName;
        p->lastName = pOther->lastName;
        p->number = pOther->number;
        
        p = p->next;
        pOther = pOther->next;
    }

}




