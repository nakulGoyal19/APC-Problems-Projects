vector<int> Solution::getRow(int A) {
    vector<int> res(0);
    res.push_back(1);
    if(A==0)
        return res;
    int i,j,c;
    for(i=1;i<A+1;i++)
    {
        c=1;
        for(j=1;j<=i;j++)
        {
            c=c*(i-j+1)/j;
            if(i==A)
                res.push_back(c);
        }
    }
    return res;
    
}
