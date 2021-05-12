class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Q98 {

    public boolean isValidBST(TreeNode root, long minV, long maxV) {
        if (root == null)
            return true;

        boolean leftValid = true, rightValid = true, isRight = false;

        if (root.val < maxV && root.val > minV)
            isRight = true;

        leftValid = isValidBST(root.left, minV, root.val);
        rightValid = isValidBST(root.right, root.val, maxV);

        return leftValid && rightValid && isRight;
    }

    public static void main(String args[]) {

        Q98 obj = new Q98();

        // TreeNode root = new TreeNode(5, new TreeNode(1, null, null), new TreeNode(6,
        // new TreeNode(3), new TreeNode(7)));

        TreeNode root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
        System.out.println(obj.isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE));
    }

}