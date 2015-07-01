package me.hengwei.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

/**
 * https://leetcode.com/problems/3sum/
 */
public class Three_Sum_15 {

    /**
     * for loop within 2SUM. LTE error mainly caused without duplicated clean and move forward.
     */
    public List<List<Integer>> threeSum_v2(int[] nums) {
        int len = nums.length;
        List<List<Integer>> sum_zero_triplets = new ArrayList<>();
        int targetSum, smallEnd, largeEnd, i=0;
        Arrays.sort(nums);
        while (i < len - 1) {
            int third = nums[i];
            targetSum = 0 - third;
            int sourceSum;
            smallEnd = i+1;
            largeEnd = len - 1;
            while(smallEnd < largeEnd) {
                int small = nums[smallEnd];
                int large = nums[largeEnd];
                sourceSum = nums[smallEnd] + nums[largeEnd];
                if(sourceSum == targetSum) {
                    sum_zero_triplets.add(Arrays.asList(nums[i], nums[smallEnd], nums[largeEnd]));
                }
                if(sourceSum >= targetSum) {
                    while(nums[largeEnd] == large && smallEnd < largeEnd)
                    {
                        largeEnd--;
                    }
                }
                if(sourceSum <= targetSum){
                    while(nums[smallEnd] == small && smallEnd < largeEnd)
                    {
                        smallEnd++;
                    }
                }
            }
            while (nums[i] == third && i < len - 1) i++;
        }
        return sum_zero_triplets;
    }

    /**
     * two end search approach.
     * @param nums input integer arrays.
     * @return all triplets array sum equals 0.
     */
    public List<List<Integer>> threeSum_v1(int[] nums) {
        int len = nums.length;
        List<List<Integer>> sum_zero_triplets = new ArrayList<>();
        if(nums == null || nums.length < 3) {
            return sum_zero_triplets;
        }

        /* quick sort first to avoid duplicate */
        quickSort(nums, 0, len-1);

        /* two-end search */
        int smallEnd=0, largeEnd=len-1, sum;
        while(smallEnd < largeEnd - 1) {
            sum = nums[smallEnd] + nums[largeEnd];
            int sumSmallEnd=smallEnd, sumLargeEnd=largeEnd;
            int sumSmall = sum, sumLarge = sum;
            int loopSum = sum;
            System.out.println("Search 3rd for : " + nums[smallEnd] + "\t" + nums[largeEnd]);
            int posSmall = smallEnd + 1, posLarge = largeEnd - 1;
            while(sumLarge == 0 || sumSmall == 0) {
                int index = posSmall;
                while(index < posLarge) {
                    if(nums[index] == 0) {
                        System.out.println("Matched :" + nums[index]);
                        List<Integer> triplet = this.createTriplet(smallEnd, index, largeEnd);
                        if(!sum_zero_triplets.contains(triplet)) {
                            sum_zero_triplets.add(triplet);
                        }
                        break;
                    }
                    index++;
                }
                sumSmall = nums[largeEnd] + nums[posSmall];
                posSmall = posSmall + 1;
                sumLarge = nums[smallEnd] + nums[posLarge];
                posLarge = posLarge - 1;
                sumSmallEnd = smallEnd + 1;
                sumLargeEnd = largeEnd - 1;
            }
            /* sum large then 0, search third from small end */
            if(sumLarge > 0 || sumSmall > 0) {
                sum = nums[sumSmallEnd] + nums[largeEnd];
                loopSum = sum + nums[posSmall];
                /* keep increasing 3rd value gradually*/
                while(loopSum < 0 && posSmall < largeEnd) {
                    System.out.println("Small End Searching :" + nums[posSmall] + "\t Sum: " + loopSum);
                    posSmall++;
                    loopSum = sum + nums[posSmall];
                }
                if(loopSum == 0) {
                    System.out.println("Matched :" + nums[posSmall]);
                    List<Integer> triplet = this.createTriplet(sumSmallEnd, posSmall, largeEnd);
                    if(!sum_zero_triplets.contains(triplet)) {
                        sum_zero_triplets.add(triplet);
                    }
                }
                largeEnd--;
            }
            if(sumSmall < 0 || sumLarge < 0){ /* sum small then 0, search third from large end */
                sum = nums[smallEnd] + nums[sumLargeEnd];
                loopSum = sum + nums[posLarge];
                /* keep decreasing 3rd value gradually */
                while(loopSum > 0 && posLarge > smallEnd) {
                    System.out.println("Large End Searching :" + nums[posLarge] + "\t Sum: " + loopSum);
                    posLarge--;
                    loopSum = sum + nums[posLarge];
                }
                if(loopSum == 0) {
                    System.out.println("Matched :" + nums[posLarge]);
                    List<Integer> triplet = createTriplet(smallEnd, posLarge, sumLargeEnd);
                    if(!sum_zero_triplets.contains(triplet)) {
                        sum_zero_triplets.add(triplet);
                    }
                }
                smallEnd++;
            }
        }
        return sum_zero_triplets;
    }

    private List<Integer> createTriplet(int small, int middle, int large) {
        List<Integer> triplet = new ArrayList<>();
        triplet.add(small);
        triplet.add(middle);
        triplet.add(large);
        return triplet;
    }

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
        long quickStart = System.nanoTime();
        quickSort(nums, 0, nums.length-1);
        long quickEnd = System.nanoTime();
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
        long sumEnd = System.nanoTime();
        System.out.println("QuickSort: " + (quickEnd - quickStart));
        System.out.println("Sum: " + (sumEnd - quickEnd));
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
        int[] nums = new int[]{ 7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6 };
        three_sum_15.quickSort(nums, 0, nums.length-1);
        for(int i=0; i<nums.length; i++) {
            //System.out.print(nums[i] + "\t");
        }

        //System.out.println("Quick sort done!");

        List<List<Integer>> sum_zero_triplets = three_sum_15.threeSum(nums);
        Iterator it = sum_zero_triplets.iterator();
        while(it.hasNext()) {
            List<Integer> triplet = (List<Integer>)it.next();
            //System.out.println(triplet.toString());
        }

        System.out.println("V2 result:");
        List<List<Integer>> sum_zero_triplets_v2 = three_sum_15.threeSum_v2(nums);
        it = sum_zero_triplets_v2.iterator();
        while(it.hasNext()) {
            List<Integer> triplet = (List<Integer>)it.next();
            System.out.println(triplet.toString());
        }
    }
}
