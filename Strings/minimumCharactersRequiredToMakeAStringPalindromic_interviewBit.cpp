int lps(string s)
{
    int i=0,j=0;
    int lp[s.length()];
    lp[0]=0;
    for(i=1;i<s.length();)
    {
        if(s[i]==s[j])
        {
            lp[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                lp[i]=0;
                i++;
            }
            else
            {
                j=lp[j-1];
            }
        }
    }
    return lp[s.length()-1];
}
string rev(string s)
{
    int l=s.length();
    for(int i=0;i<l/2;i++)
    {
        char c=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=c;
    }
    return s;
}
int Solution::solve(string A) {
    string r=rev(A);
    string res=A+'$'+r;
    int k = lps(res);
    return A.length()-k;
}
