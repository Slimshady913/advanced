#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
    map<int, string> m1;
    map<string, double> m2;

    m1[1] = "Alice";
    m1[2] = "Bob";

    m2["Alice"] = 173.5;
    m2["Bob"] = 174.0;

    cout << "m1: " << endl;
    for (auto i : m1) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "m2: " << endl;
    for (auto i : m2) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "m1[1]: " << m1[1] << endl;
    cout << "m2[\"Alice\"]: " << m2["Alice"] << endl;
}