import java.util.*;
import java.io.*;
import java.lang.Math;

public class Repetitions{
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

        String str = fs.next();
        long ans = 1;
        int flag = 0;
        long tempLen = 1;

        for(int i=1; i<str.length(); i++){
            if(str.charAt(i)==str.charAt(i-1)){
                tempLen++;
                ans = Math.max(tempLen, ans);
            }
            else{
                tempLen=1;
            }
        }
        out.println(ans);
        out.close();
    }
}