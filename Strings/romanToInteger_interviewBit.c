int romanToInt1(char ch)
{
    if(ch=='I')
        return 1;
    if(ch=='V')
        return 5;
    if(ch=='X')
        return 10;
    if(ch=='L')
        return 50;
    if(ch=='C')
        return 100;
    if(ch=='D')
        return 500;
    if(ch=='M')
        return 1000;
    return 0;
}
int Solution::romanToInt(string A) {
    int res=0;
    int len=A.length();
    for(int i=0;i<len;i++)
    {
        if((i<len-1)&&(romanToInt1(A[i])<romanToInt1(A[i+1])))
        {
            res-=romanToInt1(A[i]);
            //res+=A[i+1];
            //i++;
        }
        else
            res+=romanToInt1(A[i]);
        //cout<<res<<" ";
    }
    return res;
}
