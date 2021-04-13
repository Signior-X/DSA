class Solution:
    def isMatch(s: str, p: str) -> bool:
        # loop in revers order
        
        cache = {}

        def recursiveMatch(i, j):
            # Base cases
            print(i, j)
            
            if (i,j) in cache:
                return cache[(i,j)]
            
            if i >= len(s) and j >= len(p):
                return True
            
            if j >= len(p):
                return False
            
            # Now the cases, first check if the strings are matching or not
            match = (i < len(s)) and ((s[i] == p[j]) or (p[j] == '.'))
            
            # now check if there is a start after the character or not
            if (j + 1) < len(p) and p[j+1] == "*":
                # the star cases
                # 1. Either skipping it
                # 2. It is matching and we proceed with it
                
                cache[(i,j)] = recursiveMatch(i, j+2) or (match and recursiveMatch(i+1, j))
                return cache[(i, j)]
            
            # now if there is not a star
            if match:
                cache[(i,j)] = recursiveMatch(i+1, j+1)
                return cache[(i, j)]
            
            cache[(i, j)] = False
            return False
            
            
        ans = recursiveMatch(0, 0)
        return ans

    def iter(s, p):
        # Try to the above solution using a loop and a stack
        stack = [(0,0)]
        cache = {}
        
        ans = False
        while(len(stack) > 0):
            # take the last element from the stack
            ele = stack[-1]
            i,j = ele[0], ele[1]
            # print(stack)
            # print(i, j)

            if (i, j) in cache:
                stack.pop(-1)
                continue

            if i >= len(s) and j >= len(p):
                ans = True
                break

            if j >= len(p):
                # nothing can be done for this
                stack.pop(-1)
                continue

            cache[(i, j)] = True
            stack.pop(-1)
            # The basic matching
            match = (i < len(s)) and ((s[i] == p[j]) or (p[j] == '.'))

            # the star case
            if (j + 1) < len(p) and p[j+1] == "*":
                # the star cases
                # 1. Either skipping it
                # 2. It is matching and we proceed with it

                if match:
                    stack.append((i+1, j))
                
                stack.append((i, j+2))
                
                continue
            
            # now if there is not a star
            if match:
                stack.append((i+1, j+1))
                continue
            

        return ans

a = Solution.isMatch('aaabc', 'a*abc')
print(a)

b = Solution.iter('aaabc', 'a*abc')
print(b)
