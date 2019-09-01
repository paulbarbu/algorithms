import numpy as np
import random

def knapsack(B, s):
    for w in range(B.shape[1]):
        B[0, w] = 0
        
    for i in range(B.shape[0]):
        B[i, 0] = 0
        
    for i in range(1, B.shape[0]):
        for w in range(B.shape[1]):
            wi = s[i-1][0]
            bi = s[i-1][1]
            if wi <= w:
                if bi + B[i-1, w-wi] > B[i-1, w]:
                    B[i,w] = bi + B[i-1, w-wi]
                else:
                    B[i,w] = B[i-1,w]
            else:
                B[i,w] = B[i-1,w]
         
            
    print(B)

    
def find_items(B, s):
    items_indices = []
    W = B.shape[1]
    i = B.shape[0] - 1
    k = W - 1
    
    while i>0 and k>0:
        wi = s[i-1][0]
        if B[i,k] != B[i-1,k]:
            items_indices.append(i)
            i = i-1
            k = k-wi
        else:
            i= i-1
    return items_indices
    
    
if '__main__' == __name__:
    
    # nr obiecte si capacitate max
    s=[]
    n = int(input("Nr. obiecte="))
    W = int(input("Capacitate maxima="))
    
    for i in range(n):
        s.append((random.randint(1, W), random.randint(1, 100)))
    
    #s = [(2,3), (3,4), (4,5), (5,6)] # [(weight, benefit)]
    #n = len(s)
    #W = 5
    
    n+=1
    W+=1
    
    B = np.arange(n*W).reshape(n,W)
        
    knapsack(B, s)
    print(B)
    
    item_indices = find_items(B,s)
    print(item_indices)