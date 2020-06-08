class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int i, j = 0, l = J.size(), c;
        bool f[52] = {false};
        for (i = 0; i < l; ++i) {
            c = J[i];
            if ('a' <= c && c <= 'z')
                f[c - 97] = true;
            else
                f[(c - 65) + 26] = true;
        }
        for (c = S[0], i = 0, l = S.size(); i < l; c = S[++i])
            if ((c > 96 && f[c - 97]) || (c > 64 && c < 97 && f[(c - 65) + 26]))
                ++j;
        return j;
    }
};
