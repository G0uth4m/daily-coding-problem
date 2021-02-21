import heapq

def max_product(arr):
    maxis = heapq.nlargest(3, arr)
    minis = heapq.nsmallest(2, arr)
    return max(maxis[0] * maxis[1] * maxis[2], minis[0] * minis[1] * maxis[0])

def main():
    arr = [-10, -10, 5, 2]
    print(max_product(arr))

if __name__ == "__main__":
    main()