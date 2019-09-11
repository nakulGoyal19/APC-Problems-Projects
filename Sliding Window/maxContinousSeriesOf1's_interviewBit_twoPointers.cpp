vector<int> Solution::maxone(vector<int> &A, int B) {
    int l=0,r=0,c=0;
    int max=-1;
    int start=0,end=0;
    while(r<A.size())
    {
        if(A[r]==1)
            r++;
        else if(c<B&&A[r]==0)
        {
            c++;
            r++;
        }
        else
        {
            if(A[l]==0)
            {
                if(c>0)
                    c--;
            }
            l++;
        }
        if(l>r)r=l;
        if(r-l+1>max)
        {
            max=r-l+1;
            start=l;
            end=r;
        }
    }
    vector<int>res;
    for(int i=start;i<end;i++)
        res.push_back(i);
    return res;
}
