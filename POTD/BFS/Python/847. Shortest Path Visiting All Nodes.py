

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n=len(graph)

        q=deque()
        vis=set()
        target_mask=(1<<n)-1

        for i in range(n):
            initial_mask=(1<<i)
            q.append((i,initial_mask))
            vis.add((i,initial_mask))
        

        steps=0

        while q:
            size=len(q)

            for _ in range(size):
                node,mask=q.popleft()

                if mask==target_mask:
                    return steps
                
                for neigh in graph[node]:
                    next_mask = mask | (1 << neigh)

                    if (neigh,next_mask) not in vis:
                        vis.add((neigh,next_mask))
                        q.append((neigh,next_mask))

                
            steps+=1
        
        return -1
        
