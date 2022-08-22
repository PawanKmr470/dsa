class Node:
    def __init__(self, data, pnext=None):
        self.data = data
        self.pnext = pnext

    def __repr__(self):
        return "Node(data, pnext)"

    def __str__(self):
        return f"{self.data} {self.pnext}"

class BSTNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __repr__(self):
        return "tNode(data, left, right)"

    def __str__(self):
        return f"data : {self.data}, left : {self.left}, right : {self.right}"


def main():
    n1 = Node(10)
    print(n1)
    t1 = BSTNode(20)
    print(t1)

if __name__ == "__main__":
    main()