# Node class represents each node in the binary tree
class Node:
    def __init__(self, key):
        self.left = None  # Left child of the node
        self.right = None  # Right child of the node
        self.value = key  # Value stored in the node

# BinaryTree class represents the binary tree structure
class BinaryTree:
    def __init__(self):
        self.root = None  # Root node of the binary tree

    # Insert a new key into the binary tree
    def insert(self, key):
        # If the tree is empty, create the root node
        if self.root is None:
            self.root = Node(key)
        else:
            # Otherwise, use a recursive helper function to insert the key
            self._insert_recursive(self.root, key)

    # Helper function for insertion to place the key in the correct position
    def _insert_recursive(self, current_node, key):
        # If the key is less than the current node value, go to the left subtree
        if key < current_node.value:
            if current_node.left is None:
                current_node.left = Node(key)  # Create a new node on the left
            else:
                # Recursively insert in the left subtree
                self._insert_recursive(current_node.left, key)
        # If the key is greater than the current node value, go to the right subtree
        elif key > current_node.value:
            if current_node.right is None:
                current_node.right = Node(key)  # Create a new node on the right
            else:
                # Recursively insert in the right subtree
                self._insert_recursive(current_node.right, key)

    # In-order traversal: Left -> Root -> Right
    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)  # Traverse the left subtree
            print(node.value, end=' ')  # Visit the root node
            self.inorder_traversal(node.right)  # Traverse the right subtree

    # Pre-order traversal: Root -> Left -> Right
    def preorder_traversal(self, node):
        if node:
            print(node.value, end=' ')  # Visit the root node
            self.preorder_traversal(node.left)  # Traverse the left subtree
            self.preorder_traversal(node.right)  # Traverse the right subtree

    # Post-order traversal: Left -> Right -> Root
    def postorder_traversal(self, node):
        if node:
            self.postorder_traversal(node.left)  # Traverse the left subtree
            self.postorder_traversal(node.right)  # Traverse the right subtree
            print(node.value, end=' ')  # Visit the root node

# Example usage to demonstrate the binary tree operations
if __name__ == "__main__":
    tree = BinaryTree()  # Create an instance of the binary tree

    # Insert values into the binary tree
    values = [50, 30, 20, 40, 70, 60, 80]
    for value in values:
        tree.insert(value)

    # Display the binary tree in different traversal orders
    print("In-order traversal:")
    tree.inorder_traversal(tree.root)  # Output: 20 30 40 50 60 70 80

    print("\nPre-order traversal:")
    tree.preorder_traversal(tree.root)  # Output: 50 30 20 40 70 60 80

    print("\nPost-order traversal:")
    tree.postorder_traversal(tree.root)  # Output: 20 40 30 60 80 70 50
