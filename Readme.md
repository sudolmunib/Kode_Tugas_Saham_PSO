# <h1 align="center">Laporan Praktikum Modul 7 Stack</h1>

<p align="center">Nama: Abdul munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

## DASAR TEORI 

Stack merupakan sebuah struktur data yang digunakan untuk menyimpan sejumlah objek atau variabel. Sesuai dengan namanya, stack sering kali terlihat seperti tumpukan dalam bentuk fisik. Karakteristik khas dari stack adalah penggunaan aturan LIFO (Last In, First Out). Artinya, data yang terakhir dimasukkan ke dalam stack akan menjadi data pertama yang diambil atau dikeluarkan. 

Konsep ini mirip dengan tumpukan buku, di mana buku yang terakhir diletakkan di atas tumpukan harus diambil terlebih dahulu sebelum bisa mengakses buku yang berada di bagian bawah tumpukan.

Operasi utama pada stack meliputi:

- Push, yaitu menambahkan elemen baru ke dalam stack pada posisi teratas.

- Pop, yaitu menghapus elemen teratas dari stack dan mengembalikan nilainya.

- Peek atau Top, yaitu mengecek elemen teratas dari stack tanpa menghapusnya.

- IsEmpty, yaitu memeriksa apakah stack kosong atau tidak.

- Size, yaitu mengembalikan jumlah elemen dalam stack.

Stack sering digunakan dalam berbagai konteks pemrograman, seperti manajemen memori, pemanggilan fungsi, evaluasi ekspresi matematika, dan manajemen tumpukan panggilan saat melakukan rekursi.

## LANGKAH PRAKTIKUM 

### Guided 1
#### Kode Program 
```C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] == "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah "  << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack suda penuh?" << isFull() << endl;
    cout << "Apakah data stack kososng?" << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();
    
    cout << "Banyakanya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}
```
#### Output

