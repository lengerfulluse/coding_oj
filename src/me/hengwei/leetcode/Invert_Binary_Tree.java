package me.hengwei.leetcode;

/**
 * https://leetcode.com/problems/invert-binary-tree/
 * <p>
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */

public class Invert_Binary_Tree {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode invertTree(TreeNode root) {
        if(root == null) {
            return null;
        }
        TreeNode leftChild = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(leftChild);
        return root;
    }

    private boolean isLeafNode(TreeNode node) {
        if(node == null) {
            /* null node is not leaf node by default here */
            return false;
        }

        if(node.left == null && node.right == null) {
            return true;
        } else {
            return false;
        }
    }

    public void traverseTreeInOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        traverseTreeInOrder(root.left);
        System.out.print(root.val + "\t");
        traverseTreeInOrder(root.right);
    }

    public TreeNode createTreeForTest() {
        TreeNode root = new TreeNode(4);
        /* child nodes of root ele */
        TreeNode root_left = new TreeNode(2);
        TreeNode root_right = new TreeNode(7);
        /* root left's left and right nodes */
        TreeNode leaf_left = new TreeNode(1);
        TreeNode leaf_right = new TreeNode(3);
        root_left.left = leaf_left;
        root_left.right = leaf_right;
        /* root right's left and right nodes */
        leaf_left = new TreeNode(6);
        leaf_right = new TreeNode(9);
        root_right.left = leaf_left;
        root_right.right = leaf_right;

        root.left = root_left;
        root.right = root_right;
        return root;
    }

    public static void main(String[] args) {
        Invert_Binary_Tree invert_binary_tree = new Invert_Binary_Tree();
        TreeNode node = invert_binary_tree.createTreeForTest();
        invert_binary_tree.traverseTreeInOrder(node);
        TreeNode afterInvertNode = invert_binary_tree.invertTree(node);
        System.out.println("\nAfter Invert Tree");
        invert_binary_tree.traverseTreeInOrder(afterInvertNode);
    }

}
