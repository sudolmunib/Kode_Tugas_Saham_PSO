#include <iostream>
using namespace std;

int cariSekuesial(int arr[], int ukuran, int nilai) {
    for (int i = 0; i < ukuran; i++) {
        if (arr[i] == nilai) {
            return i;
        }
    }
    return -1;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 5};
    int ukuran = sizeof(array) / sizeof(array[0]);
    int nilaiYangDicari = 5;

    int indeks = cariSekuesial(array, ukuran, nilaiYangDicari);

    if (indeks != -1) {
        cout << "Nilai " << nilaiYangDicari << " ditemukan pada indeks " << indeks << "." << endl;
    } else {
        cout << "Nilai " << nilaiYangDicari << " tidak ditemukan dalam array." << endl;
    }

    return 0;
}
