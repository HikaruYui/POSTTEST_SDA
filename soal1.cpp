#include <iostream>
using namespace std;

int Findmin(int fibonacci[], int n, int &indeks) {
    int min = fibonacci[0];
    indeks = 0;

for(int i = 1; i < n; i++) {
    if(fibonacci[i] < min) {
        min = fibonacci[i];
    }
}
return min;

}

int main() {
    int fibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    int indeks;
    int min = Findmin(fibonacci, 8, indeks);

    cout << "Nilai minimumnya adalah: " << min << endl;
    cout << "Indeks minimumnya: " << indeks << endl;

return 0;

}

/*
Hasil Analisis kompleksitas waktu:

Best case:
Terjadi saat tidak ada elemen yang lebih kecil dari elemen pertama.
Walaupun tidak ada perubahan nilai minimum, perulangan tetap berjalan
sebanyak (n-1) kali untuk melakukan pengecekan.
Kompleksitasnya = O(n).

Worst case:
Terjadi saat setiap elemen berikutnya selalu lebih kecil dari minimum sebelumnya.
Perulangan tetap berjalan (n-1) kali dan setiap iterasi melakukan update nilai minimum.
Kompleksitasnya = O(n).

*/