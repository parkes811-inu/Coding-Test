#include<iostream>

using namespace std;

int main(void) {
    int a, b, c = 0;
    
    cin >> a >> b >> c;
    
    if(2 <= a && b && c <= 10000) {
        cout << (a+b)%c << '\n';
        cout <<(a%c + b%c)%c << '\n';
        cout << (a*b)%c << '\n';
        cout << (a%c * b%c)%c << '\n';
    }
    return 0;
}