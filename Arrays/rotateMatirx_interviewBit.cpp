void Solution::rotate(vector<vector<int> > &A) {
    int temp;
    for(int i=0;i<A.size()/2;i++)
    {
        for(int j=i;j<A.size()-1-i;j++)
        {
            temp=A[i][j];
            A[i][j]=A[A.size()-1-j][i];
            A[A.size()-1-j][i]=A[A.size()-1-i][A.size()-1-j];
            A[A.size()-1-i][A.size()-1-j]=A[j][A.size()-1-i];
            A[j][A.size()-1-i]=temp;
        }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
