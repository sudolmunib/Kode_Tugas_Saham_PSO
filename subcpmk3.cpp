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
