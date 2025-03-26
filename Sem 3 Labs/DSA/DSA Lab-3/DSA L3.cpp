#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class ExpressionConverter {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    string infixToPostfix(string expression) {
        stack<char> s;
        string result;
        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (isalnum(c)) {                  //isalnum(c): Checks if the character is alphanumeric.
                result += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    result += s.top();
                    s.pop();
                }
                s.pop();
            } else {
                while (!s.empty() && precedence(c) <= precedence(s.top())) {
                    result += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        return result;
    }

    string reverseString(string str) {
        int n = str.length();
        for (int i = 0; i < n / 2; ++i) {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
        return str;
    }

    string infixToPrefix(string expression) {
        expression = reverseString(expression);
        for (size_t i = 0; i < expression.length(); ++i) {
            if (expression[i] == '(') {
                expression[i] = ')';
            } else if (expression[i] == ')') {
                expression[i] = '(';
            }
        }
        string result = infixToPostfix(expression);
        return reverseString(result);
    }

    int evaluatePostfix(string expression) {
        stack<int> s;
        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (isdigit(c)) {
                s.push(c - '0');
            } else {
                int val1 = s.top(); s.pop();
                int val2 = s.top(); s.pop();
                switch (c) {
                    case '+': s.push(val2 + val1); break;
                    case '-': s.push(val2 - val1); break;
                    case '*': s.push(val2 * val1); break;
                    case '/': s.push(val2 / val1); break;
                }
            }
        }
        return s.top();
    }

    void menu() {
        while (true) {
            int choice;
            cout << "Menu:\n1. Infix to Postfix\n2. Infix to Prefix\n3. Evaluate Postfix\n4. Exit\nChoice: ";
            cin >> choice;
            cin.ignore();

            string expression;
            switch (choice) {
                case 1:
                    cout << "Enter infix: ";
                    getline(cin, expression);
                    cout << "Postfix: " << infixToPostfix(expression) << endl;
                    break;
                case 2:
                    cout << "Enter infix: ";
                    getline(cin, expression);
                    cout << "Prefix: " << infixToPrefix(expression) << endl;
                    break;
                case 3:
                    cout << "Enter postfix: ";
                    getline(cin, expression);
                    cout << "Result: " << evaluatePostfix(expression) << endl;
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
    }
};

int main() {
    ExpressionConverter converter;
    converter.menu();
    return 0;
}

