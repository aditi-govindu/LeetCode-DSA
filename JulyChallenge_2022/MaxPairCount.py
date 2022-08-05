from collections import defaultdict
 
def maxCountSameSUM(arr, n):
 
    # Create a map to store frequency
    M = defaultdict(lambda:0)
 
    # Store hash
    for i in range(0, n - 1):
        for j in range(i + 1, n):
            M[arr[i] + arr[j]] += 1
 
    return max(M.values())