int Solution::lengthOfLastWord(const string A) {
    int len=0;
    for(int i=A.length()-1;i>=0;i--)
    {
        if(A[i]==' ')
        {
            if(len!=0)
                return len;
        }
        else
        {
            len++;
        }
    }
    return len;
}
