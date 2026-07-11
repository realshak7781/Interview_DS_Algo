// Using BINARY SEARCH ON ANSWERS
// TIME : O(NLOGN) + oO(LOG(109))
// SPACE: O(N)


class Solution:
    def check(self,energy:int,res:List[Tuple[int, int, int]])->bool:

        for _, actual, min_energy in res:
            if energy<min_energy:
                return False
            
            energy-=actual
        
        return energy>=0
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        res=[]
        maxi=-1
        for task in tasks:
            res.append((task[1]-task[0],task[0],task[1]))
            maxi=max(maxi,task[1])
        
        res.sort(
            key=lambda x : (-x[0], -x[2], x[1])
        )

        low=maxi
        high=10**9
        reqMinEnergy=-1

        while low<=high:
            mid=low + (high-low)//2

            if self.check(mid,res):
                reqMinEnergy=mid
                high=mid-1
            else:
                low=mid+1
        
        return reqMinEnergy
