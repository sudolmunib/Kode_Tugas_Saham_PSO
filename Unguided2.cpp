#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int countVowels(const string &sentence) {
    int count = 0;
    for (int i = 0; i < sentence.length(); ++i) {
        char ch = sentence[i];
        if (isalpha(ch) && isVowel(ch)) { // Check if the character is a vowel
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;
    
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence);

    int vowelCount = countVowels(sentence);
    cout << "Jumlah huruf vokal dalam kalimat adalah: " << vowelCount << endl;

    return 0;
}
