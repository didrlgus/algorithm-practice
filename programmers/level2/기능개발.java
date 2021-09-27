import java.util.*;

class Solution {
    
    ArrayDeque<Integer> queue = new ArrayDeque<>();
    List<Integer> ret = new ArrayList<>();
    
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int N = progresses.length;
        
        for(int i = 0; i < N; i++) {
            int remainingProgress = 100 - progresses[i];
            int mod = remainingProgress / speeds[i];
            if ((remainingProgress % speeds[i]) > 0) {
                mod += 1;
            }
            queue.addLast(mod);
        }
        
        while(!queue.isEmpty()) {
            int num = queue.pollFirst();
            int cnt = 1;
            while(!queue.isEmpty() && (num >= queue.peekFirst())) {
                cnt += 1;
                num = Math.max(num, queue.pollFirst());
            }
            ret.add(cnt);
        }
        
        int M = ret.size();
        answer = new int[M];
        
        for (int i = 0; i < M; i++) {
            answer[i] = ret.get(i);
        }
        
        return answer;
    }
}