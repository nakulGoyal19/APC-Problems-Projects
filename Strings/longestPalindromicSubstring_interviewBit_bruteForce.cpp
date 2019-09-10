string Solution::longestPalindrome(string A) {
    int l=0,h,max=1;
    int start=0;
    for(int i=0;i<A.length();i++)
    {
        l=i-1;
        h=i;
        while((l>=0)&&(h<A.length())&&(A[l]==A[h]))
        {
            if(max<h-l+1)
            {   
                max=h-l+1;
                start=l;
            }
        l--;
        h++;
        }
        l=i-1;
        h=i+1;
        while((l>=0)&&(h<A.length())&&(A[l]==A[h]))
        {
            if(max<h-l+1)
            {   
                max=h-l+1;
                start=l;
            }
        l--;
        h++;
        }
    }
    string res="";
    int end=start+max;
    while(start!=end)
    {
        res+=A[start];
        start++;
    }
    return res;
}
