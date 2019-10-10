int cmp(string a,string b)
{
    return a+b>b+a;
}
string Solution::largestNumber(const vector<int> &A) {
    if(A.size()==1)
        return to_string(A[0]);
    vector<string>As(0);
    for(int i=0;i<A.size();i++)
    {
        As.push_back(to_string(A[i]));
    }
    sort(As.begin(),As.end(),cmp);
    string res="";
    for(int i=0;i<As.size();i++)
    {
        if(As[i]=="0")
            return "0";
        res+=As[i];
    }
    return res;
}

