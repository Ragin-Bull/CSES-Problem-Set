import java.util.*;
import java.io.*;
import java.lang.Math;

public class IncreasingArray{
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
        long ans = 0;
        int prev = fs.nextInt();

        for(int i=1; i<n; i++){
            int x = fs.nextInt();
            if (x >= prev){
                prev = x;
                continue;
            }
            
            ans += (prev-x);
        }

        out.println(ans);
        out.close();
    }
}