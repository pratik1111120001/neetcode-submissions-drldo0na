class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            if(digits[i] + carry == 10) digits[i]=0;
            else digits[i]+=carry,carry=0;
        }
        if(carry > 0) digits.insert(digits.begin(),1);
        return digits;
    }
};
