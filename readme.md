# <h1 align="center">Laporan Praktikum Linked List</h1>
<p align="center">Abdul munib</p>
<p align="center">2311110004</p>

## Dasar Teori Linked List

Linked List atau dikenal juga dengan sebutan senarai berantai adalah struktur data yang 
terdiri dari urutan record data dimana setiap record memiliki field yang menyimpan 
alamat/referensi dari record selanjutnya (dalam urutan). Elemen data yang dihubungkan 
dengan link pada Linked List disebut Node. Biasanya didalam suatu linked list, terdapat 
istilah head dan tail. Head adalah elemen yang berada pada posisi pertama dalam suatu linked 
list. Tail adalah elemen yang berada pada posisi terakhir dalam suatu linked list. 

### Macam macam Linked List
1. single Linked list

Single Linked List merupakan suatu linked list yang hanya memiliki satu variabel pointer 
saja. Dimana pointer tersebut menunjuk ke node selanjutnya. Biasanya field pada tail 
menunjuk ke NULL. Contoh : 
![Screenshot 2024-04-28 214745](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/e729706b-7f63-40dc-8f56-57003c8998b4)

## Guided 1
```C++
#include <iostream> 
using namespace std; 

// Deklarasi Struct Node 
struct Node { 
    int data; 
    Node *next; 
}; 

Node *head; 
Node *tail; 

// Inisialisasi Node 
void init() { 
    head = NULL; 
    tail = NULL; 
} 

// Pengecekan apakah Linked List kosong
bool isEmpty() { 
    return head == NULL; 
} 

// Tambah Node di Depan 
void insertDepan(int nilai) { 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 

    if (isEmpty() == true) { 
        head = tail = baru; 
    } else { 
        baru->next = head; 
        head = baru; 
    } 
} 

// Tambah Node di Belakang 
void insertBelakang(int nilai) { 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 

    if (isEmpty() == true) { 
        head = tail = baru; 
    } else { 
        tail->next = baru; 
        tail = baru; 
    } 
} 

// Hitung Jumlah Node 
int hitungList() { 
    Node *hitung = head; 
    int jumlah = 0; 

    while (hitung != NULL) { 
        jumlah++; 
        hitung = hitung->next; 
    } 

    return jumlah; 
} 

// Tambah Node di Tengah 
void insertTengah(int data, int posisi) { 
    if (posisi < 1 || posisi > hitungList()) { 
        cout << "Posisi diluar jangkauan" << endl; 
    } else if (posisi == 1) { 
        cout << "Posisi bukan posisi tengah" << endl; 
    } else { 
        Node *baru, *bantu; 
        baru = new Node(); 
        baru->data = data; 

        bantu = head; 
        int nomor = 1; 
        while (nomor < posisi - 1) { 
            bantu = bantu->next; 
            nomor++; 
        } 

        baru->next = bantu->next; 
        bantu->next = baru; 
    } 
} 

// Hapus Node di Depan 
void hapusDepan() { 
    Node *hapus; 
    if (isEmpty() == false) { 
        hapus = head; 
        head = head->next; 
        delete hapus; 
    } else { 
        cout << "List kosong!" << endl; 
    } 
} 

// Hapus Node di Belakang 
void hapusBelakang() { 
    Node *hapus; 
    Node *bantu; 
    if (isEmpty() == false) { 
        if (head != tail) { 
            hapus = tail; 
            bantu = head; 
            while (bantu->next != tail) { 
                bantu = bantu->next; 
            } 
            tail = bantu; 
            tail->next = NULL; 
        } else { 
            hapus = head; 
            head = tail = NULL; 
        } 
        delete hapus; 
    } else { 
        cout << "List kosong!" << endl; 
    } 
} 

// Hapus Node di Tengah 
void hapusTengah(int posisi) { 
    Node *bantu, *hapus, *sebelum; 
    if (posisi < 1 || posisi > hitungList()) { 
        cout << "Posisi di luar jangkauan" << endl; 
    } else if (posisi == 1) { 
        cout << "Posisi bukan posisi tengah" << endl; 
    } else { 
        int nomor = 1; 
        bantu = head; 
        while (nomor <= posisi) { 
            if (nomor == posisi - 1) { 
                sebelum = bantu; 
            } 
            if (nomor == posisi) { 
                hapus = bantu; 
            } 
            bantu = bantu->next; 
            nomor++; 
        } 
        sebelum->next = bantu; 
        delete hapus; 
    } 
} 

// Ubah Data Node di Depan 
void ubahDepan(int data) { 
    if (isEmpty() == false) { 
        head->data = data; 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Ubah Data Node di Tengah 
void ubahTengah(int data, int posisi) { 
    Node *bantu; 
    if (isEmpty() == false) { 
        if (posisi < 1 || posisi > hitungList()) { 
            cout << "Posisi di luar jangkauan" << endl; 
        } else if (posisi == 1) { 
            cout << "Posisi bukan posisi tengah" << endl; 
        } else { 
            bantu = head; 
            int nomor = 1; 
            while (nomor < posisi) { 
                bantu = bantu->next; 
                nomor++; 
            } 
            bantu->data = data; 
        } 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Ubah Data Node di Belakang 
void ubahBelakang(int data) { 
    if (isEmpty() == false) { 
        tail->data = data; 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Hapus Seluruh Node 
void clearList() { 
    Node *bantu, *hapus; 
    bantu = head; 
    while (bantu != NULL) { 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    } 
    head = tail = NULL; 
    cout << "List berhasil terhapus!" << endl; 
} 

// Tampilkan Isi Linked List 
void tampil() { 
    Node *bantu; 
    bantu = head; 
    if (isEmpty() == false) { 
        while (bantu != NULL) { 
            cout << bantu->data << ends; 
            bantu = bantu->next; 
        } 
        cout << endl; 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

int main() { 
    init(); 
    insertDepan(3); 
    tampil(); 
    insertBelakang(5); 
    tampil(); 
    insertDepan(2); 
    tampil(); 
    insertDepan(1); 
    tampil(); 
    hapusDepan(); 
    tampil(); 
    hapusBelakang(); 
    tampil(); 
    insertTengah(7, 2); 
    tampil(); 
    hapusTengah(2); 
    tampil(); 
    ubahDepan(1); 
    tampil(); 
    ubahBelakang(8); 
    tampil(); 
    ubahTengah(11, 2); 
    tampil(); 

    return 0; 
} 

```
2. Double linked List

