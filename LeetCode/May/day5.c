#define P struct Pair
P {
    int c, i;
};
int firstUniqChar(char * s){
    P p[26];
    int i, l = strlen(s), m=100000000;
    for (i=0;i<26;++i)
        p[i].c=0;
    for (i = 0; i < l; ++i) {
        ++(p[s[i]-97].c);
        p[s[i]-97].i=i;
    }
    for (i=0;i<l;++i)
        if (p[s[i]-97].c==1)
            m=m>p[s[i]-97].i?p[s[i]-97].i:m;
    return m==100000000?-1:m;
}
