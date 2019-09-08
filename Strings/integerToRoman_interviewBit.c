string Solution::intToRoman(int A) {
    int no[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i=0;
    string res="";
    while(A!=0)
    {
        while(A>=no[i])
        {
            res+=roman[i];
            A-=no[i];
        }
        i++;
    }
    return res;
}
