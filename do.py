#%%
fl = open('abc')
data = fl.read()
lst = data.split('\n')

#%%
compiled_data = []
test1_data = []
test2_data = []

for x in lst:
    print(x)
    # loop in x and find the first space
    i = len(x) - 1

    while(i>=0):
        print("here", x[i])
        if x[i] == " ":
            break
        else:
            i-=1
    
    p2marks = int(x[i+1:])
    
    k = i-1
    i -= 1
    while(i>=0):
        print("here2", x[i])
        if x[i] == " ":
            break
        else:
            i-=1
    
    p1marks = int(x[i+1:k+1])

    j = 0
    while(j<len(x)):
        if x[j] == " ":
            break
        else:
            j+=1
    
    roll = x[:j]
    name = x[j+1:i]

    compiled_data.append([(p1marks+p2marks), roll, name, p1marks, p2marks])
    test1_data.append([p1marks, roll, name])
    test2_data.append([p2marks, roll, name])

compiled_data

#%%
sorted(compiled_data, reverse=True)


#%%
sorted(test1_data, reverse=True)
