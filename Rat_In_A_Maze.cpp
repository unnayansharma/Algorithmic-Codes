// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int n,vector<vector<int>> &visited,vector<string>& ans,int i,int j,string move)
    {
        int flag=0;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(move);
            return;
        }
        if(i+1 <n && visited[i+1][j]==0 && m[i+1][j]!=0)
        {
            visited[i][j]=1;
            solve(m,n,visited,ans,i+1,j,move+'D');
            visited[i][j]=0;
        }
        if(j-1 >=0 && visited[i][j-1]==0 && m[i][j-1]!=0)
        {
            visited[i][j]=1;
            solve(m,n,visited,ans,i,j-1,move+'L');
            visited[i][j]=0;
        }
        if(j+1 <n && visited[i][j+1]==0 && m[i][j+1]!=0)
        {
            visited[i][j]=1;
            solve(m,n,visited,ans,i,j+1,move+'R');
            visited[i][j]=0;
        }
        if(i-1 >=0 && visited[i-1][j]==0 && m[i-1][j]!=0)
        {
            visited[i][j]=1;
            solve(m,n,visited,ans,i-1,j,move+'U');
            visited[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited;
        vector<string> ans;
        //string s="";
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                v.push_back(0);
            }
            visited.push_back(v);
        }
        if(m[0][0]==1)
            solve(m,n,visited,ans,0,0,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
