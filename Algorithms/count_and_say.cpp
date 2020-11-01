 string Solution::countAndSay(int A) {
     
    //  Dynamic Programming approach
    // string s, a[A];
    // a[0] = "1";
    // int i, c, j;
    // for (i = 1; i < A; a[i] = s, ++i)
    //     for (c = 1, s = "", j = 0; j < a[i - 1].size(); ++j)
    //         if (j + 1 < a[i - 1].size() and a[i - 1][j] == a[i - 1][j + 1])
    //             ++c;
    //         else
    //         {
    //             s += to_string(c) + a[i - 1][j];
    //             c = 1;
    //         }
    // return a[A - 1];
    
    
    // Space-optimized approach
    string s, a = "1";
    int i, c, j;
    for (i = 1; i < A; a = s, ++i)
        for (c = 1, s = "", j = 0; j < a.size(); ++j)
            if (j + 1 < a.size() and a[j] == a[j + 1])
                ++c;
            else
            {
                s += to_string(c) + a[j];
                c = 1;
            }
    return a;
}
