import java.util.HashMap;
import java.util.Map;

/**
 * Created by weiheng on 10/8/16.
 */
public class EvevatorStop {
    public static int solution(int[] A, int[] B, int M, int X, int Y) {
        // write your code in Java SE 8
        int totalStops = 0;
        long totalWeights = 0;
        int totalPeople = 0;
        Map<Integer, Integer> totalFloors = new HashMap<Integer, Integer>();
        int currPerson = 0;
        boolean startLift = false;
        while (currPerson < A.length) {
            //Should current person be considered?
            if ((totalWeights + A[currPerson]) <= Y && (totalPeople+1) <= X) {
                totalWeights += A[currPerson];
                totalPeople++;
                if(totalFloors.containsKey(B[currPerson])) {
                    int count = totalFloors.get(B[currPerson]);
                    totalFloors.put(B[currPerson], count++);
                } else {
                    totalFloors.put(B[currPerson], 1);
                }
                //If curr person is last person then start the lift
                if (currPerson == A.length - 1) {
                    startLift = true;
                }
                currPerson++;
            } else {
                startLift = true;
            }

            if (startLift)
            {
                totalStops += totalFloors.size() + 1;
                //reset variable
                totalFloors.clear();
                totalPeople = 0;
                totalWeights = 0;
                startLift = false;
            }
        }

        return totalStops;
    }

    public static void main(String[] args) {
        int[] A = new int[] {40, 40, 100, 80, 20}; //weight array.
        int[] B = new int[] {3, 3, 2, 2, 3}; // floor array.
        int M = 3; // customer
        int X = 5; // capacity
        int Y = 200; // weight
        System.out.println(EvevatorStop.solution(A, B, M, X, Y ));
    }
}
