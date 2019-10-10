vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>res(A);
    int i,j;
    for(i=0;i<A;i++)
        for(j=0;j<=i;j++)
            res[i].push_back(1);
    for(i=2;i<A;i++)
        for(j=1;j<=i;j++)
        {    
            if(i==j)
                res[i][j]=1;
            else
            res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
    return res;
}
/*
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>res(A);
    int i,j,c;
    for(i=0;i<A;i++)
        for(j=0;j<=i;j++)
            res[i].push_back(1);
    for(i=1;i<A;i++)
    {   
        c=1;
        for(j=1;j<=i;j++)
        {   
            res[i][j]=c*(i-j+1)/j;
            c=res[i][j];
        }
    }
    return res;
}
*/
