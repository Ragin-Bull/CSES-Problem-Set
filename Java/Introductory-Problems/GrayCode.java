import java.util.*;
import java.io.*;
import java.lang.*;

public class GrayCode{
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

    public static ArrayList<StringBuilder> grayCode(int n){
        if(n==1){
            StringBuilder one = new StringBuilder();
            StringBuilder zero = new StringBuilder();

            one.append("0");
            zero.append("1");

            ArrayList<StringBuilder> list = new ArrayList<>();
            list.add(one);
            list.add(zero);

            return list;
        }

        ArrayList<StringBuilder> listOne = grayCode(n-1);
        ArrayList<StringBuilder> listZero = grayCode(n-1);
        ArrayList<StringBuilder> blankList = new ArrayList<>();

        for(int i=0; i<listOne.size(); i++){
            // Use the constructor if you want to avoid value being pointed to the same location
            StringBuilder valueZero = new StringBuilder(listOne.get(i).toString());
            valueZero.append("0");

            // System.out.println(valueOne + " and " + valueZero);
            blankList.add(valueZero);
        }

        for(int i=0; i<listZero.size(); i++){
            // Use the constructor if you want to avoid value being pointed to the same location
            StringBuilder valueOne = new StringBuilder(listZero.get(i).toString());
            valueOne.append("1");

            // System.out.println(valueOne + " and " + valueZero);
            blankList.add(valueOne);
        }

        return blankList;
    }

    public static void main(String[] args){
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = fs.nextInt();
        ArrayList<StringBuilder>output = grayCode(n);

        for(int i=0; i<output.size(); i++){
            String ans = (output.get(i)).toString();
            out.println(ans);
        }

        out.close();
    }
}