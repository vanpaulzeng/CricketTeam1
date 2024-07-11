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


