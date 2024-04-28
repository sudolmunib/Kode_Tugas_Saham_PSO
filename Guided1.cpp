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
