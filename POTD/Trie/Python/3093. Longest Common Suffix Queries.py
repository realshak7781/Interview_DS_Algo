# // M- No of words in query
# // N = number of words in wordsContainer
# // Lcontainer=max len of word in container
# // Lquery=max len of word in query

# // TIME : O(N*Lcontainer + M*Lquery))
# // SPACE : O(N*Lcontainer + M)


class TrieNode:
    def __init__(self,ch):
        self.data=ch
        self.children=[None]*26
        self.isTerminalNode = False
        self.minWordIdx=-1

class Trie:
    def __init__(self):
        self.root=TrieNode('\0')
    
    def insertUtil(self,root, curIdx, word, wordsContainer, wordIdx):
        if root.minWordIdx==-1:
            root.minWordIdx=wordIdx
        else:
            curBestLen = len(wordsContainer[root.minWordIdx])
            newWordLen = len(word)

            if curBestLen > newWordLen:
                root.minWordIdx = wordIdx
        
        if curIdx==len(word):
            root.isTerminalNode=True
            return
        
        charIdx = ord(word[curIdx]) - ord('a')
        child=None

        if root.children[charIdx]:
            child=root.children[charIdx]
        else:
            child=TrieNode(word[curIdx])
            root.children[charIdx]=child
        
        self.insertUtil(child, curIdx + 1, word, wordsContainer, wordIdx)
    
    def insertWord(self, wordIdx, wordsContainer):
        self.insertUtil(self.root, 0, wordsContainer[wordIdx], wordsContainer, wordIdx)
    

    def searchWordIdx(self,query):
        cur=self.root

        for ch in query:
            charIdx=ord(ch)-ord('a')

            if cur.children[charIdx] is None:
                break
            else:
                cur=cur.children[charIdx]
        
        return cur.minWordIdx

class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:

        for i in range(len(wordsContainer)):
            wordsContainer[i] = wordsContainer[i][::-1]

        for i in range(len(wordsQuery)):
            wordsQuery[i] = wordsQuery[i][::-1]
        
        t=Trie()

        for i in range(len(wordsContainer)):
            t.insertWord(i,wordsContainer)
        

        res = []

        for query in wordsQuery:
            res.append(t.searchWordIdx(query))
        
        return res
        
