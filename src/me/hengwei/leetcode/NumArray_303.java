package me.hengwei.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode.com/problems/range-sum-query-immutable/.
 */
public class NumArray_303 {
    Map<String, Integer> rangeMap = new HashMap<>();
    int length;
    public NumArray_303(int[] nums)
    {
        this.length = nums.length;
        int i, j;
        for(i=0; i<this.length; i++)
        {
            int sum = nums[i];
            rangeMap.put(String.valueOf(i)+":"+String.valueOf(i), sum);
            for(j=i+1; j<this.length; j++)
            {
                sum += nums[j];
                rangeMap.put(String.valueOf(i)+":"+String.valueOf(j), sum);
            }
        }
    }

    public int sumRange(int i, int j)
    {
        i = Math.max(i, 0);
        j = Math.min(j, this.length);
        String key = String.valueOf(i)+":"+String.valueOf(j);
        return rangeMap.get(key);
    }

    public static void main(String[] args)
    {
        int[] nums = {-2, 0, 3, -5, 2, -1};
        NumArray_303 range_sum_query_303 = new NumArray_303(nums);
        System.out.println(range_sum_query_303.sumRange(0, 2));
        System.out.println(range_sum_query_303.sumRange(2, 5));
        System.out.println(range_sum_query_303.sumRange(0, 5));

    }
}
