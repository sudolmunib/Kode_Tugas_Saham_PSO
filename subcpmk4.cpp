#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s) {
    stack<int> tmpStack;

    while (!s.empty()) {
        int tmp = s.top();
        s.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp) {
            s.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    while (!tmpStack.empty()) {
        s.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main() {
    stack<int> s;

    // Push ubtuk masukan elemen-elemen ke dalam stack
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(1);
    s.push(2);

    // tampilan stack sebelum diurutkan
    cout << "Stack sebelum diurutkan: ";
    stack<int> tmp = s; 
    while (!tmp.empty()) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;

    // Menyortir stack
    sortStack(s);

    // tampilan stack setelah diurutkan
    cout << "Stack setelah diurutkan: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
