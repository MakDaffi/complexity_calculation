class Node(object):
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class Tree(object):
    def __init__(self):
        self.root = None

def insert(v, x):
    if v is None:
        return Node(x)
    if x < v.key:
        v.left = insert(v.left, x)
    elif x > v.key:
        v.right = insert(v.right, x)
    # v.key == x
    return v

def search(v, x):
    if v is None or v.key == x:
        return v
    elif x < v.key:
        return search(v.left, x)
    else:  # x > v.key
        return search(v.right, x)

def find_min(v):
    if v.left is not None:
        return find_min(v.left)
    else:
        return v

def delete(v, x):
    if v is None:
        return None
 
    if x < v.key:
        v.left = delete(v.left, x)
        return v
    elif x > v.key:
        v.right = delete(v.right, x)
        return v
 
    # v.key == x
    if v.left is None:
        return v.right
    elif v.right is None:
        return v.left
    else:
        # both subtrees are present
        min_key = find_min(v.right).key
        v.key = min_key
        v.right = delete(v.right, min_key)
        return v

tree = Tree()
print('Enter your array: ')
a = list(map(int, input().split()))
for x in a:
    tree.root = insert(tree.root, x)

print('Enter the element you want to find')
find = int(input())
if search(tree.root, find) == None:
    print('This element does not exist in the given tree')
else:
    print('The element is part of the given tree')