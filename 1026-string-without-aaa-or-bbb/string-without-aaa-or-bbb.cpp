class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if (B > A) {
            string s = strWithout3a3b(B, A);
            for (char &c : s)
                c = (c == 'a') ? 'b' : 'a';
            return s;
        }

        string ans;
        int groups = (A + 1) / 2;
        int mandatory = groups - 1;
        int extra = B - mandatory;

        while (A > 0) {
            ans += 'a';
            --A;
            if (A > 0) {
                ans += 'a';
                --A;
            }
            if (mandatory > 0) {
                ans += 'b';
                --mandatory;
                --B;
            }
            if (extra > 0 && B > 0) {
                ans += 'b';
                --extra;
                --B;
            }
        }
        while (B-- > 0)
            ans = 'b' + ans;

        return ans;
    }
};