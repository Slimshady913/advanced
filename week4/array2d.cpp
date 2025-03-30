#include <iostream>

using namespace std;

int main() {
    int arr2d[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "arr2d[0][0]: " << arr2d[0][0] << endl;
    cout << "**arr2d: " << **arr2d << endl;

    cout << "*arr2d: " << *arr2d << endl;
    cout << "arr2d[0]: " << arr2d[0] << endl;

    cout << "*(arr2d + 1): " << *(arr2d + 1) << endl;
    cout << "arr2d[1]: " << arr2d[1] << endl;

    cout << "**arr2d: " << **arr2d << endl;
    cout << "*(*(arr2d) + 1): "  << **(arr2d + 1) << endl;
    cout << "*(*(arr2d) + 2): " << **(arr2d + 2) << endl;
    cout << "*(*(arr2d + 1)): " << **(arr2d + 3) << endl;
    cout << "*(*(arr2d + 1) + 1): " << **(arr2d + 4) << endl;
    cout << "*(*(arr2d + 1) + 2): " << **(arr2d + 5) << endl;

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << "&arr2d[" << i << "][" << j << "]: " << &arr2d[i][j] << endl;
        }
    }
}