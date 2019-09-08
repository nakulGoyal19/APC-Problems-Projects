int Solution::atoi(const string A) {
    int res=0,i;
    int sign=1;
    if(A[0]=='-')
        sign=-1;
    for(i=0;i<A.length();i++)
    {
        if((i==0&&A[i]=='-')||(i==0&&A[i]=='+'))
            ;
        else
        {
            if(res> INT_MAX/10||(res== INT_MAX/10)&& A[i]-'0'>7)
            {
                if(sign==1)
                    return INT_MAX;
                else
                    return INT_MIN;
                
            }
            res=res*10+(A[i]-'0');
        }
    }
    return sign*res;
}
