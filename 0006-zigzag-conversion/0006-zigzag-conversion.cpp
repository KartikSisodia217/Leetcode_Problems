class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        int len = s.size();
        int factor = 2 * numRows - 2;
        string ans = "";

        for (int i = 0; i < numRows; i++) {

            int j = i;
            bool first = true;

            while (j < len) {
                ans += s[j];

                if (i == 0 || i == numRows - 1) {
                    j += factor;
                } else {
                    if (first)
                        j += factor - 2 * i;
                    else
                        j += 2 * i;

                    first = !first;
                }
            }
        }

        return ans;
    }
};