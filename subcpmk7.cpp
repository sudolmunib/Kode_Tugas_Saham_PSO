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
