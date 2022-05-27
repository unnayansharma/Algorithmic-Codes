class Solution {
public:
    bool ispalindrome(string s,int ind,int i)
    {
        while(ind<=i)
        {
            if(s[ind++]!=s[i--])
                return false;
        }
        return true;
    }
    void solve(int ind,vector<vector<string>>& ans,vector<string>& ds,string s)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(ispalindrome(s,ind,i))
            {
                ds.push_back(s.substr(ind,i-ind+1));
                solve(i+1,ans,ds,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,ans,ds,s);
        return ans;
    }
};
