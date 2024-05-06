# <h1 align="center">Laporan Praktikum Modul 7 Stack</h1>

<p align="center">Nama: Abdul munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

## DASAR TEORI 

Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting. Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Piring ditambahkan ke tumpukan saat mereka dibersihkan dan ditempatkan di bagian atas. Ketika sebuah piring dibutuhkan, diambil dari bagian atas tumpukan. Piring pertama yang ditempatkan di tumpukan adalah yang terakhir digunakan.

Stack meliputi konsep utama dari struktur data tersebut, yaitu Last In, First Out (LIFO). Ini berarti elemen terakhir yang dimasukkan ke dalam stack akan menjadi yang pertama dikeluarkan. Prinsip LIFO ini menggambarkan cara stack menyusun elemen-elemennya, mirip dengan menumpuk benda dalam kehidupan sehari-hari, di mana yang terakhir ditambahkan adalah yang pertama diambil. Dua operasi dasar dari stack adalah push, yang menambahkan elemen ke dalam stack, dan pop, yang mengeluarkan elemen dari stack [1]. Operasi push menempatkan elemen baru di atas elemen-elemen yang sudah ada dalam stack, sementara operasi pop menghapus dan mengembalikan elemen paling atas dari stack. 

Stack dapat diimplementasikan menggunakan array atau linked list. Stack dapat diimplementasikan menggunakan array atau linked list. Dalam implementasi menggunakan array, elemen-elemen stack disimpan dalam array dan operasi push dan pop mengubah indeks yang menunjukkan posisi atas stack. Dalam implementasi menggunakan linked list, setiap elemen stack memiliki referensi ke elemen di bawahnya, sehingga operasi push dan pop hanya memerlukan penambahan atau penghapusan elemen di ujung linked list [2]. Kelebihan dari implementasi stack menggunakan array adalah mudah untuk diimplementasikan, tetapi memiliki kekurangan yang tidak terlalu dinamis karena tidak dapat tumbuh dan menyusut sesuai dengan kebutuhan saat proses. Sementara itu, implementasi stack menggunakan linked list dapat bertambah dan berkurang sesuai dengan kebutuhan saat runtime [3].

Stack digunakan dalam berbagai aplikasi, termasuk dalam manajemen memori komputer, evaluasi ekspresi matematika, pemanggilan fungsi dalam bahasa pemrograman, dan pengurutan data. Pemahaman dasar tentang konsep-konsep ini penting untuk memahami cara kerja stack dan menerapkannya dalam pemrograman komputer.

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
Program tersebut adalah implementasi sederhana dari struktur data tumpukan (stack) mengguna65rkan array dalam bahasa pemrograman C++. Saat program dijalankan, ia menyediakan fungsi-fungsi dasar untuk manipulasi tumpukan buku. 

Tumpukan direpresentasikan oleh sebuah array `arrayBuku`, yang memiliki batasan maksimum elemen yang dapat disimpan ditentukan oleh variabel `maksimal`. Variabel `top` mengindikasikan posisi teratas dalam tumpukan, dimulai dari 0.

Pertama-tama, program menyediakan fungsi `pushArrayBuku()` untuk menambahkan data buku ke dalam tumpukan. Fungsi ini memeriksa apakah tumpukan sudah penuh dengan memanggil `isFull()`. Jika tumpukan belum penuh, data buku ditambahkan ke dalam tumpukan pada posisi `top`, dan `top` ditingkatkan.

Selanjutnya, terdapat fungsi `popArrayBuku()` untuk menghapus data buku dari tumpukan. Program memeriksa apakah tumpukan kosong dengan menggunakan `isEmpty()`. Jika tumpukan tidak kosong, data buku pada posisi `top - 1` dihapus, dan nilai `top` dikurangi.

Fungsi `peekArrayBuku()` memungkinkan pengguna untuk melihat data buku pada posisi tertentu di dalam tumpukan tanpa menghapusnya. Ini dilakukan dengan mengakses elemen pada posisi yang diinginkan dari tumpukan.

