#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseSentence(string kalimat) {
    stack<char> charStack;

    for (int i = 0; i < kalimat.length(); ++i) {
        charStack.push(kalimat[i]);
    }

    cout << "Hasil: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl;
}

int main() {
    string kalimat;

    cout << "Kalimat: ";
    getline(cin, kalimat);

    reverseSentence(kalimat);

    return 0;
}
