package me.hengwei.interview;


import java.util.Arrays;

/**
 * Find the topK(sequential or non-sequential) with quick sorted algorithm.
 */
public class QuickSortWithTopK {
    public static void quickSortWithTopK(int[] array, int k) {
        if(array == null || array.length == 0 || k == 0) {
            return;
        }
        quickSortWithNonSequenceTopK(array, 0, array.length-1, k);
    }

    public static void quickSortWithNonSequenceTopK(int[] array, int start, int end, int k) {
        if (start == end && k == 1) {
            System.out.println(array[start]);
        }
        if (array == null || start >= end) {
            return;
        }
        int pivot = partition(array, start, end);

        if (end - pivot + 1 == k) {
            for(int i = pivot; i<= end; i++) {
                System.out.print(array[i] + "\t");
            }
        } else if (end - pivot + 1 > k) {
            quickSortWithNonSequenceTopK(array, pivot+ 1, end, k);
        } else {
            /* we already know the biggest ones */
            for(int i = pivot; i<= end; i++) {
                System.out.print(array[i] + "\t");
            }
            quickSortWithNonSequenceTopK(array, start, pivot-1, k - (end - pivot + 1));
        }
    }

    public static int partition(int[] array, int start, int end) {
        int pos = start+1, pivotValue = array[start];
        for(int i=start+1; i<= end; i++) {
            if(array[i] <= pivotValue) {
                swap(array, pos, i);
                pos++;
            }
        }
        pos--;
        swap(array, start, pos);
        return pos;
    }

    public static void swap(int[] array, int i, int j) {
        if (i == j) {
            return;
        }
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {

        int[] array = new int[] {-1, 10, 8, 23, 78, 11, 6, -2, 9, 0, 100};
        int k = 3;
        QuickSortWithTopK.quickSortWithTopK(array, k);
    }
}
