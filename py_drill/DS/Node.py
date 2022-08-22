class Node:
    def __init__(self, data, pnext=None):
        self.data = data
        self.pnext = pnext

    def __repr__(self):
        return "Node(data, pnext)"

    def __str__(self):
        return f"{self.data} {self.pnext}"


def main():
    n1 = Node(10)
    print(n1)

if __name__ == "__main__":
    main()