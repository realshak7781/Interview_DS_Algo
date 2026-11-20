# time : o(k*log(n))
# space : o(n)

class Node:
    def __init__(self, maxLen=0, lc='', rc='', pfL=0, rfL=0):
        self.maxLen = maxLen
        self.leftMostChar = lc
        self.rightMostChar = rc
        self.prefLen = pfL
        self.sufLen = rfL

class Solution:
    def mergeNodes(self, L: Node, R: Node, leftLen: int, rightLen: int) -> Node:
        root = Node()
        root.maxLen = max(L.maxLen, R.maxLen)
        if L.rightMostChar == R.leftMostChar:
            root.maxLen = max(root.maxLen, L.sufLen + R.prefLen)
        
        root.rightMostChar = R.rightMostChar
        root.leftMostChar = L.leftMostChar

        root.prefLen = L.prefLen
        root.sufLen = R.sufLen

        if leftLen == L.prefLen and L.rightMostChar == R.leftMostChar:
            root.prefLen = L.prefLen + R.prefLen
        
        if rightLen == R.sufLen and L.rightMostChar == R.leftMostChar:
            root.sufLen = R.sufLen + L.sufLen
        
        return root
    
    def buildSegTree(self, node: int, l: int, r: int, seg: list[Node], s: str) -> Node:
        if l == r:
            seg[node] = Node(1, s[l], s[r], 1, 1)
            return seg[node]
        
        mid = l + (r - l) // 2
        leftNode = self.buildSegTree(2 * node + 1, l, mid, seg, s)
        rightNode = self.buildSegTree(2 * node + 2, mid + 1, r, seg, s)

        seg[node] = self.mergeNodes(leftNode, rightNode, mid - l + 1, r - mid)
        return seg[node]

    def updateSegTree(self, node: int, l: int, r: int, seg: list[Node], idx: int, ch: str) -> Node:
        if l == r:
            seg[node] = Node(1, ch, ch, 1, 1)
            return seg[node]
        
        mid = l + (r - l) // 2
        if idx <= mid:
            self.updateSegTree(2 * node + 1, l, mid, seg, idx, ch)
        else:
            self.updateSegTree(2 * node + 2, mid + 1, r, seg, idx, ch)
        
        seg[node] = self.mergeNodes(seg[2 * node + 1], seg[2 * node + 2], mid - l + 1, r - mid)
        return seg[node]

    def query(self, seg: list[Node]) -> int:
        return seg[0].maxLen
    
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: list[int]) -> list[int]:
        n = len(s)
        k = len(queryIndices)
        segSize = 4 * n
        seg = [None] * segSize

        self.buildSegTree(0, 0, n - 1, seg, s)

        res = [0] * k

        for i in range(k):
            queryIdx = queryIndices[i]
            queryCh = queryCharacters[i]

            self.updateSegTree(0, 0, n - 1, seg, queryIdx, queryCh)
            res[i] = self.query(seg)
        
        return res
