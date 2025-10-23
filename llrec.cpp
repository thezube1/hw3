#include "llrec.h"
#include <iostream>


//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* next = head->next;

    head->next = nullptr;

    if (head->val <= pivot) {
        smaller = head;
        llpivot(next, smaller->next, larger, pivot);
    } else {
        larger = head;
        llpivot(next, smaller, larger->next, pivot);
    }

    head = nullptr;
    

    
    
}