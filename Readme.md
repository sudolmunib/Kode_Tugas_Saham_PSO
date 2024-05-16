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
Output
![Screenshot 2024-05-16 003425](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/c2e2d522-68e1-4010-9bc3-6eb7249635ea)
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
![Screenshot 2024-05-16 003600](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/9e225e9d-5679-4bba-a78b-dd7dc0356303)

Pada contoh program tersebt saya mendefinisikan sebuah struct dengan contoh mahasiswa dan menambah tiga anggota nama ,nim, umur,dan ipk. kemudian membuat variabel 'mhs1' dengan tipe 'mahasiswa'dan mengisi data kedalam variabel tersebut.

[4]
Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

#### Jawab
```Cpp
#include <iostream>
#include <cctype> 
using namespace std;

bool isPalindrome(string kalimat) {
    string cleanedString = "";

    for (int i = 0; i < kalimat.length(); ++i) {
        char c = kalimat[i];
        if (isalpha(c)) {
            cleanedString += tolower(c); // Convert huruf besar ke huruf kecil
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
        cin.ignore();

    } while (jawaban == 'y' || jawaban == 'Y');

    return 0;
}
```
Output
![Screenshot 2024-05-16 003745](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/567e53c6-b947-435c-90f8-da3b7b64f360)

[5]
Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. 

#### Jawab
```Cpp
#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s) {
    stack<int> tmpStack;

    while (!s.empty()) {
        int tmp = s.top();
        s.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp) {
            s.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    while (!tmpStack.empty()) {
        s.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main() {
    stack<int> s;

    // Push ubtuk masukan elemen-elemen ke dalam stack
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(1);
    s.push(2);

    // tampilan stack sebelum diurutkan
    cout << "Stack sebelum diurutkan: ";
    stack<int> tmp = s; 
    while (!tmp.empty()) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;

    // Menyortir stack
    sortStack(s);

    // tampilan stack setelah diurutkan
    cout << "Stack setelah diurutkan: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
```
output
![Screenshot 2024-05-16 003854](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/134f8b73-b328-4850-8480-6e962a3d6fdf)

[6]
Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

#### jawab
```Cpp
#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue penuh. Enqueue gagal." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; 
        }
        arr[rear] = val;
        cout << val << " ditambahkan ke dalam queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong. Dequeue gagal." << endl;
            return;
        } else if (front == rear) {
            cout << arr[front] << " dihapus dari queue." << endl;
            front = rear = -1;
        } else {
            cout << arr[front] << " dihapus dari queue." << endl;
            front = (front + 1) % MAX_SIZE; 
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        cout << "Isi queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue queue;

    cout << "Queue saat ini:" << endl;
    queue.display();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Queue saat ini:" << endl;
    queue.display();

    queue.dequeue();

    cout << "Queue saat ini setelah dequeue:" << endl;
    queue.display();

    return 0;
}
````
Output
![Screenshot 2024-05-16 003938](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/b9eac6c7-e9b7-4315-aee3-2f7e85c4bef7)

[7]
Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat.

```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class AnimalShelter {
private:
    queue<pair<string, int> > cats; 
    queue<pair<string, int> > dogs; 

    int timeStamp; 

public:
    AnimalShelter() {
        timeStamp = 0;
    }

    void enqueue(string type) {
        timeStamp++;
        if (type == "cat") {
            cats.push(make_pair(type, timeStamp));
        } else if (type == "dog") {
            dogs.push(make_pair(type, timeStamp));
        } else {
            cout << "Hewan yang diterima hanya kucing atau anjing." << endl;
        }
    }

    string dequeueAny() {
        if (cats.empty() && dogs.empty()) {
            return "Selter kosong.";
        } else if (cats.empty()) {
            string dog = dogs.front().first;
            dogs.pop();
            return dog;
        } else if (dogs.empty()) {
            string cat = cats.front().first;
            cats.pop();
            return cat;
        } else {
            if (cats.front().second < dogs.front().second) {
                string cat = cats.front().first;
                cats.pop();
                return cat;
            } else {
                string dog = dogs.front().first;
                dogs.pop();
                return dog;
            }
        }
    }

    string dequeueCat() {
        if (cats.empty()) {
            return "Tidak ada kucing dalam selter.";
        }
        string cat = cats.front().first;
        cats.pop();
        return cat;
    }

    string dequeueDog() {
        if (dogs.empty()) {
            return "Tidak ada anjing dalam selter.";
        }
        string dog = dogs.front().first;
        dogs.pop();
        return dog;
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("dog");
    shelter.enqueue("cat");

    cout << "Adopsi hewan: " << shelter.dequeueAny() << endl;
    cout << "Adopsi kucing: " << shelter.dequeueCat() << endl;
    cout << "Adopsi anjing: " << shelter.dequeueDog() << endl;

    return 0;
}
```
Outut
![Screenshot 2024-05-16 004041](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/0b3fcb9d-5cab-4de6-a45f-420c5f7b97ed)





