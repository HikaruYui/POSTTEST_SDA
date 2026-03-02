#include <iostream>
#include <string>
using namespace std;

struct  Mahasiswa{
    string nama;
    string NIM;
    float IPK;
};

int FindMax(Mahasiswa mahasiswa[], int n) {
    int maks = 0;

    for(int i = 0; i < n; i++) {
        if(mahasiswa[i].IPK > mahasiswa[maks].IPK) {
            maks = i;
        }
        
    }
    return maks;
}

int main() {
    Mahasiswa mahasiswa[5];

    for(int i = 0; i < 5; i++) {
    cout << "Silakan input data mahasiswa " << endl;

    cout << "Nama: ";
    getline(cin, mahasiswa[i].nama);

    cout << "NIM: ";
    getline(cin, mahasiswa[i].NIM);

    cout << "IPK: ";
    cin >> mahasiswa[i].IPK;
    cin.ignore();

    cout << endl;
}

cout << "Data Mahasiswa: " << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Data Mahasiswa " << i+1 << endl;
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "NIM: " << mahasiswa[i].NIM << endl;
        cout << "IPK: " << mahasiswa[i].IPK << endl;

    }
   
    int IPKTertinggi = FindMax(mahasiswa, 5);
    cout << "Mahasiswa dengan IPK tertinggi adalah: " << endl;
    cout << "Nama: " << mahasiswa[IPKTertinggi].nama << endl;
    cout << "NIM: " << mahasiswa[IPKTertinggi].NIM << endl;
    cout << "IPK: " << mahasiswa[IPKTertinggi].IPK << endl;

    return 0;

}