class Solution {
public:
    int numberOfSteps (int num) {
        if (num == 1)
            return 1;
        int c = 0, i = num;
        while (i) {
            if (i & 1)
                --i;
            else
                i /= 2;
            ++c;
        }
        return c;
    }
};
