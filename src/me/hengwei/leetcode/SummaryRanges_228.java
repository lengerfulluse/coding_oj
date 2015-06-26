package me.hengwei.leetcode;

import java.util.List;
import java.util.ArrayList;

/**
 * https://leetcode.com/problems/summary-ranges/.
 */
public class SummaryRanges_228 {

    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<>();
        /* null input array or length equals to 0, return empty directly*/
        if (nums == null || nums.length == 0) {
            return ranges;
        }
        int start, end;
        start=nums[0];
        end=nums[0];
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] > end) {
                addRangePair(ranges, start, end-1);
                start=end=nums[i];
            }
            end++;
        }
        /* additional last pair at the end */
        addRangePair(ranges, start, end-1);
        return ranges;
    }

    public void addRangePair(List<String> ranges, int start, int end) {
        if(start > end) {
            return;
        } else if(start == end) {
            ranges.add(String.valueOf(start));
        } else {
            String pair = String.valueOf(start) + "->" + String.valueOf(end);
            ranges.add(pair);
        }
    }

    public static void main(String[] args) {
        SummaryRanges_228 summaryRanges_228 = new SummaryRanges_228();
        int[] input = new int[0];
        System.out.println(input.length);
        List<String> output = summaryRanges_228.summaryRanges(input);
        for (int i = 0; i < output.size(); i++) {
            System.out.println(output.get(i));
        }
    }
}
