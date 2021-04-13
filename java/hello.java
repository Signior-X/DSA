import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.ArrayList;

class hello {
    static BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

    static class Read {
        BufferedReader br;
        StringTokenizer st;

        public Read() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        int intNext() {
            return Integer.parseInt(next());
        }

        long longNext() {
            return Long.parseLong(next());
        }

        double doubleNext() {
            return Double.parseDouble(next());
        }

        String lineNext() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void printArr(int[] arr) throws IOException {
        for (int i = 0; i < arr.length - 1; i++) {
            output.write(arr[i] + " ");
        }
        output.write(arr[arr.length - 1] + "\n");
        output.flush();
    }

    public static int[] inpArr(int n) {
        int ar[] = new int[n];
        Read read = new Read();
        for (int i = 0; i < n; i++) {
            ar[i] = read.intNext();
        }
        return ar;
    }

    public static void main(String args[]) throws IOException {
        // Start you code from here
        // Create a basic array
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        Read read = new Read();
        int t = read.intNext();

        // General variable declarations
        int n;
        while (t-- > 0) {
            n = read.intNext();
            int ar[] = inpArr(n);

            // now let's find the sorted inp
            Arrays.sort(ar);

            HashMap<Integer, Integer> map = new HashMap();
            map.put(2, ar[0]);
            map.put(1, ar[1]);

            // printArr(ar);
        }
    }
}