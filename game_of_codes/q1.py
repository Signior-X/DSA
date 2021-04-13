R = lambda:list(map(int,input().split()))

tests = int(input())

while(tests  > 0):

    # start your code here
    a = int(input())

    if a == 1 or a == 2 or a == 10 or a == 11 or a == 12 or a == 13 or a == 14 or a == 15 or a == 16:
        print('Vyom')
    else:
        print('Kartik')

    tests -=1