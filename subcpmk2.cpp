#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    long long int nim; 
    float ipk;
};

int main() {

    Mahasiswa mhs1;

    mhs1.nama = "Munib";
    mhs1.nim = 2311110004; 
    mhs1.umur = 20;
    mhs1.ipk = 3.75;

    cout << "Nama: " << mhs1.nama << endl;
    cout << "NIM: " << mhs1.nim << endl;
    cout << "Umur: " << mhs1.umur << endl;
    cout << "IPK: " << mhs1.ipk << endl;

    return 0;
}
