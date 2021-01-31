#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


vector<long> riddle(vector<long> arr)
{
    long n = arr.size(), i;
    stack<long> s;
    vector<long> left(n + 1, -1), right(n + 1, n), ans(n + 1, 0);

    for (i = 0; i < n; ++i)
    {
        while (!s.empty() and arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (i = n - 1; i >= 0; --i)
    {
        while (!s.empty() and arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            right[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (i = 0; i < n; ++i)
    {
        long l = right[i] - left[i] - 1;
        ans[l] = max(ans[l], arr[i]);
    }

    for (i = n - 1; i >= 0; --i)
        ans[i] = max(ans[i], ans[i + 1]);

    vector<long> answer(n);
    for (i = 0; i < n; ++i)
        answer[i] = ans[i + 1];
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++)
    {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++)
    {
        fout << res[i];

        if (i != res.size() - 1)
        {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
