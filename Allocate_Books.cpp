int ispossible(vector<int>& A,int pages,int students)
{
    int cnt=0;
    int sumallocated=0;
    for(int i=0;i<A.size();i++)
    {
        if(sumallocated+A[i] > pages)
        {
            cnt++;
            sumallocated=A[i];
            if(sumallocated>pages)
                return false;
        }
        else
        {
            sumallocated+=A[i];
        }
    }
    if(cnt<students)
        return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {    
    if(B>A.size())
    {
        return -1;
    }
    int low=A[0];
    int high=0;
    for(int i=0;i<A.size();i++)
    {
        high=high+A[i];
        low=min(low,A[i]);
    }
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(ispossible(A,mid,B))
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}
