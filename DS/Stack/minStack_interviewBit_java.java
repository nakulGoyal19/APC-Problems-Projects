class Solution {
    Stack<Integer> s=new Stack<Integer>();
    Stack<Integer> ms=new Stack<Integer>();
    public Solution()
    {
        min=Integer.MAX_VALUE;
    }
    int min;
    public void push(int x) {
        s.push(x);
        if(ms.isEmpty()||x<=ms.peek())
            ms.push(x);
        
    }

    public void pop() {
        if(!s.isEmpty())
        {
            int num=s.pop();
            if(num==ms.peek())
                ms.pop();
        }
        
        
    }

    public int top() {
        if(s.isEmpty())
            return -1;
        return s.peek();
        
    }

    public int getMin() {
        if(ms.empty())
            return -1;
        return ms.peek();
        
    }
}
