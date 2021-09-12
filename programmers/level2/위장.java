import java.util.*;

class Solution {
    
    Map<String, Integer> map = new HashMap<>();
    
    public int solution(String[][] clothes) {
        int answer = 1;
        
        int N = clothes.length;
        
        for (int i = 0; i < N; i++) {
            String type = clothes[i][1];
            
            if (!map.containsKey(type)) {
                map.put(type, 1);
            } else {
                map.put(type, map.get(type) + 1);
            }
        }
        
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            answer *= (entry.getValue() + 1);
        }
        
        return answer - 1;
    }
}