// 한 줄로 서기
import java.util.*;

public class Main {

    public static List<Integer> list = new ArrayList<>();
    public static List<Integer> permu_list = new ArrayList<>();
    public static boolean[] check = new boolean[15];
    public static int n;
    public static boolean toggle=false;

    public static void permu() {
        if(toggle) return;
        if(permu_list.size()==n) {
            boolean flag=false;
            for(int i=0;i<n;i++) {
                int val=permu_list.get(i),cnt=0;
                if(i==0) {
                    if(list.get(val-1)!=cnt) {
                        flag=true;
                        break;
                    }
                }
                for(int j=i-1;j>=0;j--) {
                    if(permu_list.get(j)>val) cnt++;
                }
                if(list.get(val-1)!=cnt) {
                    flag=true;
                    break;
                }
            }
            if(!flag) {
                for (Integer it:permu_list) {
                    System.out.print(it + " ");
                }
                toggle=true;
            }
            return;
        }
        for(int i=1;i<=n;i++) {
            if(check[i]) continue;
            check[i]=true;
            permu_list.add(i);
            permu();
            permu_list.remove(permu_list.size()-1);
            check[i]=false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n=sc.nextInt();
        for(int i=0;i<n;i++) {
            int a=sc.nextInt();
            list.add(a);
        }
        permu();
    }
}
