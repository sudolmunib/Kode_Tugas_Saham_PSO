#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Masukkan panjang array: ";
    cin >> n;

    vector<int> array(n);

    cout << "Masukkan " << n << " angka untuk array\n";
    for (int i = 0; i < n; i++) {
        cout << "Array Ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    int choice;
    cout << "\nMenu:\n";
    cout << "1. Cari Nilai Maksimum\n";
    cout << "2. Cari Nilai Minimum\n";
    cout << "3. Cari Nilai Rata-rata\n";
    cout << "Pilih opsi: ";
    cin >> choice;

    int sum = 0;

    switch (choice) {
        case 1:
            cout << "Nilai Maksimum: " << *max_element(array.begin(), array.end()) << endl;
            break;
        case 2:
            cout << "Nilai Minimum: " << *min_element(array.begin(), array.end()) << endl;
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                sum += array[i];
            }
            cout << "Nilai Rata-rata: " << static_cast<double>(sum) / n << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }

    return 0;
}
