#https://www.acmicpc.net/problem/10950

test_cases = int(input())

for i in range(test_cases):
    input_data = input().split()
    
    A = int(input_data[0])
    B = int(input_data[1])
    print(A+B)