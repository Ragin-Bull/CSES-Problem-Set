import java.util.*;
import java.io.*;
import java.lang.*;

public class NumberSpiral{
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

        int t = fs.nextInt();
        while(t-- > 0){
            long x, y;
            x = fs.nextLong();
            y = fs.nextLong();
            long maxima = Math.max(x, y); 
            long minima = Math.min(x, y);
            long diag = maxima*maxima - maxima + 1;

            if ((maxima&1) == 1){
                out.println(diag - x + y);
            }
            else{
                out.println(diag - y + x);
            }
        }
        out.close();
    }
}