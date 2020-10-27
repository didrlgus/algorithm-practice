// 후보 추천하기
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Student {
    int num;
    int recommend;
    int time;

    public Student(int num, int recommend, int time) {
        this.num = num;
        this.recommend = recommend;
        this.time = time;
    }
}

public class Main {

    private static List<Student> frame=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        st=new StringTokenizer(br.readLine());
        int k=Integer.parseInt(st.nextToken());
        st=new StringTokenizer(br.readLine());
        for(int i=0;i<k;i++) {
            int num=Integer.parseInt(st.nextToken());
            boolean flag=false;
            if(frame.size()<n) {
                for(Student student:frame) {
                    if(num==student.num) {
                        student.recommend++;
                        flag=true;
                    }
                    student.time++;
                }
                if(!flag) {
                    frame.add(new Student(num,1,1));
                }
            } else {
                for(Student student:frame) {
                    if(num==student.num) {
                        student.recommend++;
                        flag=true;
                    }
                    student.time++;
                }
                if(!flag) {
                    frame.sort((o1, o2) -> {
                        if (o1.recommend == o2.recommend) return o2.time - o1.time;
                        else return o1.recommend - o2.recommend;
                    });
                    frame.remove(0);
                    frame.add(new Student(num,1,1));
                }
            }
        }
        List<Integer> ret=new ArrayList<>();
        for(Student student:frame) {
            ret.add(student.num);
        }
        Collections.sort(ret);
        for(Integer it:ret) System.out.print(it + " ");
        System.out.println();
    }
}
