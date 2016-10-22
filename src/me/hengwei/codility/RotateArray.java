import javafx.scene.transform.Rotate;

/**
 * Created by weiheng on 10/8/16.
 */
public class RotateArray {
    public static int[] solution(int[] A, int K) {
        int[] B = new int[A.length];
        for(int i=0; i< A.length ; i++) {
            if(i < K-1) {
                B[i+K] = A[i];
            } else {
                B[i - (K-1)] = A[i];
            }
        }
        return B;
    }
    public static void main(String[] args) {
        int[] a = new int[] {3, 8, 9, 7, 6 };
        RotateArray.solution(a, 3);
    }
}