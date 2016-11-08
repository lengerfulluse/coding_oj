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
        quickSort(array, 0, array.length-1, k);
    }

    public static void quickSort(int[] array, int start, int end, int k) {
        if (array == null || start >= end) {
            return;
        }
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot-1, k);
        quickSort(array, pivot+1, end, k);
    }

    public static int partition(int[] array, int start, int end) {
        int pos = start, pivotValue = array[start];
        int pivot = start;
        for(int i=start + 1; i<= end; i++) {
            if(array[i] < pivotValue) {
                swap(array, pos, i);
                pivot = i;
                pos++;
            }
        }
        swap(array, pivot, pos);
        return pos;
    }

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {

        int[] array = new int[] {-1, 10, 8, 6, -2, 9, 0};
        int k = 3;
        QuickSortWithTopK.quickSortWithTopK(array, k);
        Arrays.stream(array).forEach((i)->System.out.print(i + "\t"));
    }
}
