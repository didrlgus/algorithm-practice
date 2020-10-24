import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int tc=Integer.parseInt(st.nextToken());
        while(tc-->0) {
            st=new StringTokenizer(br.readLine());
            int l=Integer.parseInt(st.nextToken());
            int n=Integer.parseInt(st.nextToken());
            int mn=0,mx=0;
            for(int i=0;i<n;i++) {
                st=new StringTokenizer(br.readLine());
                int ant=Integer.parseInt(st.nextToken());
                int antMin = min(ant,l-ant);
                int antMax = max(ant,l-ant);
                mn = max(mn, antMin);
                mx = max(mx, antMax);
            }
            System.out.println(mn+" "+mx);
        }
    }

}
