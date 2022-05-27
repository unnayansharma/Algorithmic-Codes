class Solution {
public:
    void combinations(int ind, vector<int>& candidates,vector<vector<int>>& ans,vector<int>& ds,int target)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            combinations(ind,candidates,ans,ds,target-candidates[ind]);
            ds.pop_back();
        }
        combinations(ind+1,candidates,ans,ds,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        //sort(candidates.begin(),candidates.end());
        combinations(0,candidates,ans,ds,target);
        return ans;
    }
};
