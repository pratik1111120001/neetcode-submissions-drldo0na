class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) 
            return 1;
        int sign = (n<0);
        if(n == -1)
            return 1/x;
        n = abs(n);
        if(n == 1)
            return x;
        double ans = myPow(x,n/2);
        ans*=ans;
        if(n%2) ans*=x;
        if(sign)
            return (1/ans);
        return ans;
    }
};
