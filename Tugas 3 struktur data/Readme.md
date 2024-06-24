Tugas 3 Struktur Data

Berikan penjelasan dan contoh program(beserta penjelasan alur program) dari masing-masing materi struktur data berikut:
- Priority Queue
- Hash Table
- Rekursif
- Graph & Tree

### jawab penjelasan dan contoh output 

#### 1 Priority Queue
Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya. Ketika menambahkan elemen ke antrian, elemen tersebut dimasukkan ke dalam posisi berdasarkan nilai prioritasnya. Misalnya, jika menambahkan elemen dengan nilai prioritas tinggi ke priority queue, elemen tersebut mungkin dimasukkan di dekat bagian depan antrian, sementara elemen dengan nilai prioritas rendah mungkin dimasukkan di dekat bagian belakang. Priority queue juga dapat memiliki aturan-aturan yang berbeda untuk menempatkan elemenelemennya, dapat memprioritaskan yang maksimum atau minimum. Relaxation process juga akan berbeda pada tiap kasus yang ingin dipecahkan, serta akan membutuhkan inisialisasi jarak yang berbeda pula.Container priority_queue dibuat berdasarkan vector dan tidak memiliki iterator. Container ini hanya mengijinkan penghapusan elemen berprioritas paling tinggi. Harus sudah didefinisikan operator < untuk tipe data elemen. Jika x < y memberikan true, ini berarti bahwa prioritas elemen y lebih tinggi daripada elemen x. Member function yang dimiliki serupa dengan yang dimiliki oleh stack

Kode program
```c++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    if (heapSize < 0) {
        std::cerr << "Error: Heap is empty." << std::endl;
        return -1; // or some error value
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        std::cerr << "Error: Heap is empty." << std::endl;
        return -1; // or some error value
    }
    return H[0];
}

int main() {
    // Example usage:
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Max element: " << getMax() << std::endl;
    std::cout << "Extracted max: " << extractMax() << std::endl;
    std::cout << "Max element after extraction: " << getMax() << std::endl;

    changePriority(2, 49);
    std::cout << "Max element after priority change: " << getMax() << std::endl;

    return 0;
}
```
output
![Screenshot 2024-06-24 132114](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/bd63dd1b-ab45-48a8-9ebe-e861d1399331)

#### 2 Hash Table
Hash Table (Tabel Hash) adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data, di mana setiap elemen dalam kumpulan data memiliki kunci (key) yang unik dan nilainya (value) terkait. Konsep utama di balik tabel hash adalah penggunaan fungsi hash untuk mengonversi kunci menjadi alamat atau indeks di dalam tabel, sehingga memungkinkan pencarian dan pengambilan data dengan efisien.

Pada dasarnya, tabel hash berfungsi sebagai penyimpanan asosiatif, di mana data disimpan dalam bentuk pasangan kunci-nilai. Proses ini melibatkan penggunaan fungsi hash untuk menghasilkan indeks unik dari kunci, dan nilai yang sesuai akan disimpan pada indeks tersebut.

Salah satu keuntungan utama dari tabel hash adalah kecepatan akses dan pencarian data yang sangat efisien. Ketika kita ingin mencari nilai berdasarkan kunci, kita hanya perlu melakukan proses hashing pada kunci untuk mengetahui lokasi penyimpanan datanya, sehingga tidak perlu mencari secara berurutan seperti pada struktur data lainnya seperti array atau list.

Namun, perlu diingat bahwa pada situasi tertentu, bisa saja terjadi tabrakan hash (hash collision), yaitu ketika dua kunci berbeda menghasilkan indeks yang sama. Untuk menangani tabrakan ini, metode penyelesaian tabrakan (collision resolution) digunakan, seperti linear probing, chaining, atau double hashing.

Hash table digunakan dalam berbagai aplikasi, termasuk dalam basis data, kamus (dictionary), dan kebanyakan algoritma yang membutuhkan pencarian atau pengelompokan data dengan cepat dan efisien.

Fungsi Hash Table
Fungsi utama dari Hash Table (Tabel Hash) adalah untuk menyediakan struktur data yang memungkinkan pencarian, penyisipan, dan penghapusan data dengan efisien. Berikut adalah beberapa fungsi utama dari Hash Table:

