#include <iostream>
#include <vector>
using namespace std;

int main() {
    int length;
    cout << "Masukkan Panjang Array: ";
    cin >> length;
    vector<int> array(length);
    cout << "Masukkan " << length << " angka untuk array\n";
    for (int i = 0; i < length; i++) {
        cout << "Array Ke- " << (i + 1) << ": ";
        cin >> array[i];
    }
    cout << "Data array:";
    for (int i = 0; i < length; i++) {
        cout << " " << array[i];
    }
    cout << endl;
    cout << "Nomor Genap :";
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            cout << array[i];
            if (i < length - 1) 
                cout << ", ";
        }
    }
    cout << endl;
    cout << "Nomor Ganjil :";
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 != 0) {
            cout << array[i];
            if (i < length - 1) 
                cout << ", ";
        }
    }
    cout << endl;
    return 0;
}
