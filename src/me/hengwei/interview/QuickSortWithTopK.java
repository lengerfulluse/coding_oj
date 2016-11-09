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

        if (end - pivot + 1 == k) {
            System.out.println("got with exactly K size");
            for(int i = pivot; i<= end; i++) {
                System.out.print(array[i] + "\t");
            }
            System.out.println();
        } else if (end - pivot + 1 > k) {
            System.out.println("got with larger than k size");
            quickSort(array, pivot+ 1, end, k);
        } else {
            System.out.println("got with small than k size");
            /* we already know the biggest ones */
            for(int i = pivot; i<= end; i++) {
                System.out.print(array[i] + "\t");
            }
            System.out.println();
            quickSort(array, start, pivot-1, k - (end - pivot + 1));
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

        int[] array = new int[] {-1, 10, 8, 23, 11, 6, -2, 9, 0};
        Arrays.stream(array).forEach(i->System.out.print(i + "\t"));
        System.out.println();
        int k = 3;
        QuickSortWithTopK.quickSortWithTopK(array, k);
    }
}
