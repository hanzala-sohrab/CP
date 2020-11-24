#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int i, T, l, a, b;
    scanf("%d", &T);
    while (T--)
    {
        char s[151];
        scanf("%s", s);        
        l = strlen(s);
        a = 0;
        b = 0;
        for (i = 0; i < l; ++i)
        {
            if (s[i] == 'S')
            {
                if (i + 1 < l && s[i + 1] == 'U')
                {
                    if (i + 2 < l && s[i + 2] == 'V')
                    {
                        if (i + 3 < l && s[i + 3] == 'O')
                        {
                            if (i + 4 < l && s[i + 4] == 'J')
                            {
                                if (i + 5 < l && s[i + 5] == 'I')
                                {
                                    if (i + 6 < l && s[i + 6] == 'T')
                                    {
                                        ++a;
                                        i += 6;
                                    }
                                    else
                                    {
                                        ++b;
                                        i += 5;
                                    }
                                }
                                else
                                {
                                    ++b;
                                    i += 4;
                                }
                            }
                            else
                            {
                                ++b;
                                i += 3;
                            }
                        }
                        else
                            i += 2;
                    }
                    else
                        i += 1;
                }
            }
        }
        printf("SUVO = %d, SUVOJIT = %d\n", b, a);
    }
    return 0;
}
