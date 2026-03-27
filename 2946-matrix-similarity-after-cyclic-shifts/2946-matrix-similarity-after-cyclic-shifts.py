from typing import List
class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        l=len(mat[0])
        n=len(mat)
        m=mat
        for i in range(k):
            listt=[[0]*l for _ in range(n)]
            xx=0;
            for a in range(len(m)):
                for j in range(len(m[0])):
                    if((a%2)==1):
                        listt[a][(j+1)%l]=m[a][j]
                    else:
                        listt[a][(l+j-1)%l]=m[a][j]
            m=listt
            flagg=0
            xx+=1
        for i in range(n):
            for j in range(l):
                if(m[i][j]!=mat[i][j]):
                    flagg=1
                    break
        if(flagg==1):
            		return False
        else:
                   return True
 