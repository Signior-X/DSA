#%% zig zag problem 6 of leetcode
s = "PAYPALISHIRING"
numRows = 3

if numRows == 1:
    print(s)

ans = ["" for i in range(numRows)]

# we will need n + n - 2 = 6 jumps for each block of ans
# 0, 6 + 0, 12 + 0, 18 + 0
# 1, 6-1, 6 + 1, 12 - 1, 12 + 1
# 2, 6-2, 6 + 2, 12 - 2, 12 + 2
# 3, 6 + 3, 12 + 3, 18 + 3

# first create ans[0]
i = 0
steps = 2*numRows - 2
while(i<len(s)):
    ans[0] += s[i]
    i += steps

for j in range(1, numRows - 1):
    i = 1
    if j < len(s):
        ans[j] = s[j]
    
    while (steps*i - j) < len(s):
        ans[j] += s[steps*i - j]

        if (steps*i + j) < len(s):
            ans[j] += s[steps*i + j]
        i += 1

i = numRows - 1
while(i<len(s)):
    if i < len(s):
        ans[numRows-1] += s[i]
    i += steps

print((ans))
