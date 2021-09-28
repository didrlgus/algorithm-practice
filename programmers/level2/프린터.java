import java.util.ArrayDeque;
import java.util.*;

class Data {
    
    int idx;
    int priority;
    
    public Data(int idx, int priority) {
        this.idx = idx;
        this.priority = priority;
    }
}

class Solution {
    
    ArrayDeque<Data> queue = new ArrayDeque<>();
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        int N = priorities.length;
        
        for (int i = 0; i < N; i++) {
            queue.addLast(new Data(i, priorities[i]));
        }
        
        while(!queue.isEmpty()) {
            Data f_data = queue.pollFirst();
            ArrayDeque<Data> tmp_queue = new ArrayDeque<>();
            boolean flag = false;
            while(!queue.isEmpty()) {
                Data s_data = queue.pollFirst();
                if (f_data.priority < s_data.priority) {
                    flag = true;
                }
                tmp_queue.addLast(s_data);
            }
            while(!tmp_queue.isEmpty()) {
                queue.addLast(tmp_queue.pollFirst());
            }
            if (!flag) {
                answer += 1;
                if (f_data.idx == location) {
                    break;
                }
            } else { 
                queue.addLast(f_data);
            }
        }
        
        return answer;
    }
}