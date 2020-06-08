class Solution {
public:
    string defangIPaddr(string address) {
        int i, l = address.size();
        string ip;
        for (char c: address)
            if (c != '.')
                ip += c;
            else
                ip += "[.]";
        return ip;
    }
};
