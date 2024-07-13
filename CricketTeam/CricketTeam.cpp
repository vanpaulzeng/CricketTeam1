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
    Node *p,*temp=nullptr, *np;
    int compareLast=0, compareFirst=0;

    p = head;
    temp = p;
    
    if (p == nullptr){  //empty, add in
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
         cout << "we had \n";
         this->printCricket();
         cout << lastName<< "   input   " << firstName <<"\n";
        
        
        
        // if p->lastname > lastname, then comparelast will > 0, add node in front of p
        compareLast = strcmp(p->lastName.c_str(), lastName.c_str());
        compareFirst = strcmp(p->firstName.c_str(), firstName.c_str());
        
        if (compareLast < 0){ //Move ahead by lastname
            if (p != tail){
                temp = p;  //remember the previous node to temp for every p move ahead
                if (p != tail) p = p->next;
                continue;
            }
        }
        
        if(compareLast == 0 and compareFirst == 0){
            cout << " The name: " << firstName <<" "<<lastName <<" already in the list!\n";
            return false;
        }
        
        if(compareLast == 0 and compareFirst < 0){ // move ahead by firstname
            temp = p;
            if (p != tail) p = p->next;
        }
        
        else if(compareLast == 0 and compareFirst > 0){ //
            if (p==head){ //add as head
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
                head = np;

            }
            else{
                np = new Node;
                np->firstName = firstName;
                np->lastName = lastName;
                np->number = value;
                np->next = p;
                temp->next = np;

            }
            return true;
            
        }
        
        
        if (compareLast <0){  //add after p
            if (p == tail){
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
            
            else{
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
        cout << p->lastName <<" "<< p->firstName <<" \n";
        p = p->next;
    }
}

