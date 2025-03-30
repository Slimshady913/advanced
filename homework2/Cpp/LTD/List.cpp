// vector example
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2 = {1, 2, 3, 4, 5};

    v1.push_back(10);
    v2.push_back(20);

    cout << "v1: ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v2: ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    // delete items from the end
    v2.pop_back();
    cout << "v2: ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    // insert items at the beginning
    v2.insert(v2.begin(), 30);
    cout << "v2: ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    // delete item in the middle
    v2.erase(v2.begin() + 1);
    cout << "v2: ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    // insert items in the middle
    v2.insert(v2.begin() + 1, 40);
    cout << "v2: ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;
}