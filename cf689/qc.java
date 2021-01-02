import java.util.Scanner;

public class qc {
    public static void main(String args[]){
        // start your code from here
        Scanner sc = new Scanner(System.in);
        int tests = 0;
        tests = sc.nextInt();

        while(tests -- > 0) {

            int l = sc.nextInt();
            int m = sc.nextInt();

            int ar[] = new int[l];
            for (int i=0; i<l; i++) {
                ar[i] = sc.nextInt();
            }
            
            int st = l-1;

            double ms[][] = new double[m][2];

            for (int i = 0; i<m; i++) {
                ms[i][0] = sc.nextInt();
                ms[i][1] = sc.nextDouble();
            }

            // now we will find the sorted point sp
            for (int i = l-1; i>=0; i--) {
                if (ar[i] == i+1)
                    st = i - 1;
                else
                    break;
            }

            // System.out.println(st);

            if (st == -1) {
                System.out.println(1);
            } else {

                double ans = 1;

                // Now we will do the operations
                for (int i=0; i<m; i++) {
                    if (ms[i][0] > st) {
                        // Take probaility 1-p
                        ans *= (1-ms[i][1]);
                    }
                }
                
                System.out.println(1 - ans);

            }

        }

    }
}