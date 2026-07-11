class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        int shortest = 0;
        for(int i = 0; i<len; i++){
            if(strs[i].size()< strs[shortest].size()){
                shortest = i;
            }
        }

        string ans = "";
        bool match = true;
        
        for(int i = 0; i<strs[shortest].size(); i++){
            char c = strs[shortest][i];

            for(int j = 0; j<strs.size(); j++){
                if (strs[j][i] != c) {
                    match = false;
                    break;
                }
            }
            if (!match)
                break;

            ans += c;
        }
        return ans;
    }
};