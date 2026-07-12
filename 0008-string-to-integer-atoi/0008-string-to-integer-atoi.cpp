class Solution {
public:
    int StrToInt(char c){
        int num = c - 48;
        return num;
    }

    int myAtoi(string s) {
        int len = s.size();
        long long ans = 0;
        bool positive = true;

        bool foundnum = false;
        bool foundsign = false;

        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                if(!foundnum && !foundsign){
                    continue;
                }
                else{
                    break;
                }
            }
            else if(s[i] == '+'){
                if(!foundnum && !foundsign){
                    foundsign = true;
                    continue;
                }
                else{
                    break;
                }
            }
            else if(s[i] == '-'){
                if(!foundsign && !foundnum){
                    positive = false;
                    foundsign = true;
                    continue;
                }
                else{
                    break;
                }
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                foundnum = true;

                ans = ans * 10 + StrToInt(s[i]);

                if(positive && ans > INT_MAX)
                    return INT_MAX;

                if(!positive && ans > (long long)INT_MAX + 1)
                    return INT_MIN;
            }
            else{
                break;
            }
        }

        if(positive){
            return (int)ans;
        }
        else{
            return (int)(-ans);
        }
    }
};