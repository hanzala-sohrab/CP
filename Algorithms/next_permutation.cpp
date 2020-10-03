#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::sort;
using std::swap;
using std::reverse;

// Slightly modified binary search
int find(vector<int> a, int l, int r, int k) {
    int i, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (a[m] <= k)
            r = m - 1;
        else
        {
            l = m + 1;

            // For finding the index of the element
            // just greater than 'k'.
            if (i == -1 or a[i] >= a[m])
                i = m;
        }
    }
    return i;
}

vector<int> next_arrangement(vector<int> a) {
    int i, j, n = a.size();



    // Start from the end and find the first index from
    // the last where the sequence becomes non-decreasing.
    for (i = n - 2; i >= 0 and a[i] >= a[i + 1]; --i);

    if (i < 0)
    {
        // The entire sequence is in decreasing order.
        // In this case, there's no next permutation.
        // Return the array sorted in increasing order.
        sort(a.begin(), a.end());
        return a;
    }

    // Find the element that is just greater than the
    // element at index 'i'.
    j = find(a, i + 1, n - 1, a[i]);

    swap(a[j], a[i]);
    reverse(a.begin() + i + 1, a.end());

    return a;
}

void display(vector<int> a) {
    int i, n = a.size();
    for (i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    // Taking user input
    // int i, n;
    // cin >> n;
    // vector<int> a(n);
    // for (i = 0; i < n; ++i)
    //     cin >> a[i];


    // Sample input
    vector<int> a = {1, 2, 3, 4, 56, 5, 6};

    display(next_arrangement(a));

    return 0;
}