package me.hengwei.leetcode;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * https://leetcode.com/problems/3sum/
 */
public class Three_Sum_15 {

    /**
     *  Simple enumerate method with O(n^3) complexity.
     * @param nums input integer arrays.
     * @return all triplets array sum equals 0
     */
    public List<List<Integer>> threeSum(int[] nums) {

        int len = nums.length;
        List<List<Integer>> sum_zero_triplets = new ArrayList<>();
        if(nums == null || nums.length < 3) {
            return sum_zero_triplets;
        }
        /* quick sort first to avoid duplicate */
        quickSort(nums, 0, nums.length-1);

        for(int i=0; i<len; i++) {
            for(int j=i+1; j<len; j++) {
                for(int k=j+1; k<len; k++) {
                    if(nums[i] + nums[j] + nums[k]  == 0) {
                        List<Integer> triplet = new ArrayList<>();
                        triplet.add(nums[i]);
                        triplet.add(nums[j]);
                        triplet.add(nums[k]);
                        if(!sum_zero_triplets.contains(triplet))
                        {
                            sum_zero_triplets.add(triplet);
                        }
                    }
                }
            }
        }
        return sum_zero_triplets;
    }

    public void quickSort(int[] nums, int start, int end) {
        if(nums == null || start >= end) {
            return;
        }

        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot+1, end);
    }

    /**
     * Exchange and partition for the array.
     */
    private int partition(int[] nums, int start, int end) {
        int pos = start;
        int pivot_value = nums[end];
        for(int i=start; i<end; i++) {
            if(nums[i] <= pivot_value) {
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
                pos++;
            }
        }
        /* set the pivot value */
        nums[end] = nums[pos];
        nums[pos] = pivot_value;
        return pos;
    }

    public static void main(String[] args) {
        Three_Sum_15 three_sum_15 = new Three_Sum_15();
        int[] nums = new int[]{5, -2, 9, -6, 7, 8, -2, 4, 1, 3, 1};
        three_sum_15.quickSort(nums, 0, nums.length-1);
        for(int i=0; i<nums.length; i++) {
            System.out.print(nums[i]+"\t");
        }
        System.out.println("Partition Done");

        List<List<Integer>> sum_zero_triplets = three_sum_15.threeSum(nums);
        Iterator it = sum_zero_triplets.iterator();
        while(it.hasNext()) {
            List<Integer> triplet = (List<Integer>)it.next();
            System.out.println(triplet.toString());
        }
    }
}
