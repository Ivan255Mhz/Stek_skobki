

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBrackets(const string& str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << "Ошибка: закрывающая скобка без открывающей" << &c - &str[0] << endl;
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                cout << "Ошибка: неправильная пара скобок в позиции" << &c - &str[0] << endl;
                return false;
            }
        }
    }
    if (!st.empty()) {
        cout << "Ошибка: незакрытая скобка в позиции" << &st.top() - &str[0] << endl;
        return false;
    }
    cout << "Строка корректна" << endl;
    return true;
}

int main() {
    string str1 = "({x-y-z}*[x+2y]-(z+4x))";
    string str2 = "([x-y-z}*[x+2y)-{z+4x)]";
    checkBrackets(str1);
    checkBrackets(str2);
    return 0;
}


