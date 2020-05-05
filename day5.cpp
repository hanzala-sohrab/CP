class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> f;
        int i, l = s.size();
        for (char c:s)
            ++f[c-97];
        for (i = 0; i < l; ++i)
            if (f[s[i]-97] == 1)
                return i;
        return -1;
    }
};
