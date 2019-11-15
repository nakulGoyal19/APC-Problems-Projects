// 0->unvisited
// 1->visitd
// 2->visited & processed
public class Solution {
    public static Boolean dfs(int v,int[] visited,ArrayList<ArrayList<Integer>> adjList)
    {
        Boolean flag=false;
        visited[v]=1;
        for(int i:adjList.get(v))
        {
            if(visited[i]==0)
                flag=dfs(i,visited,adjList);
            else if(visited[i]==1)
                return true;
        }
        visited[v]=2;
        return flag;
    }
    public int solve(int A, ArrayList<Integer> B, ArrayList<Integer> C) {
        ArrayList<ArrayList<Integer>> adjList=new ArrayList<ArrayList<Integer>>(A);
        for(int i = 0;i <= A; i++) {
            adjList.add(new ArrayList<Integer>());
        }
        for(int i=0;i<B.size();i++)
        {
            adjList.get(B.get(i)).add(C.get(i));
        }
        int[] visited=new int[A+1];
        for(int i=1;i<A;i++)
            visited[i]=0;
        Boolean flag=false;
        for(int i=1;i<A;i++)
        {
            if(visited[i]==0)
                flag = dfs(i,visited,adjList);
            if(flag==true)
                return 0;
        }
        return 1;
    }
}
