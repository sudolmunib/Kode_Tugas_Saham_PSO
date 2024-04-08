# <h1 align="center">Laporan Praktikum Searching</h1>
<p align="center">Abdul munib</p>
<p align="center">2311110004</p>

## Dasar Teori

Algoritma sorting adalah suatu metode atau teknik untuk mengurutkan data atau elemen-elemen dalam suatu struktur data secara teratur. Algoritma sorting merupakan salah satu konsep penting dalam pemrograman, tujuannya untuk mengubah data yang tidak teratur menjadi urutan yang teratur, misalnya dari data yang tidak terurut menjadi data yang terurut menaik atau menurun.
Jenis jenis Algoritma sorting yang akan dipelajari antara lain:
### 1. Bubble Sort
Bubble Sort adalah salah satu algoritma sorting yang paling sederhana. Algoritma ini bekerja dengan membandingkan elemen-elemen berpasangan dalam daftar dan menukar mereka jika diperlukan. Proses ini terus berlanjut hingga semua elemen berada dalam urutan yang benar.

## Guided 1
```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tap;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; j++){
            if(arr[i] > arr[i + 1]){
                tap = arr[i];
                arr[i] = arr[i +1];
                arr[i + 1] = tap;
                not_sorted = true;
            }// end off it 
        }// end for loop
        
    }// end of while loop
}// end of buble short 

void print_array(double a[], int length) {

    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main(){
    int length = 4;
    double a[] = {15.7, 87.3, 7.5, 88.5, 67.9};
    cout << "urutan bilangan sebelum sorting : " << endl;
    print_array(a, length);
    bubble_sort(a, length);
    cout << "\n urutan bilangan setelah sortiing: " << endl;
    print_array(a, length);
}
```
kodingan diatas digunakan untuk mengurutkan array dari bilangan yang tidak terurut terbesar hingga terkecil dengan mendefinisikan bubble_sort(double arr[], int length). 
### 2. Insertion Sort
Insertion Sort merupakan sebuah teknik pengurutan dengan cara membandingkan dan mengurutkan dua data pertama pada array, kemudian membandingkan data para array berikutnya apakah sudah berada di tempat semestinya. Algorithma insertion sort seperti proses pengurutan kartu yang berada di tangan kita. Algorithma ini dapat mengurutkan data Ascending dan Descending.Insertion Sort membandingkan setiap elemen dengan elemen-elemen sebelumnya dan memasukkannya ke dalam posisi yang benar dalam daftar yang terurut. Algoritma ini efisien untuk daftar kecil.

## Guided 2
```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
}

void print_array(char a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);
    insertion_sort(a, length);
    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}

```
 Kode diatas adalah kode insertion sort yang berfungsi untuk mengurutkan array karakter array dari yang terbesar hingga yang terkecil. insertion sort ini membandingkan setiap elemen array dengan elemen-elemen sebelumnya, dan jika ditemukan elemen yang lebih kecil, maka elemen tersebut dipindahkan ke posisi yang sesuai untuk memastikan array tetap terurut.

## Unguided
### Tugas
### [1]
1  Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima
lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS
sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS
mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma
Selection Sort

