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



bool CricketTeam::addCricketer(string firstName, string lastName, int value){
    Node *p, *np;
    int compareLast=0, compareFirst=0;

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
        compareLast = strcmp(p->lastName.c_str(), lastName.c_str());
        compareFirst = strcmp(p->firstName.c_str(), firstName.c_str());
        if (compareLast > 0) {
            
            //lastname is ahead than existing list, need add node head
            np = new Node;
            np->firstName = firstName;
            np->lastName = lastName;
            np->number = value;
            np->next = p;
            head = np;
            return true;

        }
        
        if(compareLast == 0 and compareFirst == 0){
            cout << " The name: " << firstName <<" "<<lastName <<" already in the list!\n";
            return false;
        }
    
        if(compareLast == 0 and compareFirst < 0){
                p = p->next;
                continue;
            }
            else {
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = p->next;
                p->next = np;
                tail = np;
                return true;
            }
        
        
    
    }
    return false;
}


void CricketTeam::printCricket(){
    Node *p;
    p=head;
    while (p != nullptr){
        cout << p->lastName <<" "<< p->firstName <<" \n";
        p = p->next;
    }
}

