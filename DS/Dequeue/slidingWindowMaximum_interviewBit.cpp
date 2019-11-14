#include<deque>
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    vector<int> res;
    for(int i=0;i<A.size();i++)
    {
        if(!q.empty()&&q.back()-q.front()>=B-1)
            q.pop_front();
        if(q.empty())
            q.push_back(i);
        else if(A[q.back()]>=A[i])
            q.push_back(i);
        else{
            while(!q.empty()&&A[q.back()]<A[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        if(i>=B-1)
        {
            res.push_back(A[q.front()]);
        }
    }
    return res;
}