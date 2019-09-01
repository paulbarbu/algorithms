import numpy as np
import random
import pickle

if '__main__' == __name__:
    # nr orase
    n = int(input("Nr. orase="))
    print(n)
    dist = np.zeros((n, n))
    
    f = open("dist.pkl", "wb")
    
    for i in range(n):
        for j in range(n):
            dist[i][j] = random.randint(1, 100)
            
    pickle.dump(dist, f)
    f.close()