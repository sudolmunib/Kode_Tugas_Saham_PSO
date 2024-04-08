#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

string kalimat = "minal aidzin walaidzin ngapuntene";
char cari;

void binarysearch(const vector<char>& sorted_kalimat) {
    int awal = 0;
    int akhir = sorted_kalimat.size() - 1;
    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;
        if (sorted_kalimat[tengah] == cari) {
            int index = find(kalimat.begin(), kalimat.end(), cari) - kalimat.begin();
            cout << "\n Huruf ditemukan pada index ke-" << index << endl;
            return;
        } else if (sorted_kalimat[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    cout << "\n Huruf tidak ditemukan\n";
}

int main() {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Kalimat : " << kalimat << endl;
    vector<char> sorted_kalimat(kalimat.begin(), kalimat.end());
    sort(sorted_kalimat.begin(), sorted_kalimat.end());
    cout << "\n Masukkan huruf yang ingin Anda cari : ";
    cin >> cari;

    binarysearch(sorted_kalimat);

    return EXIT_SUCCESS;
}
