import numpy as np
import random
import copy
import pickle

def eval(X, dist):
    s = 0
    for i in range(1, len(X)):
        s += dist[X[i-1]][X[i]]
    return s

    
if '__main__' == __name__:  
    f = open("dist.pkl", "rb")
    dist = pickle.load(f)
    
    n = dist.shape[0]
    
    X = []
    for i in range(n):
        X.append(i)
        
    random.shuffle(X)
    
    E = eval(X, dist)
    f.close()
    f = open("e.txt", "w")
    
    p = 1.0
    t = 1000
    
    while t >= 1:   
        i = random.randint(0, n-1)
        j = random.randint(0, n-1)
        
        Xi = copy.deepcopy(X)
        Xi[i], Xi[j] = Xi[j], Xi[i]
        
        Ei = eval(Xi, dist)
        if Ei < E:
            X = copy.deepcopy(Xi)
            E = Ei
        elif random.random() < p:
            X = copy.deepcopy(Xi)
            E = Ei
        
        p = p - p/t
        t -= 1
        
        f.write(str(E) + "\n")
        
    f.close()