##### input
```C++
#include <iostream>
using namespace std;

void selection_sort(double arr[], int length) {
    int i, j, minIndex;
    double temp;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void print_array(double a[], int length) {
    for(int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 10;
    double a[] = {3.8, 2.9, 3.3, 4.0, 2.4, 3.6, 4.9, 4.6, 5.5, 5.6};
    cout << "IPS sebelum sorting: " << endl;
    print_array(a, length);
    selection_sort(a, length);
    cout << "\nIPS setelah sorting: " << endl;
    print_array(a, length);
    return 0;
}

```
##### Output
![Screenshot 2024-03-31 032925](https://github.com/sudolmunib/tugas-praktikum-munib/assets/162574378/10175d6d-a133-4297-b008-880c5d27f3eb)

kode diatas adalah kode untuk mengurutkan dengan menggunakan Selection sort Algoritma ini digunakan untuk mengurutkan Array dari nilai nilai tertentu.

Dan fungsi selection_sort sendiri merupakan implementasi dari algoritma pengurutan seleksi. Metode ini bekerja dengan mencari elemen terkecil di antara elemen-elemen yang belum terurut, lalu menukarnya dengan elemen pertama pada sisa array. Dalam konteks kode ini, array arr yang akan diurutkan serta panjang array length diberikan sebagai parameter.

Fungsi print_array berguna untuk menampilkan isi array ke layar. Dalam konteks ini, array a dan panjang array length diberikan sebagai parameter.

Fungsi utama main() dimulai dengan menetapkan panjang array sebagai 10 (int length = 10;). Kemudian, sebuah array a diinisialisasi dengan nilai-nilai IPS yang akan diurutkan. Pesan "IPS sebelum sorting: " ditampilkan di layar, diikuti dengan pemanggilan fungsi print_array untuk menampilkan nilai-nilai IPS sebelum diurutkan. Selanjutnya, fungsi selection_sort dipanggil untuk mengurutkan array. Setelah proses pengurutan selesai, pesan "IPS setelah sorting: " diprint di layar, dilanjutkan dengan pemanggilan fungsi print_array untuk menampilkan nilai-nilai IPS setelah diurutkan.

### [2]
2 Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo,
dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan
menggunakan algoritma Bubble Sort

##### Input

```C++
#include <iostream>
#include <string>

using namespace std;

void bubble_sort(string arr[], int length) {
    bool not_sorted = true;
    int j = 0;
    string tmp;
    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void print_array(string a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    const int length = 12;
    string names[length] = {"wulan", "siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi", "munib"};
    cout << "Nama-nama sebelum diurutkan: " << endl;
    print_array(names, length);
    bubble_sort(names, length);
    cout << "\nNama-nama setelah diurutkan sesuai alfabet: " << endl;
    print_array(names, length);
    
    return 0;
}

```
#### Output:
![Screenshot 2024-03-31 040324](https://github.com/sudolmunib/tugas-praktikum-munib/assets/162574378/83f40923-7a05-4496-815a-8daef958928e)
kode tersebut adalah kode buat mengurutkan nama dari alfabet dengan menggunakan Fungsi bubble_sort. fungsi bubbel_sort sendiri diggunakan untuk menyusun urutan array string menggunakan metode pengurutan gelembung. Proses ini mulai dengan mengatur nilai boolean not_sorted sebagai true, yang menandakan bahwa array belum terurut seluruhnya. Selanjutnya, dilakukan iterasi pada setiap elemen dalam array. Jika ada pertukaran antara dua elemen berturut-turut karena posisinya tidak benar, maka nilai not_sorted diubah menjadi true untuk menunjukkan bahwa array masih belum terurut sepenuhnya. Proses iterasi ini berlanjut sampai tidak ada lagi pertukaran yang terjadi, yang menunjukkan bahwa array telah terurut dengan benar.
### [3]
3 Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user
untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting
secara menaik (ascending) dan menurun (descending)
##### input
```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;
    char characters[n];
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }
    cout << "Urutan karakter sebelum sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    sort(characters, characters + n);
    cout << "Karakter setelah diurutkan secara ascending: ";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    sort(characters, characters + n, greater<char>());
    cout << "Karakter setelah diurutkan secara descending: ";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    
    return 0;
}

```

#### output
![Screenshot 2024-03-31 041725](https://github.com/sudolmunib/tugas-praktikum-munib/assets/162574378/bd103131-ad78-4831-8829-d29b160ddf19)

kodimgam untuk meginputkan suatu bilangan dengan n sebagai karakter dan akan muncul di layar untuk meminta pengguna memasukkan n karakter satu per satu menggunakan sebuah perulangan for.

Setelah pengguna selesai memasukkan karakter-karakter, pesan "Urutan karakter sebelum diurutkan: " akan ditampilkan di layar, diikuti dengan mencetak karakter-karakter yang dimasukkan pengguna menggunakan sebuah perulangan for.

Selanjutnya, fungsi sort dari pustaka <algorithm> digunakan untuk mengurutkan karakter-karakter dalam array secara menaik (ascending). Setelah pengurutan selesai, pesan "Karakter setelah diurutkan secara ascending: " akan ditampilkan di layar, diikuti dengan mencetak karakter-karakter yang sudah diurutkan.

Fungsi sort juga digunakan untuk mengurutkan karakter-karakter dalam array secara menurun (descending). Argumen tambahan greater<char>() digunakan untuk menentukan urutan penurunan. Setelah pengurutan selesai, pesan "Karakter setelah diurutkan secara descending: " akan ditampilkan di layar, diikuti dengan mencetak karakter-karakter yang sudah diurutkan secara menurun.
Program akan selesai dengan mengembalikan nilai 0.

## Kesimpulan
dapat disimpulkan bahwa kedua algoritma ini berguna terutama untuk dataset yang relatif kecil atau telah hampir terurut. Namun, dalam kasus dataset yang sangat besar atau sangat tidak terurut, disarankan untuk mempertimbangkan penggunaan algoritma pengurutan lain yang memiliki kompleksitas waktu yang lebih optimal. Hal ini penting untuk memastikan efisiensi dalam pengolahan data yang membutuhkan pengurutan dalam skala besar atau dengan kompleksitas yang tinggi.
## Referensi
[1] Anisya Sonita, Febrian Nurtaneo. 2015. Analisis Perbandingan Algoritma Bubble sort, Merge sort, dan Quick Sort dalam Proses Pengurutan Kombinasi Angka dan Huruf. Jurnal Pseudocode, Vol. 2 No.2.

[2] Anisya Sonita, Febrian Nurtaneo. 2015. Analisis Perbandingan Algoritma Bubble sort.