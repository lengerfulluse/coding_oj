/**
 * Created by weiheng on 10/8/16.
 */
public class EqualThreePair {
    public static int solution(int[] A) {
        // write your code in Java SE 8
        int leftSlice = 0, midSlice = 0, rightSlice = 0;
        int[] totalSumOfSlice = new int[A.length];

        /* calculate the total summary from 0 to i with O(n) */
        totalSumOfSlice[0] = A[0];
        for (int i = 1; i < A.length; i++) {
            totalSumOfSlice[i] += totalSumOfSlice[i-1] + A[i];
        }

        int left = 1, right = A.length - 2;
        while (left + 1 < right) {
            leftSlice = totalSumOfSlice[left-1];
            midSlice = totalSumOfSlice[right-1] - totalSumOfSlice[left];
            rightSlice = totalSumOfSlice[A.length-1] - totalSumOfSlice[right];
            if ((leftSlice == midSlice) && (midSlice == rightSlice)) {
                return 1;
            }
            if (leftSlice > rightSlice) {
                right--;
            } else if (leftSlice < rightSlice){
                left++;
            } else if ((leftSlice == rightSlice) && (leftSlice < midSlice)) {
                left++;
                right--;
            } else {
                return 0;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        int[] A = new int[] {4, 5, 1, 1, 1, 1, 4, 3, 1};
        System.out.println(EqualThreePair.solution(A));
    }
}
