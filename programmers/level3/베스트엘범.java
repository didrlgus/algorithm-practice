import java.util.*;

class Data {
    
    Integer num;
    Integer play;
    
    public Data(Integer num, Integer play) {
        this.num = num;
        this.play = play;
    }
}

class GenrePlays {
    
    String genre;
    Integer play;
    
    public GenrePlays(String genre, Integer play) {
        this.genre = genre;
        this.play = play;
    }
}

class Solution {
    
    private Map<String, Integer> genreMap = new HashMap<>();
    private Map<String, List<Data>> sortedMap = new HashMap<>();
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        
        int N = genres.length;
        
        for (int i = 0; i < N; i++) {
            String genre = genres[i];
            int play = plays[i];
            if (!genreMap.containsKey(genre)) {
                genreMap.put(genre, play);
            } else {
                genreMap.put(genre, genreMap.get(genre) + play);
            }
            if (!sortedMap.containsKey(genre)) {
                List<Data> list = new ArrayList<>();
                list.add(new Data(i, play));
                sortedMap.put(genre, list);
            } else {
                List<Data> tmpList = sortedMap.get(genre);
                tmpList.add(new Data(i, play));
                sortedMap.put(genre, tmpList);
            }
        }
        
        List<GenrePlays> genreRank = new ArrayList<>();
        
        for (Map.Entry<String, Integer> entry : genreMap.entrySet()) {
            genreRank.add(new GenrePlays(entry.getKey(), entry.getValue()));
        }
        
        genreRank.sort((o1, o2) -> o2.play.compareTo(o1.play));
        
        genreRank.forEach(o -> {
            List<Data> tmpList = sortedMap.get(o.genre);
            tmpList.sort((o1, o2) -> o2.play.compareTo(o1.play));
        });
        
        List<Integer> ret = new ArrayList<>();
        
        genreRank.forEach(o -> {
            List<Data> tmpList = sortedMap.get(o.genre);
            
            int M = tmpList.size() < 2 ? tmpList.size() : 2;
            
            for (int i = 0; i < M; i++) {
                ret.add(tmpList.get(i).num);
            }
        });
        
        answer = new int[ret.size()];
        
        for (int i = 0; i < ret.size(); i++) {
            answer[i] = ret.get(i);
        }
        
        return answer;
    }
}