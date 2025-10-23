#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cassert>
#include "heap.h"

void test_int_min() {
    Heap<int> h; // default is min-heap (std::less)
    std::vector<int> in{5,1,3,4,2};
    for (int x : in) h.push(x);

    std::vector<int> out;
    while (!h.empty()) {
        out.push_back(h.top());
        h.pop();
    }
    std::vector<int> expected{1,2,3,4,5};
    assert(out == expected && "int min-heap did not produce ascending order");
}

void test_int_max() {
    Heap<int, std::greater<int>> h(2, std::greater<int>()); // max-heap
    std::vector<int> in{5,1,3,4,2};
    for (int x : in) h.push(x);

    std::vector<int> out;
    while (!h.empty()) {
        out.push_back(h.top());
        h.pop();
    }
    std::vector<int> expected{5,4,3,2,1};
    assert(out == expected && "int max-heap did not produce descending order");
}

void test_string_min() {
    Heap<std::string> h;
    std::vector<std::string> in{"pear","apple","orange","banana"};
    for (auto &s : in) h.push(s);

    std::vector<std::string> out;
    while (!h.empty()) {
        out.push_back(h.top());
        h.pop();
    }
    std::vector<std::string> expected{"apple","banana","orange","pear"};
    assert(out == expected && "string min-heap did not produce lexicographic order");
}

void test_exceptions() {
    Heap<int> h;
    bool threw = false;
    try {
        h.top();
    } catch (const std::underflow_error&) {
        threw = true;
    }
    assert(threw && "top() on empty heap should throw std::underflow_error");

    threw = false;
    try {
        h.pop();
    } catch (const std::underflow_error&) {
        threw = true;
    }
    assert(threw && "pop() on empty heap should throw std::underflow_error");
}

int main() {
    try {
        test_int_min();
        test_int_max();
        test_string_min();
        test_exceptions();
    } catch (const std::exception& e) {
        std::cerr << "TEST FAILED: exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "TEST FAILED: unknown exception\n";
        return 1;
    }

    std::cout << "All heap tests passed.\n";
    return 0;
}