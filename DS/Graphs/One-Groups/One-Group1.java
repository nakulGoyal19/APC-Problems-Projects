import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


class Result {

    /*
     * Complete the 'onesGroups' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. 2D_INTEGER_ARRAY grid
     *  2. INTEGER_ARRAY queries
     */
    public static int bfs(List<List<Integer>>grid,int i,int j,int ni,int nj,int count,Boolean[][] visited)
    {
        visited[i][j]=true;
        if(grid.get(ni).get(nj)!=1)
            return count;
        if(visited[ni][nj]==true)
            return count;

        count+=1;
        if(ni+1<grid.size())
            count=bfs(grid,ni,nj,ni+1,nj,count,visited);
        if(ni-1>=0)
            count=bfs(grid,ni,nj,ni-1,nj,count,visited);
        if(nj-1>=0)
            count=bfs(grid,ni,nj,ni,nj-1,count,visited);
        if(nj+1<grid.size())
            count=bfs(grid,ni,nj,ni,nj+1,count,visited);
        return count;
    }
    public static List<Integer> onesGroups(List<List<Integer>> grid, List<Integer> queries) {
    // Write your code here
        //int dir[][]={{0,1},{0,-1},{1,0},{-1,0}};
        List<Integer> res=new ArrayList<Integer>(1);
        int n1=(grid.size())*(grid.size());
        int[] temp_result=new int[n1];
        Boolean[][] visited=new Boolean[grid.size()][grid.size()];
        for(int i=0;i<n1;i++)
            temp_result[i]=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid.size();j++)
                visited[i][j]=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid.get(i).get(j)==1&&visited[i][j]==false){
                    int count=1;
                    if(i+1<grid.size())
                        count=bfs(grid,i,j,i+1,j,count,visited);
                    int count1=1;
                    if(j+1<grid.size())
                        count1=bfs(grid,i,j,i,j+1,count,visited);
                    count=count>count1?count:count1;
                    temp_result[count]+=1;
                    //System.out.print(count+" ");
                }
            }
        }

        for(int i=0;i<queries.size();i++)
        {
            res.add(temp_result[queries.get(i)]);
        }
        return res;
        

    }

}
public class Solution {