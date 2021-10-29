import java.util.*;

class Solution {
    
    private static final int LEN = 6;
    
    boolean[] check = new boolean[46];
    List<Integer> candidateNums = new ArrayList<>();
    List<Integer> confirmNums = new ArrayList<>();
    int zeroCnt = 0;
    int mx = -1;
    int mn = 7;
    
    public void combi(int here, List<Integer> list, int[] win_nums) {
        if (list.size() == zeroCnt) {
            
            int cnt = 0;
            
            for (int i = 0; i < confirmNums.size(); i++) {
                for (int j = 0; j < LEN; j++) {
                    if (confirmNums.get(i) == win_nums[j]) {
                        cnt++;    
                    }
                }
            }
            
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < LEN; j++) {
                    if (list.get(i) == win_nums[j]) {
                        cnt++;
                    }
                }
            }
            
            mx = Math.max(mx, cnt);
            mn = Math.min(mn, cnt);
            
            return;
        }
        for (int i = here + 1; i < candidateNums.size(); i++) {
            list.add(candidateNums.get(i));
            combi(i, list, win_nums);
            list.remove(list.size() - 1);
        }
    }
    
    
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {};
        
        Map<Integer, Integer> orderMap = new HashMap<>();
        orderMap.put(6, 1);
        orderMap.put(5, 2);
        orderMap.put(4, 3);
        orderMap.put(3, 4);
        orderMap.put(2, 5);
        
        for (int i = 0; i < LEN; i++) {
            int lotto = lottos[i];
            check[lotto] = true;
            if (lotto == 0) {
                zeroCnt += 1;
            }
        }
        
        for (int i = 1; i <= 45; i++) {
            if (!check[i]) {
                candidateNums.add(i);
            } else {
                confirmNums.add(i);
            }
        }
        
        combi(-1, new ArrayList<>(), win_nums);
        
        int maxOrder = orderMap.containsKey(mx) ? orderMap.get(mx) : 6;
        int minOrder = orderMap.containsKey(mn) ? orderMap.get(mn) : 6;
        
        answer = new int[]{maxOrder, minOrder};
        
        return answer;
    }
}