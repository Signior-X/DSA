import java.util.*;

public class Paths {

    static ArrayList<ArrayList<Integer>> allPaths;
    static int m, n;
    static int ar[][];

    static void findAllPaths(int i, int j, ArrayList<Integer> path) {
        if (i >= m || j >= n)
            return;

        // Adding this route
        path.add(ar[i][j]);

        if (i == m - 1 && j == n - 1) {
            allPaths.add(path);
            return;
        }

        findAllPaths(i + 1, j, new ArrayList<>(path));
        findAllPaths(i, j + 1, new ArrayList<>(path));
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int tests = sc.nextInt();

        while (tests-- > 0) {

            m = sc.nextInt();
            n = sc.nextInt();

            ar = new int[m][n];

            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    ar[i][j] = sc.nextInt();

            // Now do the task we want to do
            // You can move only left or right
            // and return all the paths

            allPaths = new ArrayList<ArrayList<Integer>>();

            findAllPaths(0, 0, new ArrayList<>());

            allPaths.forEach(val -> {
                // val is the array
                for (int v : val) {
                    System.out.print(v + " ");
                }
                System.out.println();
            });

        }

    }
}
