#CSES - Easy (Apple Division)
n = int(input())

weights = list(map(int, input().split()))

def find_min_difference(idx, sum1, sum2):
    #if we reached the end
    if idx == n:
        return abs(sum2 - sum1)
    #either add the weights on the left or the right
    #return the minimum of the two
    return min(
        find_min_difference(idx + 1, sum1 + weights[idx], sum2), 
        find_min_difference(idx + 1, sum1, sum2 + weights[idx])
    )

min_difference = find_min_difference(0, 0, 0)
print(min_difference)