Double Linked List (DLL) merupakan suatu linked list yang memiliki dua variabel 
pointer yaitu pointer yang menunjuk ke node selanjutnya dan pointer yang menunjuk ke node 
sebelumnya. Setiap head dan tailnya juga menunjuk ke NULL. Contoh:
![Screenshot 2024-04-28 221532](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/942792cf-a843-43f9-b495-dcbd0e0d2f44)


## Guided 2
```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}

```
3. Single Linked List Circular

Single Linked List Circular adalah Single Linked List yang pointer nextnya menunjuk 
pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer 
next pada node terakhir akan menunjuk ke node terdepannya. Pengertian: 
Single : artinya field pointer-nya hanya satu buah saja dan satu arah. 
Circular : artinya pointer next-nya akan menunjuk pada dirinya sendiri sehingga berputar

 node pada linked list mempunyai field yang berisi pointer ke node berikutnya, 
dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke node terdepan sehingga linked list tersebut berputar. Node terakhir akan menunjuk lagi ke head. 

Penambahan node baru akan dikaitan di node paling depan, 
namun pada saat pertama kali (data masih kosong), maka penambahan data dilakukan pada 
head nya. Pada prinsipnya adalah mengkaitkan data baru dengan head, kemudian head 
akan menunjuk pada data baru tersebut sehingga head akan tetap selalu menjadi data 
terdepan. Untuk menghubungkan node terakhir dengan node terdepan dibutuhkan pointer 
bantu dan dibutuhkan dua buah variabel pointer: head dan tail. 
Head akan selalu menunjuk pada node pertama, sedangkan tail akan selalu menunjuk pada node terakhir. 

