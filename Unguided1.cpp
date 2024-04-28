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
