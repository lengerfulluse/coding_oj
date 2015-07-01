package me.hengwei.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode.com/problems/two-sum/
 */
public class Two_Sum_1 {

    /**
     * assume that each input would have exactly one solution.
     * @param nums integer arrays to be searched
     * @param target sum target
     * @return one of the integer sum equals to target value.
     */
    public int[] twoSum(int[] nums, int target) {
        int[] index = new int[2];
        if (nums == null || nums.length < 2) {
            return null;
        }
        /* store the original position of the nums array */
        Map<Integer, Integer> numPosDupMap = new HashMap<>();
        Map<Integer, Integer> numPosMap = new HashMap<>();
        for(int i = 0; i<nums.length; i++) {
            /* put the duplicated one into another map */
            if(!numPosMap.containsKey(nums[i])){
                numPosMap.put(nums[i], i+1);
            } else {
                numPosDupMap.put(nums[i], i+1);
            }
        }
        System.out.println(numPosDupMap.entrySet().toString());
        System.out.println(numPosMap.entrySet().toString());
        Arrays.sort(nums);
        int largeEnd = nums.length-1;
        int smallEnd = 0;
        while (smallEnd < largeEnd) {
            int sum = nums[smallEnd] + nums[largeEnd];
            int small = nums[smallEnd], large = nums[largeEnd];
            if(target == sum) {
                index[0] = numPosMap.get(small);
                if(small == large) {
                    index[1] = numPosDupMap.get(large);
                } else {
                    index[1] = numPosMap.get(large);
                }
                Arrays.sort(index);
                break;
            } else if(target < sum) {
                largeEnd--;
            } else {
                smallEnd++;
            }
        }
        return index;
    }

    /**
     * Test Input:
     *  [0,4,3,0], 0
     *
     * @param args
     */
    public static void main(String[] args) {
        Two_Sum_1 two_sum_1 = new Two_Sum_1();
        int[] nums = new int[]{-1,-2,-3,-4,-5};
        int[] index = two_sum_1.twoSum(nums, -8);
        System.out.println(index[0] + "\t" + index[1]);
    }
}
