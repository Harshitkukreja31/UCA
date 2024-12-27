public class RBT {
    public static boolean RED = true;
    public static boolean BLACK = false;

    class Node {
        Integer key;
        Integer value;
        Node left;
        Node right;
        Boolean color = false;

        public Node(Integer key, Integer value, Boolean color) {
            this.key = key;
            this.value = value;
            this.color = color;
            left = null;
            right = null;
        }
    }

    private Node root;

    private boolean isRed(Node h) {
        if (h == null) return false;
        return h.color;
    }

    private Node rotateLeft(Node h) {
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }

    private Node rotateRight(Node h) {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }

    private Node flipColor(Node h) {
        h.color = RED;
        if (h.left != null) {
            h.left.color = BLACK;
        }
        if (h.right != null) {
            h.right.color = BLACK;
        }
        return h;
    }

    public void put(Integer key, Integer value) {
        root = put(root, key, value);
        root.color = BLACK; // root is always black
    }

    private Node put(Node h, Integer key, Integer value) {
        if (h == null) return new Node(key, value, RED);

        int cmp = key.compareTo(h.key);
        if (cmp == 0) h.value = value;
        else if (cmp < 0) h.left = put(h.left, key, value);
        else if (cmp > 0) h.right = put(h.right, key, value);

        if ((h.right != null && isRed(h.right)) && (h.left == null || !isRed(h.left))) h = rotateLeft(h);
        if ((h.left != null && isRed(h.left)) && (h.left.left != null && isRed(h.left.left))) h = rotateRight(h);
        if ((h.left != null && isRed(h.left)) && (h.right != null && isRed(h.right))) h = flipColor(h);

        return h;
    }

    public Integer get(Integer key) {
        Node x = root;
        while (x != null) {
            int cmp = key.compareTo(x.key);
            if (cmp == 0) return x.value;
            else if (cmp < 0) x = x.left;
            else x = x.right;
        }
        return null;
    }

    // Main function to test the RBT implementation
    public static void main(String[] args) {
        RBT rbt = new RBT();

        // Test Case 1: Insert a single key-value pair
        rbt.put(1, 100);
        assert rbt.get(1) == 100 : "Test Case 1 Failed";

        // Test Case 2: Insert multiple key-value pairs and retrieve them
        rbt.put(2, 200);
        rbt.put(3, 300);
        rbt.put(4, 400);
        assert rbt.get(2) == 200 : "Test Case 2.1 Failed";
        assert rbt.get(3) == 300 : "Test Case 2.2 Failed";
        assert rbt.get(4) == 400 : "Test Case 2.3 Failed";

        // Test Case 3: Update the value of an existing key
        rbt.put(3, 350);
        assert rbt.get(3) == 350 : "Test Case 3 Failed";

        // Test Case 4: Insert a larger number of keys and verify their existence
        for (int i = 5; i <= 15; i++) {
            rbt.put(i, i * 10);
        }
        for (int i = 5; i <= 15; i++) {
            assert rbt.get(i) == i * 10 : "Test Case 4 Failed at key " + i;
        }

        // Test Case 5: Try retrieving a non-existing key
        assert rbt.get(20) == null : "Test Case 5 Failed";

        // If all assertions pass
        System.out.println("All test cases passed!");
    }
}
