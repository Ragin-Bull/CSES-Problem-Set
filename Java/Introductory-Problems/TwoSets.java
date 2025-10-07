import java.util.*;
import java.io.*;
import java.lang.*;

public class TwoSets{
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args){
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = fs.nextInt();
        if(n%2 == 0){
            if(n%4 == 0){
                out.println("YES");
                out.println(n/2);
                // First n/4 numbers
                for(int i=1; i<=n/4; i++)
                    out.print(i + " ");

                // Last n/4 numbers
                for(int i=1; i<=n/4; i++)
                    out.print(n-i+1 + " ");

                out.print("\n");
                out.println(n/2);

                // Middle n/2 numbers
                for(int i=(n/4)+1; i<=(n-n/4); i++)
                    out.print(i + " ");

                out.print("\n");
            }
            else{
                out.println("NO");
            }
        }
        else{
            if (n%4 == 1)
                out.println("NO");
            else{
                out.println("YES");
                int lFirst = (n+3)/4;
                int lLast = n/4;

                int lCount = lFirst + lLast;
                out.println(lCount+1);

                long totalSum = ((long)n*((long)(n+1)))/2;
                long lSum = 0;
                long rSum = 0;

                // Print the first lFirst numbers
                for(int i=1; i<=lFirst; i++){
                    out.print(i + " ");
                    lSum+=i;
                }

                // Print the last lLast numbers
                for(int i=1; i<=lLast; i++){
                    out.print(n-i+1 + " ");
                    lSum+=(n-i+1);
                }
                
                rSum = totalSum - lSum;
                long specialNum = (rSum - lSum)/2;

                out.print(specialNum + "\n");

                out.println(n - lCount - 1);

                for(int i=lFirst+1; i<=n-lLast; i++){
                    if (i!=specialNum)
                        out.print(i + " ");
                }

                // out.println("The Total Sum of the left and right is: " + (lSum + specialNum) + " and " + (rSum - specialNum));

                out.print("\n");
            }
        }
        out.close();
    }
}