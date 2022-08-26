from Node import BSTNode
from collections import deque

class BST:
    def __init__(self):
        self.root = None

    def insert_rec(self, keys=[]):
        print("Inserting elements : " + str(keys))
        for key in keys:
            self.root = self.__insert_rec(self.root, key)

    def __insert_rec(self, node, key):
        if node is None:
            return BSTNode(key)

        if key < node.data:
            node.left = self.__insert_rec(node.left, key)
        else:
            node.right = self.__insert_rec(node.right, key)
        return node

    def insert(self, keys=[]):
        print("Inserting elements : " + str(keys))
        for key in keys:
            self.__insert_nonrecursive(key)

    def __insert_nonrecursive(self, key):
        new_node = BSTNode(key)
        if self.root is None:
            self.root = new_node
            return

        # while cur_node: is also fine and for it, need to take backup of parent node
        cur_node = self.root
        while cur_node.left and cur_node.right:
            if key < cur_node.data:
                cur_node = cur_node.left
            else:
                cur_node = cur_node.right

        if key < cur_node.data:
            cur_node.left = new_node
        else:
            cur_node.right = new_node

    #
    # Preorder Traversal
    #
    def print_preorder(self):
        result = []
        if self.root is None:
            print("BST is empty.")
            return

        stack = []
        stack.append(self.root)
        while len(stack) > 0:
            node = stack.pop()
            result.append(node.data)

            # NOTE : push right first bcz it will be popped at last or visited last
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        print("Preorder element : {}".format(result))

    def print_preorder_rec(self):
        if self.root is None:
            print("BST is empty.")
            return
        self.__print_preorder_rec(self.root)

    def __print_preorder_rec(self, node):
        if node is None:
            return
        print("Preorder rec element : {}".format(node.data))
        self.__print_preorder_rec(node.left)
        self.__print_preorder_rec(node.right)

    #
    # Inorder Traversal
    #
    def print_inorder(self):
        if self.root is None:
            print("BST is empty.")
            return

        stack = []
        node = self.root
        while len(stack) or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                print("Inorder element : {}".format(node.data))
                node = node.right

    def print_inorder_rec(self):
        if self.root is None:
            print("BST is empty.")
            return
        self.__print_inorder_rec(self.root)

    def __print_inorder_rec(self, node):
        if node is None:
            return
        self.__print_inorder_rec(node.left)
        print("Inorder rec element : {}".format(node.data))
        self.__print_inorder_rec(node.right)

    #
    # Postorder Traversal
    #
    def print_postorder(self):
        print("TODO")
        return

    def print_postorder_rec(self):
        if self.root is None:
            print("BST is empty.")
            return
        self.__print_postorder_rec(self.root)

    def __print_postorder_rec(self, node):
        if node is None:
            return
        self.__print_postorder_rec(node.left)
        self.__print_postorder_rec(node.right)
        print("Postorder rec element : {}".format(node.data))

    #
    # Levelorder Traversal
    #
    def print_levelorder(self):
        if self.root is None:
            print("BST is empty.")
            return

        q = deque()
        cur_node = self.root
        q.append(cur_node)
        while len(q):
            cur_node = q.popleft()
            print("Levelorder element : {}".format(cur_node.data))
            if cur_node.left:
                q.append(cur_node.left)
            if cur_node.right:
                q.append(cur_node.right)

    # It doesn't use queue
    # Implemented with calculating height and then traversing all nodes at each level
    def print_levelorder_rec(self):
        return

    # Height using recursion
    def print_height_rec(self):
        bst_height = self.__print_height_rec(self.root)
        print("Height rec of BST is : {}".format(bst_height))

    def __print_height_rec(self, node):
        if node is None:
            return -1
        return 1 + max(self.__print_height_rec(node.left), self.__print_height_rec(node.right))

    # Height using queue (iterative)
    def print_height(self):
        bst_height = self.__print_height()
        print("Height of BST is : {}".format(bst_height))

    def __print_height(self):
        if self.root is None:
            return -1

        height = 0
        q = deque()
        q.append(self.root)

        while True:
            node_count = len(q)
            if node_count == 0:
                return height - 1

            height += 1

            while node_count:
                cur_node = q.popleft()
                if cur_node.left:
                    q.append(cur_node.left)
                if cur_node.right:
                    q.append(cur_node.right)
                node_count -= 1


def main():
    bst = BST()
    bst_rec = BST()

    bst.insert([5, 1, 10, 100, 200, 300, 400])
    bst_rec.insert([5, 1, 10, 100, 200, 300, 400])
    # bst.insert_([50, 10, 100])
    # bst_rec.insert_rec([50, 10, 100])

    print("****************************")
    bst.print_preorder()
    bst_rec.print_preorder_rec()
    print("****************************")
    bst.print_inorder()
    bst_rec.print_inorder_rec()
    print("****************************")
    bst.print_postorder()
    bst_rec.print_postorder_rec()
    print("****************************")
    bst.print_levelorder()
    print("****************************")
    bst.print_height()
    bst_rec.print_height_rec()
    # bst1 = BST()
    # bst1.insert([5])
    # bst1.print_height()


if __name__ == "__main__":
    main()