## Guided 3
```C++
#include <iostream> 
using namespace std; 
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node 
struct Node { 
    string data; 
    Node *next; 
}; 

Node *head, *tail, *baru, *bantu, *hapus; 

void init() { 
    head = NULL; 
    tail = head; 
} 

// Pengecekan apakah Linked List kosong 
int isEmpty() { 
    return head == NULL; 
} 

// Buat Node Baru 
void buatNode(string data) { 
    baru = new Node; 
    baru->data = data; 
    baru->next = NULL; 
} 

// Hitung Jumlah Node 
int hitungList() { 
    bantu = head; 
    int jumlah = 0; 
    while (bantu != NULL) { 
        jumlah++; 
        bantu = bantu->next; 
    } 
    return jumlah; 
} 

// Tambah Node di Depan 
void insertDepan(string data) { 
    buatNode(data); 
    if (isEmpty() == 1) { 
        head = baru; 
        tail = head; 
        baru->next = head; 
    } else { 
        while (tail->next != head) { 
            tail = tail->next; 
        } 
        baru->next = head; 
        head = baru; 
        tail->next = head; 
    } 
} 

// Tambah Node di Belakang 
void insertBelakang(string data) { 
    buatNode(data); 
    if (isEmpty() == 1) { 
        head = baru; 
        tail = head; 
        baru->next = head; 
    } else { 
        while (tail->next != head) { 
            tail = tail->next; 
        } 
        tail->next = baru; 
        baru->next = head; 
    } 
} 

// Tambah Node di Tengah 
void insertTengah(string data, int posisi) { 
    if (isEmpty() == 1) { 
        head = baru; 
        tail = head; 
        baru->next = head; 
    } else { 
        baru->data = data; 
        int nomor = 1; 
        bantu = head; 
        while (nomor < posisi - 1) { 
            bantu = bantu->next; 
            nomor++; 
        } 
        baru->next = bantu->next; 
        bantu->next = baru; 
    } 
} 

// Hapus Node di Depan 
void hapusDepan() { 
    if (isEmpty() == 0) { 
        hapus = head; 
        tail = head; 
        if (hapus->next == head) { 
            head = NULL; 
            tail = NULL; 
            delete hapus; 
        } else { 
            while (tail->next != hapus) { 
                tail = tail->next; 
            } 
            head = head->next; 
            tail->next = head; 
            hapus->next = NULL; 
            delete hapus; 
        } 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Hapus Node di Belakang 
void hapusBelakang() { 
    if (isEmpty() == 0) { 
        hapus = head; 
        tail = head; 
        if (hapus->next == head) { 
            head = NULL; 
            tail = NULL; 
            delete hapus; 
        } else { 
            while (hapus->next != head) { 
                hapus = hapus->next; 
            } 
            while (tail->next != hapus) { 
                tail = tail->next; 
            } 
            tail->next = head; 
            hapus->next = NULL; 
            delete hapus; 
        } 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Hapus Node di Tengah 
void hapusTengah(int posisi) { 
    if (isEmpty() == 0) { 
        int nomor = 1; 
        bantu = head; 
        while (nomor < posisi - 1) { 
            bantu = bantu->next; 
            nomor++; 
        } 
        hapus = bantu->next; 
        bantu->next = hapus->next; 
        delete hapus; 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Hapus Seluruh Node 
void clearList() { 
    if (head != NULL) { 
        hapus = head->next; 
        while (hapus != head) { 
            bantu = hapus->next; 
            delete hapus; 
            hapus = bantu; 
        } 
        delete head; 
        head = NULL; 
    } 
    cout << "List berhasil terhapus!" << endl; 
} 

// Tampilkan Isi Linked List 
void tampil() { 
    if (isEmpty() == 0) { 
        tail = head; 
        do { 
            cout << tail->data << ends; 
            tail = tail->next; 
        } while (tail != head); 
        cout << endl; 
    } else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

int main() { 
    init(); 
    insertDepan("Ayam"); 
    tampil(); 
    insertDepan("Bebek"); 
    tampil(); 
    insertBelakang("Cicak"); 
    tampil(); 
    insertBelakang("Domba"); 
    tampil(); 
    hapusBelakang(); 
    tampil(); 
    hapusDepan(); 
    tampil(); 
    insertTengah("Sapi", 2); 
    tampil(); 
    hapusTengah(2); 
    tampil(); 
    return 0; 
} 

```
 

## Unguided
### Tugas
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 
### [1]
1  Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa, berikut contoh tampilan output dari nomor 1: 
• Tampilan Menu: 
PROGRAM SINGLE LINKED LIST NON-CIRCULAR  
1. Tambah Depan  
2. Tambah Belakang  
3. Tambah Tengah  
4. Ubah Depan  
5. Ubah Belakang  
6. Ubah Tengah  
7. Hapus Depan  
8. Hapus Belakang  
9. Hapus Tengah  
10. Hapus List  
11. TAMPILKAN  
0. KELUAR  
Pilih Operasi : 

