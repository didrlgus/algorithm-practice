import java.util.*;

class Person {

    int num;
    Integer cnt;

    public Person(int num, Integer cnt) {
        this.num = num;
        this.cnt = cnt;
    }
}

class Solution {

    private int[] person1 = {1, 2, 3, 4, 5};
    private int[] person2 = {2, 1, 2, 3, 2, 4, 2, 5};
    private int[] person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    public int getLength(int[] person) {
        return person.length;
    }
    
    public int[] solution(int[] answers) {
        int[] answer = {};

        int person1_len = getLength(person1);
        int person2_len = getLength(person2);
        int person3_len = getLength(person3);

        int N = getLength(answers);

        int person1_cnt = 0, person2_cnt = 0, person3_cnt = 0;
        int a = 0, b = 0, c = 0;

        for (int i = 0; i < N; i++) {
            if (a >= person1_len) {
                a = 0;
            }
            if (b >= person2_len) {
                b = 0;
            }
            if (c >= person3_len) {
                c = 0;
            }
            if (person1[a++] == answers[i]) {
                person1_cnt += 1;
            }
            if (person2[b++] == answers[i]) {
                person2_cnt += 1;
            }
            if (person3[c++] == answers[i]) {
                person3_cnt += 1;
            }
        }

        List<Person> persons = new ArrayList<>();
        persons.add(new Person(1, person1_cnt));
        persons.add(new Person(2, person2_cnt));
        persons.add(new Person(3, person3_cnt));

        persons.sort((o1, o2) -> o2.cnt.compareTo(o1.cnt));
        
        int mx = persons.get(0).cnt;
        
        List<Integer> tmp = new ArrayList<>();
        
        for (int i = 0; i < 3; i++) {
            Person person = persons.get(i);

            if (person.cnt < mx) {
                break;
            }

            tmp.add(person.num);
        }

        int M = tmp.size();
        answer = new int[M];
        
        for (int i = 0; i < M; i++) {
            answer[i] = tmp.get(i);
        }
        
        return answer;
    }
}