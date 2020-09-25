#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo (long long int x) {
    return x and (!(x&(x-1)));
}

int main()
{
    // srand(time(0));
    // long long int i, j, s = 0, k = 1, n = 4, x, xor_val = 0, M = 1e3, m = LONG_MAX, u = 1048576l;
    // long a[n];
    // // cout << "A = ";
    // a[0] = 1;
    // a[1] = 2;
    // a[2] = 3;
    // a[3] = 4;
    // cout<<"1\n"<<n<<'\n';
    // cout.flush();
    // for (i = 0; i < n; ++i)
    // {
    //     // a[i] = (rand() % M) + 1;
    //     x = a[i] ^ 1048576l;
    //     s += x;
    //     // cout << a[i] << " ";
    //     xor_val ^= a[i];
    // }
    // // cout<<s<<'\n';
    // // cout.flush();
    // // cout << "\n\n";
    // // cout<<"0\t";
    // // s = 0;
    // // for (s = i = 0; i < n; ++i)
    // // {
    // //     // cout << a[i] << ' ';
    // //     s += a[i];
    // // }
    // // cout << ": " << s << '\n';
    // for (i = 1; i <= u / 2; i<<=1)
    // {
    //     s = 0;
    //     // cout << i << '\t';
    //     for (j = 0; j < n; ++j)
    //     {
    //         x = a[j] ^ i;
    //         // cout << x << ' ';
    //         s += x;
    //     }
    //     // cout << ": " << s << '\n';
    //     cout << s << '\n';
    //     cout.flush();
    // }
    // // cout << "\nXOR = " << xor_val<<'\n';
    // cout << xor_val << '\n';
    // cout.flush();
    
    
    // int x, i, n = 1048576l, v = 1048575l;
    // for (i = 1; i <= n; i<<=1)
    // {
    //     x = i ^ v;
    //     printf("%d XOR %d = %d\n", i, v, x);
    // }




    long long int t, n, j, i, p, xv, m;
    cin>>t;
    cout.flush();
    while (t--)
    {
        p = 1;
        xv = 0;
        cin>>n;
        cout.flush();
        vector<long long int> K(22, 0), s(22, 0);
        cout<<"1 1048576\n";
        cout.flush();
        cin>>s[20];
        s[0] = s[20] - n * 1048576l;
        for (j = i = 1; j < 20; ++i, ++j)
        {
            cout<<"1 "<<p<<'\n';
            cout.flush();
            cin>>s[i];
            cout.flush();
            m = (n + (s[20] - s[i]) / p) / 2;
            p *= 2;
            if (m & 1)
                xv += p;
        }
        cout<<"2 "<<xv<<'\n';
        cout.flush();
        cin>>xv;
    }
    return 0;
}