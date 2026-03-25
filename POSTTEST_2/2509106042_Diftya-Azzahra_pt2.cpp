#include <iostream>
#include <string>
#include <cmath>
#include <tabulate/table.hpp>
#include <tabulate/font_style.hpp>
#include <algorithm>
using namespace tabulate;
using namespace std;



struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};


void swap_Kereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampilkanJadwal(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta" << endl;
        return;
    }

    tabulate::Table table;

    table.add_row({"No Kereta", "Nama", "Asal", "Tujuan", "Harga"});

    for (int i = 0; i < n; i++) {
        table.add_row({
            to_string((arr + i)->nomor),
            (arr + i)->nama,
            (arr + i)->asal,
            (arr + i)->tujuan,
            "Rp" + to_string((arr + i)->harga)
        });
    }

    for (size_t i = 0; i < table.size(); i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            table[i][j].format()
                .border_left("|")
                .border_right("|")
                .border_top("-")
                .border_bottom("-")
                .corner("+");
        }
    }

    table[0][0].format().font_align(tabulate::FontAlign::center);
    cout << table << endl;
}


int linearSearchRute(Kereta* arr, int n, string asal, string tujuan) {
    cout << "Iterasi Linear Search" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mengecek indeks ke-[" << i << "]: "
             << (arr + i)->asal << " ke " << (arr + i)->tujuan << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            return i;
        }
    }
    return -1;
}


void selectionSortHarga(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min_idx)->harga) {
                min_idx = j;
            }
        }
        swap_Kereta(&arr[min_idx], &arr[i]);
    }
}


void selectionSortNomor(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nomor < arr[min_idx].nomor) {
                min_idx = j;
            }
        }
        swap_Kereta(&arr[min_idx], &arr[i]);
    }
}


int jumpSearchNomor(Kereta* arr, int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    cout << "Iterasi Jump Search" << endl;
    cout << "Step = " << step << endl;

    while (step < n && arr[step - 1].nomor < x) {
        cout << "Lompat dari " << prev << " ke " << step - 1 << endl;
        prev = step;
        step += sqrt(n);

        if (prev >= n) {
            return -1;
        }
    }

    while (prev < n && arr[prev].nomor < x) {
        cout << "Cek indeks " << prev << " nomor " << arr[prev].nomor << endl;
        prev++;

        if (prev == min(step, n)) {
            return -1;
        }
    }

    if (prev < n && arr[prev].nomor == x) {
        return prev;
    }

    return -1;
}


void mergeNama(Kereta* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}


void mergeSortNama(Kereta* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortNama(arr, l, m);
        mergeSortNama(arr, m + 1, r);
        mergeNama(arr, l, m, r);    
    }
}

bool tambahData(Kereta*& arr, int& n) {
    cout << "Nomor KA: ";
    cin >> (arr + n)->nomor;
    cin.ignore();

    cout << "Nama KA : ";
    getline(cin, (arr + n)->nama);

    cout << "Asal    : ";
    getline(cin, (arr + n)->asal);

    cout << "Tujuan  : ";
    getline(cin, (arr + n)->tujuan);

    cout << "Harga   : ";
    cin >> (arr + n)->harga;

    n++;
    return true;
}

int main() {
    int n = 3;
    Kereta daftar[100] = {
        {102, "Argo Wilis", "Bandung", "Surabaya", 450000},
        {101, "Gajayana", "Malang", "Jakarta", 550000},
        {105, "Logawa", "Purwokerto", "Jember", 120000}
    };
    
    Kereta* p = daftar;

    int pilihan;
    do {
        cout << "\n=== SISTEM INFORMASI KERETA API (GENAP) ===";
        cout << "\n1. Tampil Jadwal";
        cout << "\n2. Tambah Data Baru";
        cout << "\n3. Cari Rute";
        cout << "\n4. Cari No Kereta";
        cout << "\n5. Urutkan Nama";
        cout << "\n6. Urutkan Harga";
        cout << "\n0. Keluar";
        cout << "\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanJadwal(daftar, n);
                break;

            case 2:
                tambahData(p, n);
                break;

            case 3: {
                string as, tj;
                cout << "Masukkan Asal: ";
                cin >> as;
                cout << "Masukkan Tujuan: ";
                cin >> tj;

                int hasil = linearSearchRute(daftar, n, as, tj);

                if (hasil != -1) {
                    cout << "DATA DITEMUKAN PADA INDEKS KE-" << hasil << endl;
                    cout << "KA " << (daftar + hasil)->nama << endl;
                } else {
                    cout << "\nData tidak ditemukan.\n";
                }
                break;
            }

            case 4: {
                if (n == 0) {
                    cout << "[!] Data kosong.\n";
                    break;
                }

                int cari;
                cout << "Masukkan Nomor KA: ";
                cin >> cari;

                selectionSortNomor(daftar, n);
                int idx = jumpSearchNomor(daftar, n, cari);

                if (idx != -1) {
                    cout << "\nHASIL: KA " << daftar[idx].nama
                     << " ditemukan di indeks " << idx << endl;
                } else {
                    cout << "\n[!] Nomor KA tidak ditemukan.\n";
                }
                break;
            }

            case 5:
                if (n > 0) {
                    mergeSortNama(daftar, 0, n - 1);
                    cout << "[!] Berhasil urut Nama A-Z.\n";
                }
                break;

            case 6:
                if (n > 0) {
                    selectionSortHarga(daftar, n);
                    cout << "[!] Berhasil urut Harga Termurah.\n";
                }
                break;

            case 0:
                cout << "Program Keluar...\n";
                break;

            default:
                cout << "[!] Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}