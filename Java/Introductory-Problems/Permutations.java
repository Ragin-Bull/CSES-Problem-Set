import java.util.*;
import java.io.*;
import java.lang.*;

public class Permutations{
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

        if (n==1){
            out.println(1);
        }
        else if (n==2 || n==3){
            out.println("NO SOLUTION");
        }
        else{
            // Print all evens
            for(int i=2; i<=n; i+=2)
                out.print(i + " ");
            
            // Print all odds
            for(int i=1; i<=n; i+=2)
                out.print(i + " ");

            out.print("\n");
        }
        out.close();
    }
}