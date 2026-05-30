class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, right, n = nums.length;
        int res = n + 1, window = 0;

        for(right = 0; right < n; right++){
            window += nums[right];
            while(window >= target){
                res = Math.min(res, right - left + 1);
                window -= nums[left];
                left++;
            }
        }
        return res == n + 1 ? 0 : res;
    }
}