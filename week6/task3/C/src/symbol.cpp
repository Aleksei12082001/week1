#include "symbol.hpp"
#include <unordered_map>
#include <stack>

using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValid(const string& s) {
    stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c); 
        } else {
            if (stack.empty() || !isMatchingPair(stack.top(), c)) {
                return false; 
            }
            stack.pop(); 
        }
    }

    return stack.empty(); 
}







