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
