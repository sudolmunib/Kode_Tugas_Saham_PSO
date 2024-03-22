# <h1 align="center">Laporan Praktikum array</h1>
<p align="center">Abdul munib</p>
<p align="center">2311110004</p>

## Dasar Teori
Array merupakan kumpulan dari nilai-nilai data yang bertipe sama dalam urutan tertentu yang
menggunakan nama yang sama. Letak atau posisi dari elemen array ditunjukkan oleh suatu index. Dilihat dari
dimensinya array dapat dibagi menjadi Array dimensi satu, array dimensi dua dan array multi-dimensi. Setiap
elemen array dapat diakses melalui indeks. Dalam bahasa C indeks dimulai dari 0 (nol).
Itu berarti dengan menggunakan array jika kita ingin menyimpan lima nilai bertpe data int kita tidak perlu
mendeklarasikan lima variabel yang berbeda dengan tipe data int, kita cukup mendeklarasikan satu variabel array
engan tipe data int. 

## Guided 1

### 1. [Array tiga dimensi]

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {   
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z <<
"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z <<
"] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Kode di atas digunakan untuk untuk memasukkan elemen-elemen ke dalam array tiga dimensi dan kemudian menampilkan elemen-elemen tersebut.

## Guided 2

### 1. [Program Mencari Nilai Maksimal pada Array]

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan Panjang Array : ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array Ke- " << (i) << ": ";
        cin >> array [i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai Maksimum Adalah " << maks << " Berada Di Array Ke- " << lokasi << endl;
}
```
kodingn diatas untuk mencari nilai maksimum dari sebuah array yang diinputkan oleh pengguna.

### unguided 1
```C++
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

```
Kodingan tersebut adalah sebuah program dalam bahasa C++ yang memungkinkan pengguna untuk memasukkan elemen-elemen array, kemudian menampilkan array tersebut, serta memisahkan elemen-elemen array menjadi dua kelompok: nomor genap dan nomor ganjil. Program ini memberikan fungsionalitas untuk memasukkan elemen-elemen array, menampilkan array tersebut, dan memisahkan elemen-elemen array menjadi dua kelompok berdasarkan kriteria tertentu (genap dan ganjil).
#### Output:
![Screenshot 2024-03-23 002126](https://github.com/sudolmunib/tugas-praktikum2-munib/assets/162574378/9891e854-b7dd-4347-b58b-386a0637a4f2)
hasil outputan tersebut untuk mencari data array ganjil dan genap
### unguided2

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x_size, y_size, z_size;
    cout << "Masukkan ukuran array (x y z): ";
    cin >> x_size >> y_size >> z_size;
    vector<vector<vector<int> > > array(x_size, vector<vector<int> >(y_size, vector<int>(z_size)));
    cout << "Masukkan elemen-elemen array:\n";
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> array[x][y][z];
            }
        }
    }
    cout << "\nArray yang dimasukkan:\n";
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << array[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

```
Kode tersebut adalah kode untuk memasukkan elemen-elemen ke dalam array tiga dimensi dengan ukuran yang ditentukan oleh pengguna, kemudian menampilkannya kembali.

#### Full code Screenshot:
![Screenshot 2024-03-23 000835](https://github.com/sudolmunib/tugas-praktikum2-munib/assets/162574378/d52c2ccc-41d6-4845-bf4a-7097f949541f)

Hasil Output tersebut merupakan hasil dari program yang meminta pengguna untuk memasukkan elemen-elemen array tiga dimensi dengan ukuran yang telah ditentukan (4x2x3).
### unguided 3
```C++
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

```
Kode tersebut adalah untuk memasukkan angka-angka ke dalam sebuah array dan kemudian melakukan operasi tertentu tergantung pada pilihan pengguna, seperti mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array.
#### Full code Screenshot:
![Screenshot 2024-03-23 003034](https://github.com/sudolmunib/tugas-praktikum2-munib/assets/162574378/0e5c9396-a2a9-4a7d-971e-ccf0250cee1b)
pada outputan tersebut angka yang dimasukan 2 sampai 5 dan yang diperintahkan mencari nilai minimum maka nilai minimum nya 2

## Kesimpulan
Array merupakan kumpulan nilai-nilai data dengan tipe data yang sama yang disusun dalam urutan tertentu menggunakan nama yang sama. Setiap elemen dalam array diidentifikasi oleh indeksnya.Array dapat memiliki berbagai dimensi, termasuk array satu dimensi, dua dimensi, dan multi-dimensi, tergantung pada kompleksitas struktur data yang dibutuhkan.

## Referensi
[1] Cheltenham Computer Training, C Programming, www.cctglobal.com, United Kingdom, 1997

[2]Deitel & Deitel, C How to Program 3rd Edition, Prentice Hall, New Jersey, 2001
