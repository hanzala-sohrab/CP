#include <bits/stdc++.h>
using namespace std;
void sort012(int[], int);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

void sort012(int a[], int n)
{
    int i, j = 0, z = 0, o = 0, t = 0;
    for (i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            swap(a[i], a[j]);
            ++j;
        }
    }
    z = j;
    for (i = j; i < n; ++i)
    {
        if (a[i] == 1)
        {
            swap(a[i], a[j]);
            ++j;
        }
    }
    o = j - z;
    t = j - o;
}
