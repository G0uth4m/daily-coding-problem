"""
This problem was asked by Quora.

Given an absolute pathname that may have . or .. as part of it, return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
"""

def simplify(path):
    path = path.split("/")
    stack = []
    for i in path:
        if i == "..":
            stack.pop()
        elif i == '.':
            continue
        else:
            stack.append(i)
    
    return "/".join(stack)

def main():
    res = simplify("/usr/bin/../bin/./scripts/../")
    print(res)

if __name__ == "__main__":
    main()
