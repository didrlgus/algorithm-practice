// 괄호의 값
import java.util.Scanner;
import java.util.Stack;

public class Main {

    private static Stack<String> stk = new Stack<>();
    private static boolean flag=false;
    private static int ret=0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str=sc.nextLine();
        for(int i=0;i<str.length();i++) {
            if(str.charAt(i)=='(') {
                stk.push("(");
            } else if(str.charAt(i)=='[') {
                stk.push("[");
            } else if(str.charAt(i)==')') {
                if(stk.empty()) {
                    flag=true;
                    break;
                }
                int val=0;
                while(!stk.empty()) {
                    String top=stk.peek();
                    if(top.equals(")")||top.equals("]")||top.equals("[")) {
                        flag=true;
                        break;
                    }
                    if(top.equals("(")) break;
                    val+=Integer.parseInt(stk.pop());
                }
                if(flag) break;
                if(!stk.empty()&&stk.peek().equals("(")) {
                    stk.pop();
                } else {
                    flag=true;
                    break;
                }
                if(val==0) stk.push("2");
                else stk.push(String.valueOf(val*2));
            } else {
                if(stk.empty()) {
                    flag=true;
                    break;
                }
                int val=0;
                while(!stk.empty()) {
                    String top=stk.peek();
                    if(top.equals(")")||top.equals("]")||top.equals("(")) {
                        flag=true;
                        break;
                    }
                    if(top.equals("[")) break;
                    val+=Integer.parseInt(stk.pop());
                }
                if(flag) break;
                if(!stk.empty()&&stk.peek().equals("[")) {
                    stk.pop();
                } else {
                    flag=true;
                    break;
                }
                if(val==0) stk.push("3");
                else stk.push(String.valueOf(val*3));
            }
        }
        if(flag) System.out.println(0);
        else {
            try {
                while (!stk.empty()) {
                    ret += Integer.parseInt(stk.pop());
                }
                System.out.println(ret);
            } catch (Exception e) {
                System.out.println(0);
            }
        }
    }
}