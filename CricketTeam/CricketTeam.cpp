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
    }
    return numOfNodes;
}



bool CricketTeam::addCricketer(string firstName, string lastName, int value){
    Node *p, *np;
    
    p = head;
    if (p == nullptr){
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
        if (p->lastName == lastName and p->firstName == firstName) {
            cout << " The name: " << firstName <<" "<<lastName <<" already in the list!\n";
            return false;
        }
        if (p->lastName == lastName and firstName < p->firstName){
            p = p->next;
        }
        else {
            
            np = new Node;
            np->firstName = firstName;
            np->lastName = lastName;
            np->number = value;
            np->next = p->next;
            p->next = np;
            return true;
            
            
        }
    }
    cout <<" List is empty";
    return false;

}


void CricketTeam::printCricket(){
    Node *p;
    p=head;
    while (p != nullptr){
        cout << p->firstName <<" \n";
    }
}

