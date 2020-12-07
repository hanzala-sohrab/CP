#include <iostream>

using std::cout;
using std::cin;

#define ll long long

ll recursive_binary_exponentiation(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    ll answer = recursive_binary_exponentiation(a, b / 2, m);
    return ((answer * answer * (b & 1 ? a : 1)) % m + m) % m;
}

ll iterative_binary_exponentiation(ll a, ll b, ll m) {
    a %= m;
    ll answer = 1;
    while (b)
    {
        if (b & 1)
            answer = answer * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return answer;
}

int main() {
    ll a = 13, b = 20, m = 1e9 + 7;
    cout << recursive_binary_exponentiation(a, b, m) << '\n';
    cout << iterative_binary_exponentiation(a, b, m) << '\n';
    return 0;
}