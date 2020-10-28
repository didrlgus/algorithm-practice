// 컬러볼
import java.io.*;
import java.util.*;

class Ball {
    int id;
    int color;
    int size;

    public Ball(int id, int color, int size) {
        this.id = id;
        this.color = color;
        this.size = size;
    }
}

public class Main {

    private static int p_sum=0;
    private static int[] color_sum=new int[200005];
    private static List<Ball> ballList=new ArrayList<>();
    private static int[] ret=new int[200005];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st=new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i = 0; i< n; i++) {
            st = new StringTokenizer(br.readLine());
            int color = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());
            ballList.add(new Ball(i, color, size));
        }
        ballList.sort((Comparator.comparingInt(o -> o.size)));
        int idx=0;
        for(int i = 0; i< n; i++) {
            Ball a = ballList.get(i);
            Ball b = ballList.get(idx);
            while (b.size < a.size) {
                p_sum += b.size;
                color_sum[b.color] += b.size;
                b = ballList.get(++idx);
            }
            ret[a.id] = p_sum - color_sum[a.color];
        }
        for(int i = 0; i< n; i++) {
            sb.append(ret[i]).append("\n");
        }
        System.out.print(sb.toString());
    }
}
