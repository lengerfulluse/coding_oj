package me.hengwei.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode.com/problems/range-sum-query-immutable/.
 */
public class NumArray_303 {
    Map<String, Integer> rangeMap = new HashMap<>();
    int[] nums;
    public NumArray_303(int[] nums)
    {
        this.nums = nums;
    }

    public int sumRange(int i, int j)
    {
        i = Math.max(i, 0);
        j = Math.min(j, nums.length);
        String key = String.valueOf(i)+":"+String.valueOf(j);
        if(rangeMap.containsKey(key))
        {
            return rangeMap.get(key);
        }
        int tmp=i, sum=0;
        while(tmp<=j)
        {
            sum += nums[tmp];
            rangeMap.put(String.valueOf(i)+":"+String.valueOf(tmp), sum);
            tmp++;
        }
        return sum;
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
