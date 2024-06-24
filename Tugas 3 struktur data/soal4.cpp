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