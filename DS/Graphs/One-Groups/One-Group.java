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

    public static int func(Integer a[][], int size, Integer flag[][], int i, int j) {
        int res = 0;
        flag[i][j] = 1;
        res++;
        if( ((i-1) >= 0) && (a[i-1][j] == 1) && flag[i-1][j] == 0) {
            res+=func(a, size, flag, i-1, j);
        }
        if( ((i+1) < size) && (a[i+1][j] == 1) && flag[i+1][j] == 0)  {
            res+=func(a, size, flag, i+1, j);
        }
        if( ((j-1) >= 0) && (a[i][j-1] == 1 && flag[i][j-1] == 0) ) {
            res+=func(a, size, flag, i, j-1);
        }
        if( ((j+1) < size) && (a[i][j+1] == 1 && flag[i][j+1] == 0) ) {
            res+=func(a, size, flag, i, j+1);
        }
        return res;
    }


    public static List<Integer> onesGroups(List<List<Integer>> grid, List<Integer> queries) {
        // Write your code here
        Integer arr[][] = new Integer[grid.size()][grid.size()];
        Integer vis[][] = new Integer[grid.size()][grid.size()];
        List<Integer> fina = new ArrayList<Integer>();
        List<Integer> res = new ArrayList<Integer>();
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                arr[i][j] = grid.get(i).get(j);
                vis[i][j] = 0;
            }
        }
        for(int i = 0; i < grid.size() ;i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                count = 0;
                if(vis[i][j] == 0 && arr[i][j] == 1)
                {
                    count = func(arr, grid.size(), vis, i, j);
                    res.add(count);
                }
            }
        }
        for(int i = 0; i < queries.size(); i++) {
            int f = 0;
            for(int j = 0 ; j < res.size(); j++)
            {
                if(queries.get(i) == res.get(j)) {
                    f++;
                }
            }
            fina.add(f);
        }
    return fina;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int gridRows = Integer.parseInt(bufferedReader.readLine().trim());
        int gridColumns = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> grid = new ArrayList<>();

        for (int i = 0; i < gridRows; i++) {
            String[] gridRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> gridRowItems = new ArrayList<>();

            for (int j = 0; j < gridColumns; j++) {
                int gridItem = Integer.parseInt(gridRowTempItems[j]);
                gridRowItems.add(gridItem);
            }

            grid.add(gridRowItems);
        }

        int queriesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> queries = new ArrayList<>();

        for (int i = 0; i < queriesCount; i++) {
            int queriesItem = Integer.parseInt(bufferedReader.readLine().trim());
            queries.add(queriesItem);
        }

        List<Integer> result = Result.onesGroups(grid, queries);

        for (int i = 0; i < result.size(); i++) {
            bufferedWriter.write(String.valueOf(result.get(i)));

            if (i != result.size() - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
