//
//  subtractLinkedList.cpp
//  CodePathPrework
//
//  Created by Sudipta Bhowmik on 7/10/17.
//  Copyright © 2017 Sudipta Bhowmik. All rights reserved.
//

#include "subtractLinkedList.hpp"


/* Function to push a node */
void push(struct ListNode** head_ref, int new_data)
{
    /* allocate node */
    struct ListNode* new_node =
    (struct ListNode*) malloc(sizeof(struct ListNode));
    
    /* put in the data  */
    new_node->val  = new_data;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode * findMiddleNode(ListNode *A) {
    ListNode *fast, *slow;
    
    slow = fast = A;
    while (fast != NULL) {
        fast = fast -> next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow ->next;
        }
    }
    return slow;
}

ListNode *reverseList(ListNode *head) {
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next;
    
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
        
    }
    
    return prev;
}

void subtractNodes(ListNode *first, ListNode *second) {
    ListNode *temp = first;
    while (second != NULL) {
        //Both lists are of the same length & we are at the last node in both lists so this is the middle node
        if (second->next == NULL && temp->next == NULL) {
            break;
        } else {
            if (temp->next) {
                temp->val = abs(second->val - temp->val);
                temp = temp->next;
                second = second->next;
            }
        }
    }
}



ListNode* subtract(ListNode* A) {
    
    //Find middle node
    ListNode *mid = findMiddleNode(A);
    
    cout<<"middle is: "<<mid->val<<endl;
    
    //Reverse nodes starting from the middle node
    ListNode *reverseHead = reverseList(mid);
    
    cout<<"reverse is: ";
    printList(reverseHead);
    
    //Subtract values in original half from reversed half of list
    subtractNodes(A, reverseHead);
    
    cout<<"After sub: ";
    printList(A);
    
    //Re-reverse the second half of list
    ListNode *secondList = reverseList(reverseHead);
    
    cout<<"After re-reverse: ";
    printList(secondList);
    
    //Join elements from second half back to original half
    //joinList(A, secondList);
    
    cout<<"New: ";
    printList(A);
    return A;
}