![Screenshot 2024-05-06 125507](https://github.com/sudolmunib/tugas-praktikum7-Stack/assets/162574378/c5a587c3-613a-46c6-89d3-928c990b3fd8)


#### Interpretasi
Program di atas adalah implementasi sederhana dari struktur data tumpukan (stack) menggunakan array dalam bahasa pemrograman C++. Program ini menyediakan fungsi-fungsi dasar untuk manipulasi tumpukan buku.

Tumpukan direpresentasikan oleh sebuah array arrayBuku, dengan batasan maksimum elemen yang dapat disimpan ditentukan oleh variabel maksimal. Variabel top menunjukkan posisi teratas dalam tumpukan, dimulai dari 0.

- Fungsi pushArrayBuku(): Menambahkan data buku ke dalam tumpukan. Fungsi ini memeriksa apakah tumpukan sudah penuh dengan menggunakan isFull(). Jika tumpukan belum penuh, data buku ditambahkan pada posisi top, dan nilai top ditingkatkan.
- Fungsi popArrayBuku(): Menghapus data buku dari tumpukan. Program memeriksa apakah tumpukan kosong menggunakan isEmpty(). Jika tidak kosong, data buku pada posisi top - 1 dihapus, dan nilai top dikurangi.
- Fungsi peekArrayBuku(): Memungkinkan pengguna untuk melihat data buku pada posisi tertentu di dalam tumpukan tanpa menghapusnya. Ini dilakukan dengan mengakses elemen pada posisi yang diinginkan dari tumpukan.
- Fungsi changeArrayBuku(): Mengubah data buku pada posisi tertentu dalam tumpukan. Fungsi ini memeriksa apakah posisi yang dimasukkan valid, dan jika ya, data buku pada posisi tersebut diubah.
- Fungsi destroyArrayBuku(): Menghapus semua data buku dari tumpukan.


Melalui fungsi-fungsi tersebut, program menyediakan antarmuka sederhana untuk mengelola tumpukan buku, termasuk penambahan, penghapusan, dan modifikasi data, serta memberikan informasi tentang status tumpukan seperti apakah penuh atau kosong, dan jumlah elemen yang ada di dalamnya.

## TUGAS PRAKTIKUM
[1]
Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
#### Input
```C++
#include <iostream>
#include <cctype> 
using namespace std;

bool isPalindrome(string kalimat) {
    string cleanedString = "";

    for (int i = 0; i < kalimat.length(); ++i) {
        char c = kalimat[i];
        if (isalpha(c)) {
            cleanedString += tolower(c); 
        }
    }

    int left = 0, right = cleanedString.length() - 1;
    while (left < right) {
        if (cleanedString[left] != cleanedString[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string kalimat;
    char jawaban;
    do {
        cout << "Kalimat: ";
        getline(cin, kalimat);

        if (isPalindrome(kalimat)) {
            cout << "Kalimat tersebut adalah palindrom." << endl;
        } else {
            cout << "Kalimat tersebut adalah bukan palindrom." << endl;
        }

        cout << "Coba lagi? (y/n): ";
        cin >> jawaban;
        cin.ignore(); // Membersihkan newline di buffer
    } while (jawaban == 'y' || jawaban == 'Y');

    return 0;
}
```
#### Output
![Screenshot 2024-05-06 125717](https://github.com/sudolmunib/tugas-praktikum7-Stack/assets/162574378/bd4c13ae-e88c-4c60-aa0f-c29d6ed862c6)
## Interpretasi
Program tersebut adalah perogram untuk menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak menggunakan konsep stack. pengertian Palindrom sendiri adalah kalimat yang dapat dibaca sama baik dari depan maupun dari belakang atau dibalik.

Berikut adalah cara kerja dari program tersebut:

Meminta Input Kalimat: Program meminta pengguna untuk memasukkan sebuah kalimat.
Pemrosesan Kalimat: Kalimat yang dimasukkan oleh pengguna diproses dengan menghapus spasi dan mengubah semua huruf menjadi huruf kecil agar program tidak sensitif terhadap huruf kapital atau kecil.
- Penggunaan Stack: Program membuat sebuah stack untuk menyimpan karakter-karakter dari kalimat yang telah diproses. Setiap karakter dari kalimat dimasukkan ke dalam stack.
- Pengecekan Palindrom: Setelah semua karakter dimasukkan, karakter-karakter tersebut diambil kembali dari stack satu per satu. Karena stack bekerja berdasarkan prinsip LIFO (Last In, First Out), karakter terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Sehingga kalimat terbalik akan terbentuk.
- Perbandingan dengan Kalimat Asli: Kalimat terbalik dibandingkan dengan kalimat asli. Jika keduanya sama, maka kalimat tersebut merupakan palindrom. Jika tidak, maka bukan palindrom.
Hasil dari Program tersebut menampilkan pesan sesuai dengan hasil pengecekan, apakah kalimat tersebut merupakan palindrom atau bukan.

[2]
Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?
#### input
```C++
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
}   ``

int main() {
    string kalimat;

    cout << "Kalimat: ";
    getline(cin, kalimat);

    reverseSentence(kalimat);

    return 0;
}

```
#### Output
![Screenshot 2024-05-06 130135](https://github.com/sudolmunib/tugas-praktikum7-Stack/assets/162574378/7306b379-ff56-400d-8d1a-32e818f7ae7e)
## Interpretasi

Program tersebut merupakan program sederhana yang bertujuan untuk menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak menggunakan konsep stack. Sebuah kalimat palindrom adalah kalimat yang dapat dibaca sama baik dari depan maupun dari belakang.

setelah hasil input keluar Pengguna diminta untuk memasukkan sebuah kalimat melalui terminal.
Setelah kalimat dimasukkan, program akan menampilkan hasil apakah kalimat tersebut merupakan palindrom atau bukan. Seperti yang sudah dijelaskan sebelumya palindrom adalah kalimat yang dapat dibaca sama baik dari depan maupun dari belakang atau dibalik.

Penjelasan Source Code dan Operasi/Fungsi:

Program dimulai dengan mendeklarasikan sebuah string kalimat untuk menyimpan input pengguna.
Kemudian, program memanggil fungsi isPalindrome(kalimat) untuk memeriksa apakah kalimat tersebut palindrom atau tidak.
- Fungsi isPalindrome(string kalimat) digunakan untuk melakukan pemrosesan kalimat:
- Kalimat diproses dengan menghapus spasi dan mengubah semua huruf menjadi huruf kecil agar program tidak sensitif terhadap huruf kapital atau kecil.
Setiap karakter dari kalimat dimasukkan ke dalam stack.
- Setelah semua karakter dimasukkan, karakter-karakter tersebut diambil kembali dari stack satu per satu untuk membandingkan apakah kalimat tersebut merupakan palindrom atau tidak.
- Hasil dari pengecekan palindrom kemudian dikembalikan oleh fungsi isPalindrome() dan ditampilkan ke layar.


## KESIMPULAN 
Stack adalah struktur data yang penting dalam pemrograman komputer yang mengikuti prinsip Last In, First Out (LIFO). Ini berarti elemen terakhir yang dimasukkan ke dalam stack adalah yang pertama kali dikeluarkan, mirip dengan menumpuk buku di atas meja di mana buku terakhir yang diletakkan di atas tumpukan adalah yang pertama kali diambil. Stack memungkinkan penumpukan dan penghapusan elemen dengan efisiensi tinggi, sehingga sering digunakan dalam berbagai aplikasi.

Konsep stack digunakan dalam banyak konteks, termasuk pengelolaan memori komputer, evaluasi ekspresi matematika, dan manajemen pemanggilan fungsi dalam bahasa pemrograman. Dalam pengelolaan memori, stack menyediakan struktur untuk alokasi dan dealokasi memori secara otomatis untuk variabel lokal dan informasi panggilan fungsi. Dalam evaluasi ekspresi matematika, stack digunakan untuk mengubah ekspresi infix menjadi postfix, yang kemudian dievaluasi dengan menggunakan stack. Selain itu, stack juga digunakan dalam pelacakan backtracking dan dalam validasi tumpukan dalam berbagai algoritma.

Dengan pemahaman yang baik tentang prinsip-prinsip dasar dan operasi stack, para pengembang dapat meningkatkan efisiensi dan keandalan dalam pengembangan perangkat lunak. Kemampuan untuk menggunakan stack dengan baik memungkinkan pengembang untuk merancang algoritma yang lebih efisien dan menerapkan solusi yang lebih optimal untuk berbagai masalah pemrograman.

## DAFTAR PUSTAKA
[1] Cormen, Thomas H., Leirserson, Charles E., Rivest, Ronald L.,
Introduction to Algorithms, McGraw-Hill Book Company, 1990.

[2] Liem, Inggriani, Diktat Kuliah Algoritma dan pemrograman Prosedural,
Jurusan Teknik Informatika ITB, 1996.