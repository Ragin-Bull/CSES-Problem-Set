import java.util.*;
import java.io.*;
import java.lang.*;

public class CoinPiles{
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

    public static void main(String[] args){
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        long t = fs.nextLong();
        while(t-- > 0){
            long a = fs.nextLong();
            long b = fs.nextLong();

            if(a==0 && b==0){
                out.println("YES");
            }
            else if(a==0 || b==0){
                out.println("NO");
            }
            else{
                if(2*a-b >=0 && 2*b-a >=0 && (2*a-b)%3==0 && (2*b-a)%3 == 0)
                    out.println("YES");
                else
                    out.println("NO");
            }
        }
        out.close();
    }
}