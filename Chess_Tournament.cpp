bool ispossible(vector<int> positions,int n,int c, int mid)
{
    int count=1;
    int lastplace=positions[0];
    for(int i=1;i<n;i++)
    {
        if(positions[i]-lastplace >= mid)
        {
            count++;
            lastplace=positions[i];
        }
    }
    if(count>=c)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int low=1;
    int high=positions[n-1]-positions[0];
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(ispossible(positions,n,c,mid))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return high;
}
