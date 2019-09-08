bool isAlphaNum(char c)
{
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return true;
    else
        return false;
}
int Solution::isPalindrome(string A) {
    int i=0,j=A.length()-1;
    while(i<=j)
    {
        if(!isAlphaNum(A[i]))
        {
            i++;
            continue;
        }
        if(!isAlphaNum(A[j]))
        {
            j--;
            continue;
        }
        if(A[i]!=A[j]&&abs(A[i]-A[j])!=32)
        {
            return 0;
        }
        i++;j--;
    }
    return 1;
}
