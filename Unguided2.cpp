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
