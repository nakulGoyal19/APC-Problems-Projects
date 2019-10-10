int Solution::repeatedNumber(const vector<int> &A) {
     vector<bool>res(A.size(),true);// for checking presence of a Number  
    for(int i=0;i<A.size();i++){
      if(res[A[i]])
      res[A[i]]=false;
        else
        return A[i];
    }
    
    /*
    int slow = A[0];
  int fast = A[A[0]];
  while (slow != fast) {
    slow = A[slow];
    fast = A[A[fast]];
  }

  fast = 0;
  while (slow != fast) {
    slow = A[slow];
    fast = A[fast];
  }
  return slow;
  */
  /*
  int i,xor1=0;
    for(i=0;i<A.size();i++)
    {
        xor1^=A[i];
        xor1^=i;
    }
    return xor1;
    */
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
