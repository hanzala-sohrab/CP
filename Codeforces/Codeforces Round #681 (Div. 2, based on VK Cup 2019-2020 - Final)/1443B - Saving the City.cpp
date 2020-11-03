/*
Find the number of 0's that appear between two 1's.

Store them in an array.

Suppose the result = cost of activating a mine

Then, using the newly obtained array, keep on checking which is minimum
    - placing the same number of mines as there are 0's between two 1's and then activating
    - simply activating another set of already present mines

Keep adding this minimum in the result.

Example:
a = 5, b = 1
string = 0110111000000000010
For the sake of simplicity, compress the string.
New string = 10100000000001
NOTE : This string compression won't affect the result.

So, the array = [1, 10]

result = 5
for (int i: array)
    result += min(a, i * b)

result = 5

for the first element in array:
    result = result + min(5, 1 * 1)

=> result = 5 + 1 = 6

for the second element in array:
    result = result + min(5, 10 * 1)

=> result = 6 + min(5, 10) = 6 + 5 = 11
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        string str;
        cin >> str;
        int i, len = str.size(), ans = 0;
        int minIndex, maxIndex;
        i = 0;
        while (i < len and str[i] == '0')
            ++i;
        if (i < len)
        {
            minIndex = i;
            maxIndex = len - 1;
            while (maxIndex >= 0 and str[maxIndex] == '0')
                --maxIndex;
            int count = 1;
            vector<int> noOfZeroesBetweenOnes;
            for (i = minIndex; i <= maxIndex; ++i)
            {
                if (str[i] == '1')
                    continue;
                if (str[i] == str[i + 1])
                    ++count;
                else
                {
                    noOfZeroesBetweenOnes.push_back(count);
                    count = 1;
                }
            }
            ans = a;
            for (i = 0; i < noOfZeroesBetweenOnes.size(); ++i)
                ans += min(a, noOfZeroesBetweenOnes[i] * b);
        }
        cout << ans << '\n';
    }
    return 0;
}