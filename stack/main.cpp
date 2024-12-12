#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatchingPair(char opening, char closing) {
    switch (opening) {
    case '{':
        return closing == '}';
    case '[':
        return closing == ']';
    case '(':
        return closing == ')';
    }
    return false;
}

bool isValidExpression(const string& expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '{' || ch == '(' || ch == '[') {
            s.push(ch);
        }
        else if (ch == '}' || ch == ')' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string expression;
    cout << "Enter a string of characters with brackets: ";
    getline(cin, expression);

    bool valid = isValidExpression(expression);

    if (valid) {
        cout << "The string is valid.\n";
    }
    else {
        
        size_t errorPos = expression.find_first_of("}{][");
        if (errorPos != string::npos) {
            cout << "Invalid at position " << errorPos << ": " << expression.substr(0, errorPos + 1) << "\n";
        }
    }

    return 0;
}
