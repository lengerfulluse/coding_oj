import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

/**
 * https://leetcode.com/problems/palindrome-partitioning/.
 */
public class Palindrome_Partitioning {
    public static List<List<String>> partition(String s) {
        return null;
    }

    public static void main(String[] args) {
        String s = "aab";
        ArrayList
        List<List<String>> result = Palindrome_Partitioning.partition(s);
        ListIterator<List<String>> listIterator = result.listIterator();
        while(listIterator.hasNext()) {
            List<String> combination = listIterator.next();
            Iterator<String> iterator = combination.iterator();
            while(iterator.hasNext()) {
                System.out.print(iterator.next() + " ");
            }
            System.out.println("");
        }
    }
}
