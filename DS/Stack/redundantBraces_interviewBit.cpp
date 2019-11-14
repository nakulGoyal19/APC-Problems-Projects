int Solution::braces(string A) {
    stack<int> s;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='('||A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/')
            s.push(A[i]);
        else if(A[i]==')')
        {
            if(s.top()=='(')
                return 1;
            while(!s.empty()&&s.top()!='(')
                s.pop();
            s.pop();
        }
    }
    return 0;
}
