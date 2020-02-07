int Solution::canJump(vector<int> &A) {
    int temp[A.size()];
    int i=0;
    temp[0]=A[0];
    for(i=1;i<A.size();i++)
    {
        int max=A[i-1]-1>temp[i-1]-1?A[i-1]-1:temp[i-1]-1;
        if(max<0)
            return 0;
        temp[i]=max;
    }
    return 1;
}
