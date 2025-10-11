import java.util.*;
import java.io.*;
import java.lang.*;

public class TowerOfHanoi{
    static class FastScanner {
        /*
            Faster input and output reader and printer methods
        */
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

    public static long binaryExponentiation(long a, long b, long mod){
        /*
        * Method for calculating a^b modulo mod
        */

        long ans = 1L;
        while(b>0){
            if(b%2 == 1){
                ans = (ans * a)%mod;
                if (ans < 0)
                    ans+=mod;
            }
            a = (a*a)%mod;
            b=b/2;
        }
        return ans;
    }

    public static void towerOfHanoi(int diskNumber, int initial, int helper, int dest, PrintWriter out){
        if (diskNumber == 1){
            out.println(initial + " " + dest);
            // out.close();
            return ;
        }

        towerOfHanoi(diskNumber-1, initial, dest, helper, out);
        out.println(initial + " " +dest);
        towerOfHanoi(diskNumber-1, helper, initial, dest, out);
    }

    public static void main(String[] args){
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = fs.nextInt();
        out.println(binaryExponentiation(2L, (long)n, (long)1e9+7)-1L);
        towerOfHanoi(n, 1, 2, 3, out);
        out.close();
    }
}