import java.util.*;
import java.io.*;

public class MissingNumber{
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

        long n = fs.nextLong();
        long actualSum = (n*(n+1))/2;
        long givenSum = 0;

        for(int i=0; i<n-1; i++){
            long value = fs.nextLong();
            givenSum+=value;
        }
        long ans = actualSum - givenSum;

        out.println(ans);
        out.close();
    }
}