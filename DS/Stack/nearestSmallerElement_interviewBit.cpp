vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> res;
    for(int i=0;i<A.size();)
    {
        if(s.empty())
        {
            s.push(i);
            res.push_back(-1);
            i++;
        }
        else if(A[i]>A[s.top()])
        {
            res.push_back(A[s.top()]);
            s.push(i);
            i++;
        }
        else
        {
            s.pop();
        }
    }
    return res;
}
