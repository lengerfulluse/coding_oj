package me.hengwei.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode.com/problems/range-sum-query-immutable/.
 */
public class NumArray_303 {
    int[] sum;
    int[] nums;
    public NumArray_303(int[] nums)
    {
        this.nums = nums;
        sum = new int[nums.length];
        if(nums.length == 0)
        {
            return;
        }
        sum[0] = nums[0];
        for(int i=1; i<nums.length; i++)
        {
            sum[i] = sum[i-1] + nums[i];
        }
    }

    public int sumRange(int i, int j)
    {
        int start = Math.max(i, 0);
        int end = Math.min(j, nums.length-1);
        if(start > end)
        {
            return 0;
        }
        return sum[end] - sum[start] + nums[start];
    }

    public static void main(String[] args)
    {
        int[] nums = {};
        NumArray_303 range_sum_query_303 = new NumArray_303(nums);
        System.out.println(range_sum_query_303.sumRange(0, 2));
        System.out.println(range_sum_query_303.sumRange(2, 5));
        System.out.println(range_sum_query_303.sumRange(0, 5));

    }
}
