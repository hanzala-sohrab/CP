#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << ' ';
        n = n & 1 ? n * 3 + 1 : n >> 1;
    }
    cout << "1\n";
    return 0;
}
