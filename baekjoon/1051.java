// 숫자 정사각형
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static int n;
    public static int m;
    public static char[][] arr;
    public static int ret=-987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] str_arr=str.split(" ");
        n = Integer.parseInt(str_arr[0]);
        m = Integer.parseInt(str_arr[1]);
        arr=new char[n+1][m+1];
        for(int i=0;i<n;i++) {
            str = br.readLine();
            arr[i]=str.toCharArray();
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int size=1;
                char val=arr[i][j];
                while (i + size < n && j + size < m) {
                    if (arr[i + size][j] == val && arr[i][j + size] == val && arr[i + size][j + size] == val) {
                        ret = Math.max(ret, size);
                    }
                    size++;
                }
            }
        }
        if(ret==-987654321) System.out.println(1);
        else System.out.println((ret+1)*(ret+1));
    }
}