1. Pencarian (Search)
Hash Table memungkinkan pencarian data berdasarkan kunci (key) dengan cepat. Saat kita ingin mencari nilai berdasarkan kunci, fungsi hash akan mengonversi kunci menjadi indeks, dan nilai yang sesuai dapat diakses langsung dari indeks tersebut, menghasilkan waktu akses yang konstan (O(1)).

2. Penyisipan (Insertion)
Hash Table memungkinkan penambahan data baru dengan kunci dan nilainya. Saat kita ingin menyisipkan data baru, fungsi hash akan mengonversi kunci menjadi indeks, dan nilai tersebut akan disimpan pada indeks yang sesuai. Proses ini dapat dilakukan dengan waktu yang konstan (O(1)) pada kebanyakan kasus, membuatnya sangat efisien.

3. Penghapusan (Deletion)
Hash Table memungkinkan penghapusan data berdasarkan kunci. Saat kita ingin menghapus data, hash table akan menggunakan fungsi hash untuk menemukan indeks data yang sesuai dengan kunci dan menghapusnya dari tabel. Seperti pencarian dan penyisipan, operasi penghapusan juga berjalan dengan waktu yang konstan (O(1)) dalam kebanyakan kasus.

4. Asosiasi Kunci-Nilai (Key-Value Association)
Hash Table menyimpan data dalam bentuk pasangan kunci-nilai (key-value). Ini memungkinkan kita untuk mengaitkan kunci dengan nilai tertentu sehingga kita dapat dengan mudah mengakses nilai tersebut ketika diberikan kunci.

5. Kecepatan Akses
Salah satu keunggulan utama dari Hash Table adalah kecepatan aksesnya. Dengan menggunakan fungsi hash, proses mencari dan mengakses data menjadi sangat cepat karena kita dapat langsung menuju lokasi data tanpa perlu mencari secara berurutan.

Cara Membuat
Untuk membuat Hash Table (Tabel Hash), Anda dapat mengikuti langkah-langkah berikut:

1. Tentukan Ukuran Tabel
Pertama, tentukan ukuran tabel hash yang sesuai untuk kebutuhan Anda. Ukuran tabel haruslah bilangan prima agar membantu mengurangi jumlah tabrakan hash dan mendistribusikan data dengan lebih merata.

2. Buat Struktur Data
Buat struktur data untuk menyimpan pasangan kunci-nilai (key-value) dalam tabel hash. Dalam beberapa bahasa pemrograman, Anda dapat menggunakan array, linked list, atau struktur data lainnya untuk mewakili tabel hash.

3. Definisikan Fungsi Hash
Buatlah fungsi hash yang akan mengubah kunci (key) menjadi indeks dalam tabel hash. Fungsi hash harus menghasilkan nilai yang unik dan merata untuk setiap kunci untuk mencegah terjadinya tabrakan hash sebisa mungkin.

4. Penanganan Tabrakan
Tentukan dan terapkan metode penanganan tabrakan hash. Jika dua kunci berbeda menghasilkan indeks yang sama, Anda perlu memutuskan cara untuk menangani tabrakan tersebut. Metode umum untuk menangani tabrakan adalah dengan teknik chaining, yaitu menyimpan beberapa nilai dalam satu slot tabel hash menggunakan struktur data seperti linked list atau array.

5. Operasi Pencarian, Penyisipan, dan Penghapusan
Implementasikan fungsi-fungsi untuk melakukan operasi pencarian (search), penyisipan (insertion), dan penghapusan (deletion) data dalam tabel hash. Pastikan operasi ini bekerja dengan benar dan efisien, memanfaatkan fungsi hash dan metode penanganan tabrakan yang telah ditentukan sebelumnya.

6. Uji Coba dan Optimalisasi
Setelah selesai membuat Hash Table, lakukan uji coba untuk memastikan bahwa implementasi berfungsi dengan baik dan memberikan hasil yang diharapkan. Jika diperlukan, lakukan optimasi untuk meningkatkan kinerja Hash Table, termasuk pemilihan ukuran tabel yang lebih optimal atau perbaikan pada fungsi hash.

