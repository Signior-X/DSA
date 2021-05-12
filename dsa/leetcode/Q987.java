import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.Arrays;

public class Q987 {

    public static void main(String args[]) {
        // We practice priority queue

        PriorityQueue<ArrayList<Integer>> pq = new PriorityQueue<>((arr1, arr2) -> {
            // Priority to 0th index and then 1st index and rest all equal
            if (arr1.get(0) < arr2.get(0)) {
                return -1;
            } else if (arr1.get(0) > arr2.get(0)) {
                return 1;
            } else {
                if (arr1.get(1) < arr2.get(1)) {
                    return -1;
                } else if (arr1.get(1) > arr2.get(1)) {
                    return 1;
                }

                return 0;
            }
        });

        pq.add(new ArrayList<>(Arrays.asList(1, 2)));
        pq.add(new ArrayList<>(Arrays.asList(6, 4)));
        pq.add(new ArrayList<>(Arrays.asList(6, 3)));
        pq.add(new ArrayList<>(Arrays.asList(3, 4)));
        pq.add(new ArrayList<>(Arrays.asList(4, 4)));

    }
}