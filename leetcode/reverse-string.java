// Reverse String
class Solution {
    public void reverseString(char[] s) {
        char[] tmp = new char[s.length];
        int idx = 0;
        for (int i = s.length-1; i >= 0; i--) {
            tmp[idx++] = s[i];
        }
        for (int i = 0; i < s.length; i++) {
            s[i] = tmp[i];
        }
    }
}