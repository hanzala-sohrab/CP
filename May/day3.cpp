class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> N, M;
        for (char c: ransomNote)
            ++N[c];
        for (char c: magazine)
            ++M[c];
        for (auto i: N)
            if (i.second > M[i.first])
                return false;
        return true;
    }
};
