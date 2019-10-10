vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size()+A.size()-1;
    vector<vector<int>>a(n);
    /*for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<=i;j++)
            a.push_back(0);
    }
    for(int i=0;i<n-n/2;i++)
    {
        for(int j=0;j<A.size()-i;j++)
            a.push_back(0);
    }*/
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            a[i+j].push_back(A[i][j]);
        }
    }
    return a;
}
