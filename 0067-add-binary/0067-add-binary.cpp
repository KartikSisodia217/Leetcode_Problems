class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        int digit_a = 0;
        int digit_b = 0;
        int curr;

        string ans = "";
        bool carry = false;

        while (i >= 0 || j >= 0) {

            if (i >= 0) {
                digit_a = a[i] - '0';
                i--;
            } else {
                digit_a = 0;
            }

            if (j >= 0) {
                digit_b = b[j] - '0';
                j--;
            } else {
                digit_b = 0;
            }

            curr = digit_a + digit_b;

            if (curr == 2) {
                if (carry) {
                    ans += '1';
                } else {
                    ans += '0';
                }
                carry = true;
            }
            else {
                if (carry) {
                    if (curr == 1) {
                        ans += '0';
                        carry = true;
                    }
                    else {
                        ans += '1';
                        carry = false;
                    }
                }
                else {
                    ans += (curr + '0');
                    carry = false;
                }
            }
        }

        if (carry) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};