#include <iostream>
#include <fstream>
#include <functional>
#include <random>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    Node* smaller;
    Node* larger;

    // Test out your linked list code
    llpivot(head, smaller, larger, 10);

    cout << "New smaller list: "; // should print 323ew2\]=
    print(smaller);
    cout << "New larger list: ";
    print(larger);

    // Test out your linked list code
    llpivot(head, smaller, larger, 5);

    cout << "New smaller list: "; // should print 323ew2\]=
    print(smaller);
    cout << "New larger list: ";
    print(larger);

    // create random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 100);

    // create 100 random test cases (for fun)
    int limit = 100;
    for (int i = 0; i < limit; i++) {
        cout << "---New Random Test #" << i+1 << " ---" << endl;
        // create first node with random value
        int randomFirstNodeVal = dist(gen);
        Node* tempHead = new Node(randomFirstNodeVal, nullptr);

        // create smaller and larger arrays
        Node* tempSmaller = nullptr;
        Node* tempLarger = nullptr;

        // create rest of array of random length (constrained)
        int randomLength = dist(gen);
        Node* tail = tempHead;
        for (int j = 0; j <= randomLength; j++) {
            int randomVal = dist(gen);
            tail->next = new Node(randomVal, nullptr);
            tail = tail->next;
        }
        
        cout << "Original list: ";
        print(tempHead);
        
        // generate and run pivot
        int randomPivot = dist(gen);
        cout << "Pivot: " << randomPivot << endl;

        llpivot(tempHead, tempSmaller, tempLarger, randomPivot);

        cout << "New smaller list: ";
        print(tempSmaller);
        cout << "New larger list: ";
        print(tempLarger);
    }



    
    return 0;

}
