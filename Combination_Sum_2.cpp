class Solution {
public:
    
    void comb(int ind,vector<int>& candidates,vector<vector<int>>& ans, vector<int>& ds,int target)
    {
            if(target==0)
            {
                ans.push_back(ds);
                return;
            }
            
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind and candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(candidates[i]>target)
            {
                break;
            }
        ds.push_back(candidates[i]);
            comb(i+1,candidates,ans,ds,target-candidates[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        comb(0,candidates,ans,ds,target);
        return ans;
    }
};