##### input
```C++
#include <iostream> 
#include <string> 
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
void init() {
    head = NULL;
    tail = NULL;
}
bool isEmpty() {
    return head == NULL;
}
void insertDepan(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void insertTengah(string nama, string nim, int posisi) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
    } else {
        Node* baru = new Node;
        baru->nama = nama;
        baru->nim = nim;
        baru->next = NULL;

        Node* bantu = head;
        int nomor = 1;

        while (bantu != NULL && nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        if (bantu == NULL) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

void ubahData(string& namaBaru, string& nimBaru, int posisi) {
    Node* bantu = head;
    int nomor = 1;

    while (bantu != NULL && nomor < posisi) {
        bantu = bantu->next;
        nomor++;
    }

    if (bantu == NULL) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        cout << "Masukkan nama : ";
        cin >> namaBaru;
        cout << "Masukkan NIM : ";
        cin >> nimBaru;
        bantu->nama = namaBaru;
        bantu->nim = nimBaru;
    }
}

void hapusNode(int posisi) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node* hapus;
    if (posisi == 1) {
        hapus = head;
        head = head->next;
    } else {
        Node* bantu = head;
        int nomor = 1;

        while (bantu != NULL && nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        if (bantu == NULL || bantu->next == NULL) {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        if (hapus == tail) {
            tail = bantu;
        }
    }

    cout << "Data " << hapus->nama << " berhasil dihapus" << endl;
    delete hapus;
}

void hapusList() {
    Node* bantu = head;
    Node* hapus;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

int hitungList() {
    Node* hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

void tampil() {
    Node* bantu = head;
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
    } else {
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (bantu != NULL) {
            cout << bantu->nama << "\t" << bantu->nim << endl;
            bantu = bantu->next;
        }
    }
}

void menu() {
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus Depan" << endl;
    cout << "8. Hapus Belakang" << endl;
    cout << "9. Hapus Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. Tampilkan" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih Operasi : ";
}

int main() {
    init();
    int pilihan;
    string nama, nim;
    int posisi;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                ubahData(nama, nim, 1);
                cout << "Data telah diubah" << endl;
                break;
            case 5:
                ubahData(nama, nim, hitungList());
                cout << "Data telah diubah" << endl;
                break;
            case 6:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                ubahData(nama, nim, posisi);
                cout << "Data telah diubah" << endl;
                break;
            case 7:
                hapusNode(1);
                break;
            case 8:
                hapusNode(hitungList());
                break;
            case 9:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                hapusNode(posisi);
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampil();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}

```
Kode diatas terdiri dari node-node yang saling terhubung. Setiap node memiliki dua bagian utama: data dan pointer yang menunjuk ke node berikutnya dalam linked list. 

Kode tersebut menggunakan struktur data linked list yang terdiri dari Node yang memiliki atribut nama, nim, dan next.
Struktur Node sendiri adalah inti dari representasi data dalam linked list. Setiap Node terdiri dari dua string, yaitu nama dan nim, yang menyimpan informasi terkait, serta sebuah pointer next yang menunjuk ke Node berikutnya dalam linked list. 
Inisialisasi dan pengelolaan linked list didasarkan pada konsep pointer head dan tail. Pointer head menandai awal dari linked list, sementara pointer tail menandai akhirnya.

 Fungsi init() bertanggung jawab untuk menginisialisasi linked list dengan mengatur pointer head dan tail menjadi NULL, sedangkan fungsi isEmpty() membantu memeriksa apakah linked list kosong dengan memeriksa apakah head adalah NULL. Fungsi insertDepan() dan insertBelakang() digunakan untuk menambahkan node baru di depan dan belakang linked list secara berturut-turut. Fungsi insertTengah() memungkinkan penambahan node baru di posisi tertentu dalam linked list. Fungsi ubahData() memungkinkan pengubahan data node pada posisi tertentu dalam linked list. Sementara itu, fungsi hapusNode() digunakan untuk menghapus node pada posisi tertentu, dan fungsi hapusList() untuk menghapus seluruh isi linked list. Fungsi hitungList() membantu dalam menghitung jumlah node dalam linked list, sementara fungsi tampil() digunakan untuk menampilkan isi linked list. Fungsi menu() bertanggung jawab untuk menampilkan opsi operasi kepada pengguna, sedangkan fungsi main() adalah inti dari program, yang mengatur interaksi antara pengguna dan operasi-operasi yang tersedia dalam linked list.

 Melalui fungsi-fungsi ini, program memungkinkan pengguna untuk mengelola dan memanipulasi data dalam linked list sesuai kebutuhan.

