class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> ans(len1 + len2, 0);

        for(int i = len1 - 1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0; j--){

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + ans[i + j + 1];

                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }

        string res = "";

        int i = 0;
        while(i < ans.size() && ans[i] == 0){
            i++;
        }

        while(i < ans.size()){
            res += ans[i] + '0';
            i++;
        }

        return res;
    }
};