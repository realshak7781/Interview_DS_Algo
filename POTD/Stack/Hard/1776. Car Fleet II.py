# Time : O(2*n)
# space : o(n)

class Solution:

    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        n=len(cars)
        res=[-1]*n

        stack=[]

        for i in range(n-1,-1,-1):
            pi,si=cars[i]

            while stack:
                j = stack[-1] 
                pj, sj = cars[j]

                if sj>=si:
                    stack.pop()
                    continue

                deltaT = (pj - pi) / (si - sj)

                if res[j]!=-1 and deltaT>=res[j]:
                    stack.pop()
                else:
                    # found a valid ans : yeajj
                    res[i]=deltaT
                    break

            stack.append(i)

        
        return res