Berikut adalah hasil output dari kode trsebut:
#### Output
#### Tampilkan menu
> Tampilan Menu
![Screenshot 2024-04-28 141300](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/29d34e6d-e8ef-431e-9b6f-03e2f92c1ded)
#### Tampilan Operasi Tambahan
> Tambah Depan
![Screenshot 2024-04-28 141754](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/10635bc0-6f31-42ac-8723-16e714c423b3)

> Tambah Tengah
![Screenshot 2024-04-28 141921](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/d03c4db3-16bb-4b02-8c83-b30192d6c603)
#### Tampilan Operasi Hapus
> Hapus Belakang
![Screenshot 2024-04-28 142256](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/0fb884c2-962f-47ae-abe2-04621f8685bf)

> Hapus Tengah
![Screenshot 2024-04-28 142441](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/ed1800c8-f4a8-489b-928e-13d31ee36efb)

#### Tampilan Operasi Ubah
> Ubah Belakang
![Screenshot 2024-04-28 143414](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/e2e93395-e4b5-4411-a400-2d6896a90757)

> Ubah Tengah
![Screenshot 2024-04-28 142638](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/7f3b4e88-fa69-440a-bd15-8833bc85936a)

> Ubah Depan
![Screenshot 2024-04-28 143157](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/361105bb-b202-4b21-b83f-a7d97dadc274)

#### Tampilan Operasi Tampilan Data
> Data Mahasiswa
![Screenshot 2024-04-28 140938](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/92143c91-5bac-4e68-a9ee-8a6ae21373a0)

### [2] 
Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)  
```
Nama 	NIM
Jawad 	23300001
[Nama Anda] 	[NIM Anda]
Farrel 	23300003
Denis 	23300005
Anis 	23300008
Bowo 	23300015
Gahar 	23300040
Udin 	23300048
Ucok 	23300050
Budi 	23300099
```
#### Screnshoot data Yang telah diinputkan
![Screenshot 2024-04-28 140938](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/92143c91-5bac-4e68-a9ee-8a6ae21373a0)

### [3]
Lakukan perintah berikut: 

a) Tambahkan data berikut diantara Farrel dan Denis: 
Wati 2330004 

![Screenshot 2024-04-27 230543](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/c2d6c61a-0d1d-44be-87df-2a8f92ffbd0f)


Interpresentasi langkah langkah: 

Pilih operasi ke 3 (Tambah Tengah) -> Masukan Nama Wati -> Masukan NIM -> Masukan Posisi ke 4

b) Hapus data Denis 

![Screenshot 2024-04-28 134724](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/c81f569f-0549-42a0-aa34-caae901cbba3)

Interpresentasi langkah langkah:

Pilih operasi ke 9 (Hapus Tengah) -> Masukan opsi ke 5

c) Tambahkan data berikut di awal: 
Owi 2330000 

![Screenshot 2024-04-28 135118](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/460da1e8-b882-4f7c-bf4d-0012a9fff4fa)

Interpresentasi langkah langkah:

Pilih operasi ke 1 (Tambah Depan) -> Masukan Nama Owi -> Masukan Nim 

d) Tambahkan data berikut di akhir: 
David 23300100 

![Screenshot 2024-04-28 135308](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/cfeb9e04-25df-42c9-b09e-dbd66462d7c5)

c

e) Ubah data Udin menjadi data berikut: 
Idin 23300045 

![Screenshot 2024-04-28 135546](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/04edcc52-43ef-41a0-b2a4-c76cb6e5ac64)

Interpresentasi langkah langkah:

Pilih operasi ke 6 (Ubah Tengah) -> Masukan Nama Idin -> Masukan Nim -> Masukan posisi 9


f) Ubah data terkahir menjadi berikut: 
Lucy 23300101 

![Screenshot 2024-04-28 135903](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/02321939-d0d1-4309-acae-7c2399acd308)

Interpresentasi langkah langkah:

