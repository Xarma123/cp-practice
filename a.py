def findMinima(arr):
    n = len(arr)
    if n < 3:
        return -1
    # Initialize two pointers
    left = 1
    right = 2
    # Move the pointers
    while right < n and left < n:
        print(left)
        print(right)
        if arr[left] < arr[right]:
            right += 1
        else:
            left += 1
    # The minimum element is at index left
    return left
arr=[7,6,5,4,5,6,7]
print(findMinima(arr))