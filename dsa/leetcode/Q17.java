import java.util.ArrayList;
import java.util.List;

public class Q17 {
    String lc[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    List<String> ans = new ArrayList<>();

    void findAllCombinations(String digits, int i, String currstr) {
        if (i == digits.length()) {
            ans.add(currstr);
            return;
        }

        // CURRENTLY i has not reached the end
        String options = lc[(int) digits.charAt(i) - 48];

        for (int it = 0; it < options.length(); it++) {
            findAllCombinations(digits, i + 1, currstr + options.charAt(it));
        }
    }

    public static void main(String args[]) {

        findAllCombinations("23", 0, "");

        ans.forEach(val -> {
            System.out.println(val);
        });

    }
}