Pilih operasi ke 5 (Ubah Belakang) -> Masukan Nama Lucy -> Masukan Nim 

g) Hapus data awal 

![Screenshot 2024-04-28 140029](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/d722c243-2a05-41cc-a947-0c1446afa799)

Interpresentasi langkah langkah:

Pilih operasi ke 7 (Hapus Depan) Data Mahasiswa berhasil dihapus.

h) Ubah data awal menjadi berikut: 
Bagas 2330002 

![Screenshot 2024-04-28 140251](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/64ca6932-fb73-4765-b523-9c0a42bf8461)

Interpresentasi langkah langkah:

Pilih operasi ke 4 (Ubah Depan) -> Masukan Nama Bagas -> Masukan Nim 


i) Hapus data akhir 

![Screenshot 2024-04-28 140422](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/1e5a9149-133e-42bd-a89b-0a7e6311305f)

Interpresentasi langkah langkah:

Pilih operasi ke 8 (Hapus Belakang) Data Mahasiswa berhasil dihapus.


j) Tampilkan seluruh data

![Screenshot 2024-04-28 142113](https://github.com/sudolmunib/tugas-praktikum6-linked-list/assets/162574378/a162b1ab-a8db-487f-881c-54a3094f8ae3)

Interpresentasi langkah langkah:

Pilih operasi ke 11 (Tampilkan) Data Mahasiswa Akan tampil dengan keseluruhan.

## Kesimpulan
Konsep dasar Linked List adalah fondasi dari struktur data ini. Linked list merupakan urutan record data di mana setiap record, yang disebut Node, memiliki sebuah field yang menyimpan alamat atau referensi dari record selanjutnya dalam urutan. Node-node ini terhubung satu sama lain melalui link, membentuk sebuah rantai data yang dapat diakses secara berurutan.

Single Linked List adalah jenis Linked List yang paling umum digunakan. Dalam single linked list, setiap Node memiliki satu variabel pointer yang menunjuk ke Node berikutnya. Biasanya, terdapat dua pointer penting: head, yang menunjukkan ke elemen pertama dalam linked list, dan tail, yang menunjukkan ke elemen terakhir. Dengan bantuan head dan tail, kita dapat dengan mudah mengakses elemen pertama dan terakhir dalam linked list.

Double Linked List (DLL) merupakan modifikasi dari single linked list yang memiliki keunggulan navigasi maju dan mundur. Setiap Node dalam DLL memiliki dua variabel pointer: satu untuk menunjuk ke Node berikutnya dan satu lagi untuk menunjuk ke Node sebelumnya. Hal ini memungkinkan kita untuk bergerak maju dan mundur dalam linked list dengan efisien.

Single Linked List Circular adalah varian khusus dari single linked list di mana pointer next pada Node terakhir menunjuk kembali ke Node pertama, membentuk sebuah lingkaran atau siklus. Dengan demikian, linked list ini tidak memiliki akhir yang jelas, dan Node terakhir selalu menunjuk kembali ke head, menciptakan siklus yang berkelanjutan.

Proses penambahan dan penghapusan Node merupakan operasi penting dalam pengelolaan linked list. Penambahan node baru umumnya dilakukan di depan linked list dengan mengaitkan data baru dengan head. Namun, pada kondisi awal, penambahan data dilakukan pada head. Penghapusan node juga harus dikelola dengan hati-hati untuk menjaga konsistensi linked list.

Manajemen pointer head dan tail sangat penting dalam menjaga konsistensi linked list. Head selalu menunjuk ke Node pertama, sedangkan tail selalu menunjuk ke Node terakhir. Dengan manajemen yang baik, kita dapat dengan mudah mengakses elemen pertama dan terakhir dalam linked list, serta menjaga struktur linked list tetap teratur dan konsisten.

## Referensi
[1] Annisa Puspa Kirana, S.Kom, M.Kom. 2016. Modul Praktikum Algoritma dan Struktur Data. 
Malang : Universitas Negeri Malang.

[2] Aruming Tyah, D., 2022. Modul Praktikum Algoritma Struktur Data [Daring]

Daan Czajkowski and Qiang Chew Jew (2016).Object oriented programming inC++. New York: Arcler Press.

Isrd Group (2007). Introduction to object oriented programming and C++. NewDelhi: Tatamcgraw Hill.