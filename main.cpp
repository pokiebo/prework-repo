//
//  main.cpp
//  CodePathPrework
//
//  Created by Sudipta Bhowmik on 7/10/17.
//  Copyright © 2017 Sudipta Bhowmik. All rights reserved.
//

#include <iostream>
#include "PrettyPrint.hpp"
#include "kSmallest.hpp"
#include "subtractLinkedList.hpp"
#include "LongestSubseq.hpp"

void callPrettyPrint() {
    prettyPrint(4);
}

void callkSmallest() {
    vector<int> A;
    A.push_back(2);
    A.push_back(1);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    int x = kthsmallest(A, 3);
    cout << x<<endl;
}

void callsubtract() {
    struct ListNode* head = NULL;
    
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    printf("Given linked list\n");
    printList(head);
    subtract(head);
    
}

void callLongestSubseq() {
    vector<int> A;
    A.push_back(100);
    A.push_back(4);
    A.push_back(200);
    A.push_back(1);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    
    cout <<longestConsecutive(A);
}


int main(int argc, const char * argv[]) {
    //================= PrettyPrint================//
    callPrettyPrint();
    
    //================= kthSmallest================//
    callkSmallest();
    
    
    //================Subtract list ==============//
    callsubtract();
    
    //===============Longest Cont Subseq==========//
    callLongestSubseq();
    
    return 0;
}
