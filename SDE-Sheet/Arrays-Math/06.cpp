#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> overlappedInterval(vector<pair<int, int>>, int);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> arr, res;
        int n, x, y;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }

        res = overlappedInterval(arr, n);

        for (int i = 0; i < res.size(); i++)
            cout << res[i].first << " " << res[i].second << " ";

        cout << endl;
    }
}

vector<pair<int, int>> overlappedInterval(vector<pair<int, int>> vec, int n)
{
    sort(vec.begin(), vec.end());
    stack<pair<int, int>> s;
    s.push(vec[0]);
    vector<pair<int, int>> ans;
    int i;
    for (i = 1; i < n; ++i)
    {
        pair<int, int> x = s.top();
        if (vec[i].first <= x.second)
        {
            if (vec[i].second > x.second)
            {
                s.pop();
                s.push(make_pair(x.first, vec[i].second));
            }
        }
        else
        {
            s.push(vec[i]);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
