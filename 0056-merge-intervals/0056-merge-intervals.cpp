class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans = {{0,0}};
        sort(intervals.begin(), intervals.end());
        ans[0] = intervals[0];
        for(int i=1; i<intervals.size(); i++){
            if(ans[ans.size()-1][1]>=intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};