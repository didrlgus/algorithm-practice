import java.util.*;

class Solution {
    Map<String, Integer> map = new HashMap<>();
    
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        for (int i = 0; i < completion.length; i++) {
            String key = completion[i];
            if (!map.containsKey(key)) {
                map.put(key, 1);
            } else {
                map.put(key, map.get(key) + 1);
            }
        }
        
        for (int i = 0; i < participant.length; i++) {
            String key = participant[i];
            if (map.containsKey(key)) {
                if (map.get(key) <= 0) {
                    answer = key;
                    break;
                }
                map.put(key, map.get(key) - 1);
            } else {
                answer = key;
                break;
            }
        }
        
        return answer;
    }
}