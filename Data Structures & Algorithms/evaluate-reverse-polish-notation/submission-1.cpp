class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> token;
        for(auto it : tokens)
        {
            if(it=="+" || it=="-" || it=="*" || it=="/")
            {
                int val1 = token.top();
                token.pop();
                int val2 = token.top();
                token.pop();
                if(it=="+") val2+=val1;
                else if(it=="-") val2-=val1;
                else if(it=="*") val2*=val1;
                else val2/=val1;
                token.push(val2);
            }
            else
            {
                int c=0;
                int sign=1;
                int i=0,n=it.size();
                if(it[i]=='-') sign=-1,i++;
                for(;i<n;i++) c*=10,c+=(it[i]-'0');
                c*=sign;
                token.push(c);
            }
        }
        return token.top();
    }
};
