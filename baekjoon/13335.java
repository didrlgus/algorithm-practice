// 트럭
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Truck {
    int id;
    int idx;
    int weight;

    public Truck(int id, int idx, int weight) {
        this.id = id;
        this.idx = idx;
        this.weight = weight;
    }
}
public class Main {

    private static boolean[] check=new boolean[1005];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int w=Integer.parseInt(st.nextToken());
        int l=Integer.parseInt(st.nextToken());
        List<Truck> trucks = new ArrayList<>();
        st=new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++) {
            int val=Integer.parseInt(st.nextToken());
            trucks.add(new Truck(i,w+i,val));
        }
        int ret=0,tot_weight=0,cnt=0,enter=0;
        do {
            ret++;
            for (Truck cur_truck : trucks) {
                if (cur_truck.idx == 0) continue;
                if (cur_truck.idx > w + 1) {
                    cur_truck.idx--;
                } else {
                    if (check[cur_truck.id]) {
                        cur_truck.idx--;
                        if (cur_truck.idx == 0) {
                            tot_weight -= cur_truck.weight;
                            check[cur_truck.id] = false;
                            enter--;
                            cnt++;
                        }
                        continue;
                    }
                    if (cur_truck.weight + tot_weight <= l && enter < w) {
                        cur_truck.idx--;
                        if (!check[cur_truck.id]) {
                            tot_weight += cur_truck.weight;
                            check[cur_truck.id] = true;
                            enter++;
                        }
                    } else {
                        break;
                    }
                }
            }
        } while (cnt != n);
        System.out.println(ret);
    }
}