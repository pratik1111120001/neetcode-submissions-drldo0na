class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size();
        j--;
        vector<int> ans;
        while(i<j)
        {
            int curr_sum = numbers[i] + numbers[j];
            if(curr_sum > target) j--;
            else if(curr_sum < target) i++;
            else
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
        }
        return ans;
    }
};
