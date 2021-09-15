import java.util.*;
import java.util.stream.Collectors;

class Data {

    int play;
    int uniqueNumber;

    public Data(int play, int uniqueNumber) {
        this.play = play;
        this.uniqueNumber = uniqueNumber;
    }

}

class Solution {
    
    Map<String, Integer> map1 = new HashMap<>();
    Map<String, List<Data>> map2 = new HashMap<>();

    public int[] solution(String[] genres, int[] plays) {
        int[] answer;

        List<Integer> ret = new ArrayList<>();

        int N = genres.length;

        for (int i = 0; i < N; i++) {
            String genre = genres[i];
            int play = plays[i];

            if (!map1.containsKey(genre)) {
                map1.put(genre, play);
            } else {
                map1.put(genre, map1.get(genre) + play);
            }

            List<Data> list;
            if (!map2.containsKey(genre)) {
                list = new ArrayList<>();
            } else {
                list = map2.get(genre);
            }
            list.add(new Data(play , i));
            map2.put(genre, list);
        }

        List<Map.Entry<String, Integer>> collect
                = map1.entrySet().stream().sorted((o1, o2) -> o2.getValue().compareTo(o1.getValue())).collect(Collectors.toList());

        for (Map.Entry<String, Integer> entry : collect) {
            String key = entry.getKey();

            List<Data> dataList = map2.get(key);

            List<Data> sortedList = dataList.stream().sorted((o1, o2) -> {
                if (o1.play == o2.play) {
                    return o1.uniqueNumber - o2.uniqueNumber;
                }
                return o2.play - o1.play;
            }).collect(Collectors.toList());

            ret.add(sortedList.get(0).uniqueNumber);
            if (sortedList.size() >= 2) {
                ret.add(sortedList.get(1).uniqueNumber);
            }
        }

        answer = new int[ret.size()];

        for (int i = 0 ; i < ret.size(); i++) {
            answer[i] = ret.get(i);
        }

        return answer;
    }
}