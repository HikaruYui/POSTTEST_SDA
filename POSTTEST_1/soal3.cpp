#include <iostream>
using namespace std;

void reverseArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main() {
    int bil_Prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array sebelum dibalik: ";
    int *p = bil_Prima;
    for (int i = 0; i < n; i++) {
        cout << bil_Prima[i] << " ";
    }
    cout << endl << endl;


    cout << "Array sebelum dibalik dan Keterangan alamat: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke: " << i << " = " << bil_Prima[i] 
        << " " << "(alamat = " << &bil_Prima[i] << ")" << endl;
    }

    reverseArray(bil_Prima, n);
    cout << endl << endl;
    
    cout << "Array ketika sudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << bil_Prima[i] << " ";
    }
    cout << endl << endl;

    cout << "Alamat memori reverse array: ";
    for (int *p = bil_Prima; p < bil_Prima + n; p++) {
        cout << "Nilai: " << *p 
        << " (alamat = " << p << ")" << endl;
    }

    return 0;
}