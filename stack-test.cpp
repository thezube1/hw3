#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char*argv[]) {
    Stack<int> s;
    cout << "initial empty: " << (s.empty() ? "yes" : "no") << '\n';

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "size after pushes: " << s.size() << '\n';
    cout << "top: " << s.top() << '\n';

    s.pop();
    cout << "top after one pop: " << s.top() << '\n';
    cout << "size: " << s.size() << '\n';

    s.pop(); s.pop();
    cout << "empty after popping all: " << (s.empty() ? "yes" : "no") << '\n';

    try {
        s.pop();
        cout << "ERROR: pop on empty did not throw\n";
    } catch (const std::underflow_error& e) {
        cout << "pop on empty threw: " << e.what() << '\n';
    }

    try {
        s.top();
        cout << "ERROR: top on empty did not throw\n";
    } catch (const std::underflow_error& e) {
        cout << "top on empty threw: " << e.what() << '\n';
    }

    return 0;
}