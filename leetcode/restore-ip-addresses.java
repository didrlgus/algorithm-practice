class Solution {
        public String getNumberStr(String s, int start, int end) {
        return s.substring(start, end);
    }

    public boolean isValid(String s) {
        if (s.length() <= 1) {
            return true;
        }
        if (s.startsWith("0")) {
            return false;
        }
        return Integer.parseInt(s) <= 255;
    }

    public List<String> restoreIpAddresses(String s) {

        List<String> ret = new ArrayList<>();
        int N = s.length();

        if (N < 4 || N > 12) {
            return ret;
        }

        for (int a=1;a<4;a++) {
            for (int b=1;b<4;b++) {
                for (int c=1;c<4;c++) {
                    for(int d=1;d<4;d++) {
                        int sum = a + b + c + d;

                        if (sum != N) {
                            continue;
                        }

                        StringBuilder ipAddr = new StringBuilder();

                        String aa = getNumberStr(s, 0, a);
                        String bb = getNumberStr(s, a, a+b);
                        String cc = getNumberStr(s, a+b, a+b+c);
                        String dd = getNumberStr(s, a+b+c, a+b+c+d);

                        if (!isValid(aa) || !isValid(bb) || !isValid(cc) || !isValid(dd)) {
                            continue;
                        }

                        ipAddr.append(aa).append(".").append(bb).append(".").append(cc).append(".").append(dd);

                        ret.add(ipAddr.toString());
                    }
                }
            }
        }

        return ret;
    }
}