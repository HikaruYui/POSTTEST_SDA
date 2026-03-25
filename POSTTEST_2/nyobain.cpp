#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    long harga;
};

// 1. Fungsi Swap menggunakan dereferensi pointer (*a, *b) - Syarat Wajib 4
void swapKereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Tampil Jadwal menggunakan Pointer Aritmatika - Syarat Wajib 1 & 3
void tampilJadwal(Kereta* arr, int n) {
    cout << "\n======================== JADWAL KERETA API ========================\n";
    cout << setw(5) << "No" << setw(15) << "Nama" << setw(15) << "Asal" << setw(15) << "Tujuan" << setw(12) << "Harga" << endl;
    for (int i = 0; i < n; i++) {
        // Menggunakan pointer aritmatika (arr + i) - Syarat Wajib 3
        cout << setw(5) << (arr + i)->nomor 
             << setw(15) << (arr + i)->nama 
             << setw(15) << (arr + i)->asal 
             << setw(15) << (arr + i)->tujuan 
             << setw(12) << (arr + i)->harga << endl;
    }
}

// 3. Selection Sort berdasarkan Harga (Termurah)
void selectionSortHarga(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        swapKereta(&arr[minIdx], &arr[i]); // Menggunakan referensi pointer - Syarat Wajib 2
    }
    cout << "\nData berhasil diurutkan berdasarkan harga termurah!\n";
}

// 4. Merge Sort berdasarkan Nama (A-Z)
void merge(Kereta* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Kereta L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortNama(Kereta* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortNama(arr, l, m);
        mergeSortNama(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Linear Search berdasarkan Rute (Menampilkan Iterasi) - Syarat Wajib 5
void linearSearchRute(Kereta* arr, int n, string asal, string tujuan) {
    bool found = false;
    cout << "\n--- Proses Iterasi Linear Search ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Mengecek indeks ke-" << i << ": " << (arr + i)->asal << " ke " << (arr + i)->tujuan << endl;
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "\nData Ditemukan!\n";
            cout << "Nama Kereta: " << (arr + i)->nama << " | Harga: " << (arr + i)->harga << endl;
            found = true;
        }
    }
    if (!found) cout << "Jadwal rute tersebut tidak ditemukan.\n";
}

// 6. Jump Search berdasarkan Nomor Kereta
int jumpSearchNomor(Kereta* arr, int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    
    // Syarat Jump Search: Data harus urut (kita asumsikan user mengurutkan atau input urut)
    while ((arr + min(step, n) - 1)->nomor < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while ((arr + prev)->nomor < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if ((arr + prev)->nomor == x) return prev;
    return -1;
}

int main() {
    int n = 3;
    Kereta* daftar = new Kereta[100]; // Array of struct

    // Data Awal
    daftar[0] = {101, "Argo Bromo", "Jakarta", "Surabaya", 500000};
    daftar[1] = {105, "Gajayana", "Malang", "Jakarta", 600000};
    daftar[2] = {102, "Logawa", "Purwokerto", "Jember", 200000};

    int pilihan;
    do {
        cout << "\n=== SISTEM INFORMASI KERETA API ===";
        cout << "\n1. Tampil Jadwal";
        cout << "\n2. Tambah Kereta";
        cout << "\n3. Cari Rute (Linear Search)";
        cout << "\n4. Cari Nomor (Jump Search)";
        cout << "\n5. Urutkan Nama (Merge Sort)";
        cout << "\n6. Urutkan Harga (Selection Sort)";
        cout << "\n0. Keluar";
        cout << "\nPilihan: "; cin >> pilihan;

        if (pilihan == 1) {
            tampilJadwal(daftar, n);
        } else if (pilihan == 2) {
            cout << "Nomor Kereta: "; cin >> daftar[n].nomor;
            cout << "Nama Kereta: "; cin.ignore(); getline(cin, daftar[n].nama);
            cout << "Asal: "; getline(cin, daftar[n].asal);
            cout << "Tujuan: "; getline(cin, daftar[n].tujuan);
            cout << "Harga: "; cin >> daftar[n].harga;
            n++;
        } else if (pilihan == 3) {
            string a, t;
            cout << "Asal: "; cin >> a;
            cout << "Tujuan: "; cin >> t;
            linearSearchRute(daftar, n, a, t);
        } else if (pilihan == 4) {
            int no;
            cout << "Masukkan Nomor Kereta: "; cin >> no;
            int hasil = jumpSearchNomor(daftar, n, no);
            if(hasil != -1) cout << "Ditemukan: " << daftar[hasil].nama << " rute " << daftar[hasil].asal << endl;
            else cout << "Tidak ditemukan. (Pastikan data terurut nomor untuk Jump Search)\n";
        } else if (pilihan == 5) {
            mergeSortNama(daftar, 0, n - 1);
            cout << "Berhasil diurutkan A-Z.\n";
        } else if (pilihan == 6) {
            selectionSortHarga(daftar, n);
        }
    } while (pilihan != 0);

    delete[] daftar;
    return 0;
}


// // Syarat 1 & 3: Fungsi menggunakan parameter pointer dan pointer aritmatika
// void tampilkanJadwal(Kereta* arr, int n) {
//     cout << "\n========================== JADWAL KERETA API ==========================\n";
//     cout << left << setw(8) << "Nomor" << setw(15) << "Nama" << setw(15) << "Asal" 
//          << setw(15) << "Tujuan" << setw(12) << "Harga" << endl;
//     cout << "-----------------------------------------------------------------------\n";
//     for (int i = 0; i < n; i++) {
//         // Syarat 3: Menggunakan pointer aritmatika (arr + i)
//         cout << left << setw(8) << (arr + i)->nomor 
//              << setw(15) << (arr + i)->nama 
//              << setw(15) << (arr + i)->asal 
//              << setw(15) << (arr + i)->tujuan 
//              << "Rp" << setw(10) << (arr + i)->harga << endl;
//     }
// }
