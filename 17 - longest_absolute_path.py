def longest_absolute_path(s):
    level = {-1: 0}
    max_len = 0
    for line in s.split('\n'):
        depth = line.count('\t')
        level[depth] = len(line) - depth + level[depth - 1]

        if '.' in line:
            max_len = max(max_len, level[depth] + depth)
    
    print(level)
    return max_len


if __name__ == "__main__":
    print(longest_absolute_path("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"))
