# <h1 align="center">Tugas setruktur data </h1>

<p align="center">Nama: Abdul Munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

[1]
Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

contoh

Input string1 = “bahu” string2 = “buah”
Output: “anagram”

Input string1 = “makan” string2 = “minum”
Output: “tidak anagram”

#### Jawab
```Cpp
#include <iostream>
#include <algorithm>
#include <string>

bool isAnagram(std::string str1, std::string str2) {
    str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(std::remove(str2.begin(), str2.end(), ' '), str2.end());

    if (str1.length() != str2.length())
        return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    std::string string1 = "bahu";
    std::string string2 = "buah";
    std::cout << "Input string1 = " << string1 << " string2 = " << string2 << std::endl;
    std::cout << "Output: " << (isAnagram(string1, string2) ? "anagram" : "tidak anagram") << std::endl;

    string1 = "makan";
    string2 = "minum";
    std::cout << "\nInput string1 = " << string1 << " string2 = " << string2 << std::endl;
    std::cout << "Output: " << (isAnagram(string1, string2) ? "anagram" : "tidak anagram") << std::endl;

    return 0;
}
```
Kode tersebut menggunakan isAnagram untuk mengambil dua string sebagai argumen. Pertama, spasi dihapus dari kedua string menggunakan fungsi std::remove, kemudian fungsi std::sort digunakan untuk mengurutkan karakter dalam kedua string. Jika panjang kedua string tidak sama, maka fungsi mengembalikan false, jika panjangnya sama, maka string yang telah diurutkan dibandingkan. Jika kedua string setelah diurutkan sama, maka fungsi mengembalikan true, yang berarti kedua string adalah anagram.
Output

[2]
Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

#### Jawab
Alur

Linear search Melakukan pencarian dengan cara melihat array secara berurutan dari elemen pertama hingga elemen terakhir.

Jika elemen yang dicari tidak ditemukan maka akan mengembalikan nilai -1 atau mengindikasikan bahwa elemen tersebut tidak ada dalam array.

Runtime

Best case: o(1), ketika elemen yang dicari berada di posisi pertama dalam array

Wort case: o(n) Ketika elemen yang dicari berada di posisi terakhir dalam array atau elemen tidak ada dalam array.

Alur

Binary search hanya dapat digunakan pada algoritma yang sudah terurut 

Pencarian dilakukan dengan cara membagi array enjadi dua bagian dan memeriksa elemen tengahnya.

jika elemen tengah sama dengan elen yang dicari, maka pencarian selesai

dan apabila elemen tengah lebih kecil dari eleme yang dicari, pencarian dilanjutkan pada separuh kanan array.Begitu pula sebaliknya.

proses tersebut berulang ulang sampai elemen yang dicari ditemukan.

Runtime:

Best case: O(1), ketika elemen yang dicari berada tepat di tengah array.

Worst case: O(log n), ketika elemen yang dicari tidak ada dalam array atau terletak di salah satu ujung array.

[3]
Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 
#### jawab
Dalam bahasa C++, struct adalah tipe data bentukan yang terdiri dari kumpulan tipe data lain.

Struct mirip seperti array, tapi struct bisa menampung lebih dari 1 jenis tipe data. Jika sebelumnya anda pernah belajar bahasa pemrograman Pascal, struct dalam bahasa C++ sangat mirip seperti tipe data record di Pascal.

```Cpp
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
```
output

Pada contoh program tersebt saya mendefinisikan sebuah struct dengan contoh mahasiswa dan menambah tiga anggota nama ,nim, umur,dan ipk. kemudian membuat variabel 'mhs1' dengan tipe 'mahasiswa'dan mengisi data kedalam variabel tersebut.

[4]




