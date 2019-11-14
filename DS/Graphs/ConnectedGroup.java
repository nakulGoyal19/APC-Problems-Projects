import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


class Result {

    /*
     * Complete the 'countGroups' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING_ARRAY related as parameter.
     */
    static void dfs(int v,Boolean[] visited,ArrayList<ArrayList<Integer>> arr)
    {
        visited[v]=true;
        for(int i=0;i<arr.get(v).size();i++)
        {
            int u=arr.get(v).get(i);
            if(!visited[u])
                dfs(u,visited,arr);
        }
    }
    public static int countGroup(List<String> related) {
    // Write your code here
        ArrayList<ArrayList<Integer>> arr=new ArrayList<ArrayList<Integer>>(related.size());
        //for(int i=0;i<related.size();i++){
        //    arr[i]=new ArrayList<Integer>();
        //}
        for(int i=0;i<related.size();i++)
        {
            ArrayList<Integer> arr1=new ArrayList<Integer>();
            for(int j=0;j<related.get(i).length();j++)
            {
                if(related.get(i).charAt(j)=='1')
                {
                    if(i!=j)
                    {
                        arr1.add(j);
                    }
                }
            }
            arr.add(arr1);
        }
        int count=0;
        Boolean visited[]=new Boolean[related.size()];
        for(int i=0;i<related.size();i++)
            visited[i]=false;
        for(int i=0;i<related.size();i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,visited,arr);
            }
        }
        return count;

    }

}
class CountConnectedGroups {
    public static void main(String[] args){
        List<String> s=new ArrayList<String>(4);
        s.add("1000");
        s.add("0100");
        s.add("0010");
        s.add("0001");
        System.out.println("Connected Groups are "+Result.countGroup(s));
    }
}
