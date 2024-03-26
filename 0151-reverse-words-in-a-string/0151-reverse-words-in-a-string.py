class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.strip().split()
        x = ""
        for i in range(len(l)-1,-1,-1):
            x+=l[i]
            x+=" "
        return x.rstrip()
        
    