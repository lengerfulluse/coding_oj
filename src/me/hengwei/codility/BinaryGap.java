/**
 * Created by weiheng on 10/8/16.
 */
public class BinaryGap {
    public static int solution(int N) {
        int shift = N >> 1;
        int interval = 0;
        int maxInterval = 0;
        boolean entryOne = false;
        while(N > 0) {
            int binary = N - shift * 2;
            if(binary == 1) {
                entryOne = true;
                maxInterval = maxInterval > interval ? maxInterval : interval;
                interval = 0;
            } else if((binary == 0) && (entryOne == true)) {
                interval++;
            }
            N = shift;
            shift = N >> 1;
        }
        return maxInterval;
    }

    public static void main(String[] args) {
        System.out.println(BinaryGap.solution(1041));

    }
}
