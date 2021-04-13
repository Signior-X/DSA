#%% Wild card matching using caching technique

def solve(s, p):
    # will do this using loop
    stack = [(0,0)]
    # Now store in cache so that only 1 time is executed
    cache = {}

    ans = False
    while(len(stack)):
        # Till now stack is not empty
        val = stack.pop(-1)
        i, j = val
        # print(stack)
        print(i, j)

        if (i, j) in cache:
            continue

        if (i >= len(s)) and (j >= len(p)):
            ans = True
            break

        if (j >= len(p)):
            continue

        cache[(i, j)] = True
        match = (i < len(s)) and ((s[i] == p[j]) or (p[j] == "?"))

        # handle the star cases
        if p[j] == "*":
            
            if i < len(s):
                stack.append((i+1, j))
            
            stack.append((i, j+1))

        if match:
            stack.append((i+1, j+1))
        
        # if (i >= len(s)):
        #     # the case when star has taken place of all
        #     # then only can be true if all the ones after
        #     # it are start
            
        #     # check if this is a star and this is the last one
        #     if p[j] == "*" and (j == (len(p) - 1)):
        #         # we reached to an end
        #         ans = True
        #         break

        #     continue

        # if it is not a match, it is already popped
    
    return ans


def solve2(s, p):
    # We will do this using recursion

    cache = {}

    def dfs(i,j):
        # print(i, j)
        # Base cases

        if (i, j) in cache:
            return cache[(i, j)]

        if (i >= len(s)) and (j >= len(p)):
            return True
        
        if j >= len(p):
            return False
        
        match = (i < len(s)) and ((s[i] == p[j]) or (p[j] == "?"))


        if p[j] == "*":
            cache[(i, j)] = (dfs(i, j+1) or ((i < len(s)) and dfs(i+1, j)))
            return cache[(i, j)]

        if match:
            cache[i, j] = dfs(i+1, j+1)
            return cache[(i, j)]
        
        cache[(i, j)] = False
        return False

    return dfs(0, 0)

a = solve("adceb", "*a*b")
print(a)

b = solve2("adceb", "*a*b")
print(b)
