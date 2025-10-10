import java.util.*;
import java.io.*;
import java.lang.*;

public class PalindromeReorder{
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

        String s = fs.next();
        int len = s.length();
        int flag = 0; // How many odd frequency distinct letters are there
        
        TreeMap<Character,Integer> mp = new TreeMap<>();
        ArrayList<Character> palindromeRecreated = new ArrayList<>();

        for(int i=0; i<len; i++){
            if(mp.containsKey(s.charAt(i))){
                mp.put(s.charAt(i), mp.get(s.charAt(i))+1);
            }
            else{
                mp.put(s.charAt(i), 1);
            }
        }
        
        char specialCharacter = '\0';
        int freqOfSpecialCharacter = 0;

        // for(Map.Entry<Character, Integer> en : mp.entrySet()){
        //     out.println(en.getKey() + " : " + en.getValue());
        // }

        for(Map.Entry<Character,Integer> en : mp.entrySet()){
            if((en.getValue() % 2) != 0){
                specialCharacter = en.getKey();
                freqOfSpecialCharacter = en.getValue();
                flag++;
            }
        }

        if(flag > 1){
            out.println("NO SOLUTION");
            out.close();
            return;
        }

        mp.put(specialCharacter, freqOfSpecialCharacter-1);

        for(Map.Entry<Character, Integer> en : mp.entrySet()){
            int count = en.getValue();
            count/=2;
            while(count-- > 0){
                palindromeRecreated.add(en.getKey());
            }
        }

        for(int i=0; i < palindromeRecreated.size(); i++){
            out.print(palindromeRecreated.get(i));
        }

        if(flag != 0)
            out.print(specialCharacter);

        for(int i = palindromeRecreated.size() - 1; i>=0; i--){
            out.print(palindromeRecreated.get(i));
        }            
        out.println();
        out.close();
    }
}