//
//  subtractLinkedList.hpp
//  CodePathPrework
//
//  Created by Sudipta Bhowmik on 7/10/17.
//  Copyright © 2017 Sudipta Bhowmik. All rights reserved.
//

#ifndef subtractLinkedList_hpp
#define subtractLinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* subtract(ListNode* A);
void push(struct ListNode** head_ref, int new_data);
void printList(struct ListNode *head);

#endif /* subtractLinkedList_hpp */
