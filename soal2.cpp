#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Masukkan sebuah bilangan: ";
    cin >> num;
    int result = factorial(num);
    cout << "Faktorial dari " << num << " adalah " << result << endl;
    
    return 0;
}


