import java.util.*;

class Solution {

    public String processStr(String s) {

        ArrayList<Character> processed = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            if (ch == '*') {

                if (!processed.isEmpty()) {
                    processed.remove(processed.size() - 1);
                }

            } else if (ch == '#') {

                duplicate(processed);

            } else if (ch == '%') {

                reverse(processed);

            } else {

                processed.add(ch);
            }
        }

        StringBuilder ans = new StringBuilder();

        for (char c : processed) {
            ans.append(c);
        }

        return ans.toString();
    }

    public void duplicate(ArrayList<Character> processed) {

        int n = processed.size();

        for (int i = 0; i < n; i++) {
            processed.add(processed.get(i));
        }
    }

    public void reverse(ArrayList<Character> processed) {

        int n = processed.size();

        for (int i = 0; i < n / 2; i++) {

            char temp = processed.get(i);

            processed.set(i, processed.get(n - i - 1));

            processed.set(n - i - 1, temp);
        }
    }
}