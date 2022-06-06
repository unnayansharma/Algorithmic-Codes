vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int> ans;
    int n=A.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    pq.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    s.insert(make_pair(n-1,n-1));
    for(int m=0;m<C;m++)
    {
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        int i=temp.second.first;
        int j=temp.second.second;
        int sum=A[i-1]+B[j];
        pair<int,int> temp1=make_pair(i-1,j);
        if(s.find(temp1)==s.end())
        {
            pq.push(make_pair(sum,temp1));
            s.insert(temp1);
        }
        sum=A[i]+B[j-1];
        temp1=make_pair(i,j-1);
        if(s.find(temp1)==s.end())
        {
            pq.push(make_pair(sum,temp1));
            s.insert(temp1);
        }
        
    }
    return ans;
}