Perlu diingat bahwa implementasi Hash Table dapat bervariasi tergantung pada bahasa pemrograman yang digunakan. Setiap bahasa pemrograman memiliki cara tersendiri dalam membuat dan mengelola struktur data Hash Table. Pastikan untuk mengacu pada dokumentasi resmi bahasa pemrograman yang Anda gunakan atau cari referensi yang tepat untuk mendapatkan contoh dan panduan yang sesuai.

``` c++
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int hash_func(int key) {
    return key % MAX_SIZE;
}

struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(NULL) {}
};


class HashTable {
private:
    Node** table; 

public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != NULL) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != NULL) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; 
    }

    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = NULL;
        while (current != NULL) {
            if (current->key == key) {
                if (prev == NULL) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(1, 15);
    ht.insert(2, 17);
    ht.insert(3, 18);

    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    ht.remove(4); 
    ht.traverse();
    return 0;
}
```
output
![Screenshot 2024-06-24 133613](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/406d539c-d381-455b-87b4-8844e97cef4c)


#### soal 3 Rekursif
Rekursif adalah suatu proses atau prosedur dari fungsi yang memanggil dirinya sendiri secara berulang-ulang. Karena proses dalam Rekursif ini terjadi secara berulang-ulang maka harus ada kondisi yang membatasi pengulangan persebut, jika tidak maka proses tidak akan pernah berhenti sampai memori yang digunakan untuk menampung proses tersebut tidak dapat menampung lagi/penuh. Kelebihan Fungsi Rekursif adalah program menjadi lebih singkat. Pada beberapa kasus, lebih mudah menggunakan fungsi rekursif, contohnya: pangkat, factorial, dan fibonacci, dan beberapa proses deret lainnya [1]. Fungsi rekursif lebih efisien dan cepat dibandingkan proses secara iteratif. Kekurangan Fungsi Rekursif adalah memakan memori lebih besar, karena setiap bagian dari dirinya dipanggil, akan membutuhkan sejumlah ruang memori untuk penyimpanan. Rekursif sering kali tidak bisa berhenti sehingga memori akan terpakai habis dan program bisa *hang*. 

Rekursif berarti bahwa suatu proses bisa memanggil dirinya sendiri. Rekursif adalah kemampuan suatu rutin untuk memanggil dirinya sendiri. Dalam Rekursif sebenarnya terkandung pengertian prosedur dan fungsi. Perbedaannya adalah bahwa rekursif bisa memanggil ke dirinya sendiri, tetapi prosedur dan fungsi harus dipanggil lewat pemanggil prosedur dan fungsi [2].

Rekursif dibedakan menjadi dua jenis, yaitu Rekursif Langsung dan Rekursif Tidak Langsung. Rekursif Langsung terjadi ketika suatu fungsi memanggil dirinya sendiri secara langsung, tanpa memanggil fungsi lain. Rekursif Tidak Langsung terjadi ketika suatu fungsi memanggil fungsi lain yang kemudian memanggil fungsi asli.

-Rekrusift langsung
```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main( ) {
    cout << " Rekursif Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```
output
![Screenshot 2024-06-24 134740](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/a78615fd-de93-4dc2-99c8-4df35385f2cf)

-Rekrusift tidak langsung
```C++

#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n-1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n<< " ";
        functionB(n/2);
    }
}

int main( ) {
    int num= 5;
    cout << "Rekursif Tidak Langsung:";
    functionA(num);
    return 0;
}

```
Output
![Screenshot 2024-06-24 134907](https://github.com/sudolmunib/tugas-struktur-data/assets/162574378/b7342c35-2410-4b25-ab31-e83de296abf4)

#### soal 4 Graph & Tree
Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge).

- G = (V, E)
- Dimana :
- G = Graph
- V = Simpul atau Vertex, atau Node, atau Titik
- E = Busur atau Edge, atau arc

tree atau Pohon: Dalam ilmu komputer, pohon/tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi.

```c++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[5] = {
    "jambi", "medan", "pekanbaru", "padang", "palembang"
};

int busur[5][5] = {
    {0, 7, 8, 0, 0},
    {0, 0, 5, 0, 15},
    {0, 6, 0, 0, 5},
    {0, 5, 0, 0, 2},
    {23, 0, 0, 10, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 5; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 5; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ") ";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```






