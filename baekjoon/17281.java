// 야구공
import java.io.*;
import java.util.*;

import static java.lang.Math.max;

public class Main {

    public static int n;
    public static int[][] arr=new int[55][10];
    public static List<Integer> permu_list=new ArrayList<>();
    public static boolean[] check=new boolean[10];
    public static boolean[] base=new boolean[5];
    public static int ret=0;

    public static void permu() {
        if(permu_list.size()==8) {
            List<Integer> list = new ArrayList<>();
            for(Integer it:permu_list) {
                if(list.size()==3) {
                    list.add(1);
                }
                list.add(it);
            }
            int sum=0,z_cnt=0;
            int inning=0,num=0;
            while(inning<n) {
                int now_score=arr[inning][list.get(num)-1];
                if(now_score==0) {
                    z_cnt++;
                    if(z_cnt>=3) {
                        inning++;
                        z_cnt=0;
                        for(int i=1;i<=3;i++) {
                            if(base[i]) base[i]=false;
                        }
                    }
                } else {
                    if(now_score==1) {
                        if(base[3]) {
                            base[3]=false;
                            sum++;
                        }
                        for(int i=2;i>=1;i--) {
                            if(base[i]) {
                                base[i]=false;
                                base[i+1]=true;
                            }
                        }
                        base[1]=true;
                    } else if(now_score==2) {
                        for(int i=3;i>=2;i--) {
                            if(base[i]) {
                                base[i]=false;
                                sum++;
                            }
                        }
                        if(base[1]) {
                            base[1]=false;
                            base[3]=true;
                        }
                        base[2]=true;
                    } else if(now_score==3) {
                        for(int i=3;i>=1;i--) {
                            if(base[i]) {
                                base[i]=false;
                                sum++;
                            }
                        }
                        base[3]=true;
                    } else {
                        for(int i=3;i>=1;i--) {
                            if(base[i]) {
                                base[i]=false;
                                sum++;
                            }
                        }
                        sum++;
                    }
                }
                num++;
                if(num>=9) num=0;
            }
            ret=max(ret,sum);
            return;
        }
        for(int i=1;i<=9;i++) {
            if(i==1) continue;
            if(check[i]) continue;
            check[i]=true;
            permu_list.add(i);
            permu();
            permu_list.remove(permu_list.size()-1);
            check[i]=false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<9;j++) {
                arr[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        permu();
        System.out.println(ret);
    }
}