#include <iostream>

using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "arr[0]: " << arr[0] << endl;
    cout << "*arr: " << *arr << endl;

    cout << "arr[2]: " << arr[2] << endl;
    cout << "arr+2: " << arr+2 << endl;
    cout << "*(arr+2): " << *(arr+2) << endl;
    
    return 0;
} 