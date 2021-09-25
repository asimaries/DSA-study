import java.io.*; import java.util.*; import static java.lang.Math.*; import static java.util.Arrays.*; import static java.util.Collections.*;
 
public class abc {
    static final FastReader fs = new FastReader();
    static final PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args) {
        int T = fs.getInt();
        for (int tt = 0; tt < T; tt++) {
            test_case();
        }
        out.close();
    }
 
    static void test_case() {
        int n = fs.getInt(), m = fs.getInt(), k = fs.getInt();
        int d_jkr = min(n / k, m);
        m -= d_jkr;
        int r_jkr = (int) ceil((double)m / (double)(k - 1));
        out.println(d_jkr - r_jkr);
    }
 
    static class FastReader {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); StringTokenizer st = new StringTokenizer("");
        String get() { while (!st.hasMoreTokens() || st == null) {try { st = new StringTokenizer(br.readLine()); }  catch (IOException e) { e.printStackTrace(); } } return st.nextToken();}
        int getInt() { return Integer.parseInt(get()); }
    }
}