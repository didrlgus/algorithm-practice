import java.util.*;

class Data {
    
    int idx;
    int value;
    
    public Data(int idx, int value) {
        this.idx = idx;
        this.value = value;
    }
}

class Solution {
    ArrayDeque<Data> stack = new ArrayDeque<>();
    
    public int[] solution(int[] prices) {
        int N = prices.length;
        
        int[] answer = new int[N];
        
        for (int i = 0; i < N; i++) {
            int curPrice = prices[i];
            
            while (!stack.isEmpty() && stack.getLast().value > curPrice) {
                Data pollData = stack.pollLast();
                answer[pollData.idx] = i - pollData.idx;
            }
            
            stack.addLast(new Data(i, curPrice));
        }
        
        while(!stack.isEmpty()) {
            Data pollData = stack.pollLast();
            answer[pollData.idx] = N - 1 - pollData.idx;
        }
        
        return answer;
    }
}