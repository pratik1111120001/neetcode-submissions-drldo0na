class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> ind = new HashMap<>();
        int n = nums.length;
        int[] ans = new int[2];
        for(int i=0;i<n;i++)
        {
            if(ind.containsKey(target - nums[i])) 
            {
                ans[0] = ind.get(target - nums[i]);
                ans[1] = i;
                return ans;
            }
            ind.put(nums[i], i);
        }
        return ans;
    }
}