Program juga menyediakan fungsi `changeArrayBuku()` untuk mengubah data buku pada posisi tertentu dalam tumpukan. Ini memerlukan pemeriksaan apakah posisi yang dimasukkan valid, dan jika iya, data buku pada posisi tersebut diubah.

Pada akhirnya, program memberikan kemampuan untuk menghapus semua data buku dari tumpukan menggunakan fungsi `destroyArrayBuku()`.

Dengan menggunakan fungsi-fungsi ini, program menyediakan antarmuka sederhana untuk mengelola tumpukan buku, termasuk penambahan, penghapusan, dan modifikasi data, serta memberikan informasi tentang status tumpukan seperti apakah penuh atau kosong, dan jumlah elemen yang ada di dalamnya.

## TUGAS PRAKTIKUM
### 1.Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
#### Kode Program 
```C++
#include <iostream>
#include <cctype> // Untuk isalpha
using namespace std;

bool isPalindrome(string kalimat) {
    string cleanedString = "";

    // Membuat cleanedString tanpa spasi atau tanda baca
    for (int i = 0; i < kalimat.length(); ++i) {
        char c = kalimat[i];
        if (isalpha(c)) {
            cleanedString += tolower(c); // Convert huruf besar ke huruf kecil
        }
    }

    // Membandingkan kalimat asli dengan kalimat yang dibalik
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
#### Interpretasi
Cara kerja dari program: 

Program tersebut bertujuan untuk menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak menggunakan konsep stack. Palindrom adalah kalimat yang dapat dibaca sama baik dari depan maupun dari belakang. 

Pertama, program meminta pengguna untuk memasukkan sebuah kalimat. Kemudian, kalimat tersebut diproses dengan menghapus spasi dan mengubah semua huruf menjadi huruf kecil agar program tidak sensitif terhadap huruf kapital atau kecil.

Selanjutnya, program membuat sebuah stack untuk menyimpan karakter-karakter dari kalimat yang telah diproses. Setiap karakter dari kalimat dimasukkan ke dalam stack.

Setelah semua karakter dimasukkan, karakter-karakter tersebut diambil kembali dari stack satu per satu. Karena stack bekerja berdasarkan prinsip LIFO (Last In, First Out), karakter terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Sehingga kalimat terbalik akan terbentuk.

Selanjutnya, kalimat terbalik dibandingkan dengan kalimat asli. Jika keduanya sama, maka kalimat tersebut merupakan palindrom. Jika tidak, maka bukan palindrom. Program akan menampilkan pesan sesuai dengan hasil pengecekan.

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?
#### Kode Program 
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
}

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
#### Interpretasi
Penjelasan Output: 

Output program akan menampilkan hasil pembalikan kalimat yang dimasukkan pengguna. Setelah pengguna memasukkan kalimat, program akan membalikkan kalimat tersebut menggunakan konsep stack dan kemudian menampilkan hasil pembalikan. Program hanya membalikkan urutan karakter dalam kalimat tanpa mengubah urutan kata-kata.

Misalnya:
1. Jika memasukkan kalimat "Telkom Purwokerto", maka output program akan menampilkan:
otrekowruP mokleT

Masukkan kalimat: Telkom Purwokerto

Hasil pembalikan: otrekowruP mokleT

2. Jika memasukkan kalimat "Institut Teknologi Telkom Purwokerto" maka output program akan menampilkan: otrekowruP mokleT igolonkeT tutitsnI

Masukkan kalimat: Institut Teknologi Telkom Purwokerto 

Hasil pembalikan:  otrekowruP mokleT igolonkeT tutitsnI

3. Jika memasukkan kalimat "Sains Data" maka output program akan menampilkan: ataD sniaS

Masukkan kalimat: Sains Data

Hasil pembalikan: ataD sniaS

Penjelasan source codenya beserta operasi/fungsi: 

Program yang diberikan bertujuan untuk membalikkan urutan karakter dalam sebuah kalimat yang dimasukkan pengguna menggunakan konsep stack. Pada awalnya, pustaka `iostream`, `stack`, dan `string` diimpor untuk mendukung input-output standar, implementasi stack, dan manipulasi string. Dengan menggunakan `using namespace std;`, program menghindari penulisan `std::` sebelum setiap pemanggilan fungsi dari pustaka standar.

Fungsi `reverseSentence` bertanggung jawab untuk membalikkan kalimat. Fungsi ini menerima satu parameter, yaitu kalimat yang akan dibalikkan. Dalam fungsi ini, sebuah objek stack dibuat untuk menyimpan karakter-karakter dari kalimat. Setiap karakter dari kalimat dimasukkan ke dalam stack. Kemudian, karakter-karakter tersebut diambil kembali dari stack satu per satu untuk membangun ulang kalimat terbalik. Kalimat terbalik dikembalikan sebagai nilai balik dari fungsi ini.

Fungsi utama `main` memulai dengan mendeklarasikan sebuah string `inputSentence` untuk menyimpan kalimat yang dimasukkan pengguna. Menggunakan `getline(cin, inputSentence)`, program meminta pengguna untuk memasukkan kalimat, memungkinkan pengguna untuk memasukkan kalimat dengan spasi di dalamnya. Selanjutnya, program memanggil fungsi `reverseSentence` dengan `inputSentence` sebagai argumen dan menyimpan hasilnya dalam string `reversed`. Terakhir, program menampilkan hasil pembalikan kalimat menggunakan `cout`.

Cara Kerja Program: 

Program ini adalah program sederhana yang bertujuan untuk membalikkan urutan karakter dalam sebuah kalimat yang dimasukkan oleh pengguna. Pertama-tama, program meminta pengguna untuk memasukkan sebuah kalimat melalui terminal. Setelah pengguna memasukkan kalimat, program akan menyimpannya dalam variabel `inputSentence`. Selanjutnya, program akan memanggil fungsi `reverseSentence` yang bertugas untuk membalikkan kalimat tersebut menggunakan konsep stack. Dalam fungsi `reverseSentence`, setiap karakter dari kalimat dimasukkan ke dalam stack satu per satu. Setelah semua karakter dimasukkan, karakter-karakter tersebut diambil kembali dari stack satu per satu untuk membangun ulang kalimat terbalik. Hasil pembalikan kalimat tersebut kemudian akan ditampilkan ke layar menggunakan `cout`. Dengan memisahkan logika pembalikan kalimat ke dalam fungsi `reverseSentence`, program menjadi lebih terstruktur dan mudah dipahami.

## KESIMPULAN 
Stack adalah struktur data yang penting dalam pemrograman komputer yang mengikuti prinsip Last In, First Out (LIFO), yang berarti elemen terakhir yang dimasukkan ke dalam tumpukan adalah yang pertama kali dikeluarkan. Konsep ini mirip dengan menumpuk buku di atas meja, di mana buku terakhir yang diletakkan di atas tumpukan adalah yang pertama kali diambil. Stack memungkinkan penumpukan dan penghapusan elemen dengan efisiensi tinggi, dan digunakan dalam berbagai aplikasi, termasuk dalam pengelolaan memori komputer, evaluasi ekspresi matematika, dan manajemen pemanggilan fungsi dalam bahasa pemrograman. Dengan memahami prinsip-prinsip dasar dan operasi stack, para pengembang dapat meningkatkan efisiensi dan keandalan dalam pengembangan perangkat lunak.

## DAFTAR PUSTAKA
[1] R. Firliana, R. Rina, dan P. Kasih, "Struktur Data yang Terorganisir," dalam Algoritma dan Pemrograman C++, Adjie Media Nusantara, Hal.1-82, 2019.

[2] E. L. Pratiwi, Konsep Dasar Algoritma dan Pemrograman dengan Bahasa C++. Banjarmasin: Poiban Press, 2020.

[3] R. Thareja, "Data structures using C", New Delhi: OXFOR, 2019.