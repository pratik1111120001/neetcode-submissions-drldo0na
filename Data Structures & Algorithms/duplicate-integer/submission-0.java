class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap<Integer,Integer> freq = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++)
        {
            if(freq.containsKey(nums[i]))
                return true;
            freq.put(nums[i],nums[i]);
        }
        return false;
    }
}