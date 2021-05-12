import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeMap;

public class Q501 {
    TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();

    void dfs(TreeNode root) {
        if (root == null)
            return;

        int cnt = map.containsKey(root.val) ? map.get(root.val) + 1 : 1;
        map.put(root.val, cnt);

        dfs(root.left);
        dfs(root.right);
    }

    public int[] findMode(TreeNode root) {
        // First do the dfs
        dfs(root);

        int max = map.values().stream().max(Integer::compare).get();
        System.out.println(max);

        ArrayList<Integer> lst = new ArrayList<>();

        map.forEach((key, val) -> {
            if (val == max)
                lst.add(key);
        });

        int ans[] = new int[lst.size()];

        for (int i = 0; i < lst.size(); i++) {
            ans[i] = lst.get(i);
        }

        return ans;
    }

    public static void main(String args[]) {

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        Q501 obj = new Q501();

        obj.findMode(new TreeNode(4, new TreeNode(3), null));
    }
}
