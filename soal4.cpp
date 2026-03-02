#include <iostream>
using namespace std;

void tukar(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp; 
}

int main() {
int x, y;

cout << "Silakan input nilai X" << endl;
cin >> x;

cout << "Silakan input nilai Y" << endl;
cin >> y;

cout << "Sebelum pertukaran: " << endl;
cout << "x = " << x << " " << "y = " << y << endl;

tukar(&x, &y);

cout << "\nSetelah pertukaran: " << endl;
cout << "x = " << x << " " << "y = " << y << endl;


return 0;

}


