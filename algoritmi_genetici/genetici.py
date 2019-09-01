import numpy as np
import random
import copy
import pickle
import math
import sys

#random.seed(1)

def eval(X, dist):
    s = 0
    for i in range(1, len(X)):
        s += dist[X[i-1]][X[i]]
    return s


def gen_populatie(num_cities, size):
    seq = list(range(num_cities))
    p = []
    p.append(seq)
    
    for i in range(1, size):
        random.shuffle(seq)
        p.append(copy.deepcopy(seq))
        
    return p
    
    
def eval_population(p, dist):
    """ Cheie = f(x)
        Valoare = x
    """
    fitness = list(map(lambda x: eval(x,dist), p))
    return dict(zip(fitness, p))
    
    
def roulette(p, n):
    fitness_to_population = copy.deepcopy(p)
    selected = []
    for i in range(0, 2):
        normalized_fitness = list(map(lambda x: 1/x, fitness_to_population.keys()))
        sum_fitness = sum(normalized_fitness)
        probabilities = list(map(lambda p: p/sum_fitness, normalized_fitness))
        #TODO: aici ar trebui sa pastrez ordinea sortarii?
        
        #print(probabilities)
        #print(sum(probabilities))
    
        r = random.random()
        pos = 0
        s = probabilities[pos]        
        
        while s < r and pos < len(probabilities):
            s += probabilities[pos]
            pos += 1
    
        #print("pos=", pos)
        #print("s=", s)
        #print("r=", r)
       
        if pos == len(probabilities):
            pos -= 1
            
        fitness = list(fitness_to_population.keys())[pos]
        selected.append(fitness_to_population[fitness])
        del fitness_to_population[fitness]
    
    return selected
    
    
def mutation(x):
    pos1 = random.randint(0, len(x)-1)
    pos2 = random.randint(0, len(x)-1)
    
    #print("pos1 = " + str(pos1))
    #print("pos2 = " + str(pos2))
        
    x[pos1], x[pos2] = x[pos2], x[pos1]
    
    return x

def crossover(x1, x2, dist):
        
    return x1
    
    
def crossover3(x1, x2, dist):
    x=[]
    pos = 0
    
    i=0
    while i < len(x1):
        print(x1)
        print(sorted(x1))
        print(pos)
        s = copy.deepcopy(x1[pos])
        
        pos1 = pos + 1    
        if pos1 >= len(x1):
            pos1 = 0
            
        
        pos2 = x2.index(x1[pos])
        pos2 += 1    
        if pos2 >= len(x1):
            pos2 = 0
            
        
        if dist[s][x1[pos1]] < dist[s][x2[pos2]]:
            print("aleg e1")
            i+=1
            x.append(x1[pos1])
            pos = pos1
        else:
            print("aleg e2")
            
            i+=1
            x.append(x2[pos2])
            pos = pos2
    
        #print(x1)
        #print(x2)
        #print(s)
        #print(e1)
        #print(e2)
        #print(pos)
        #print(pos2)
        
    print(x)
    print(sorted(x))
    return x
    
    
def crossover2(origx1, origx2, dist):  
    x1 = copy.deepcopy(origx1)
    x2 = copy.deepcopy(origx2)
    x = []
    
    start_city = None
    end_city = None
    end_city1 = None
    end_city2 = None
    
    pos11 = random.randint(0, len(x1)-1)
    pos21 = pos11 + 1
    
    if pos21 >= len(x1):
        pos21 = 0
        
    
    x.append(start_city)
    
    for i in range(0, len(x1)-1):
        x1 = copy.deepcopy(origx1)
        x2 = copy.deepcopy(origx2)
        #print("pos11: " + str(pos11))
        #print("pos21: " + str(pos21))
        start_city = x1[pos11]
        end_city1 = x1[pos21]
        x1 = copy.deepcopy(origx1)
        x2 = copy.deepcopy(origx2)
        #print("start_city: " + str(start_city))
        #print("end_city1: " + str(end_city1))
        
        try:
            pos12 = x2.index(start_city)
        except ValueError:
            print(x2)
            print(sorted(x2))
            print(origx2)
            print(sorted(origx2))
            raise
        pos22 = pos12 + 1
        
        if pos22 >= len(x1):
            pos22 = 0
        
        #print("pos12: " + str(pos12))
        #print("pos22: " + str(pos22))
        
        end_city2 = x2[pos22]
        
        #print("start_city: " + str(start_city))
        #print("end_city2: " + str(end_city2))
        
        end_city = None
        if dist[start_city][end_city1] < dist[start_city][end_city2]:
            end_city = end_city1
        else:
            end_city = end_city2

        #print("start_city: " + str(start_city))
        #print("end_city: " + str(end_city))
        
        x.append(end_city)
        x1 = copy.deepcopy(origx1)
        x2 = copy.deepcopy(origx2)
        try:        
            pos11 = x1.index(end_city)
        except ValueError:
            print(x1)
            print(origx1)
            print(sorted(x1))
            print(sorted(origx1))
            raise
        pos21 = pos11 + 1

        if pos21 >= len(x1):
            pos21 = 0
        
        #start_city = end_city
    
    #print(x1)
    #print(eval(x1, dist))
    #print(x2)
    #print(eval(x2, dist))
    #print(x)
    #print(eval(x, dist))
    #print(len(x))
    #exit(1)
    return x
    
        
if '__main__' == __name__:  
    f = open("dist.pkl", "rb")
    dist = pickle.load(f)
    f.close()
    n = dist.shape[0] # nr de orase
    
    
    f = open("min.txt", "w")
    
    population_size = 100  
    p = gen_populatie(n, population_size)
    #print(p)
    #exit(1)
    
    #f = open("p.pkl", "wb")        
    #pickle.dump(p, f)
    #f.close()
    epsilon = 1
    num_iter = 100
    
    #p = pickle.load(open("p.pkl", "rb"))
    
    #print(p)
    fitness_to_population = eval_population(p, dist)
    #print(fitness_to_population)
    #exit(1)
    
    #x = {0.5:1, 0.2:2, 0.3:4}
    #print(x)
    #print(roulette(x, 2))
    #print(x)
    #exit(1)
    
    
    #a = [1, 2, 3, 4, 5, 6]
    #print(mutation(a))
    #print(a)
    #exit(1)
    
    #a = [1, 2, 3, 4, 5, 6]
    #b = [6, 5, 4, 3, 2, 1]
    #crossover(a, b)
    #exit(1)
    
    minimum = sys.float_info.max
    new_minimum = min(fitness_to_population.keys())
    
    print(new_minimum)
        
    t=0
    while abs(minimum - new_minimum) > epsilon or t < num_iter:
        best_fit = {}
        
        # move the best half of the first population
        sorted_fitness = sorted(fitness_to_population.keys())
        #print(sorted_fitness)
        for i in range(0, population_size//2):
            #print(sorted_fitness[i], fitness_to_population[sorted_fitness[i]])
            best_fit[sorted_fitness[i]] = fitness_to_population[sorted_fitness[i]]
                
        #print(len(best_fit))
        #print("roulette")
        
        new_p = copy.deepcopy(list(best_fit.values()))
        #print(new_p)
        
        i=0
        while i < population_size//2:
            num_chromosomes = random.randint(1, 2)
            selected_chromosomes = roulette(best_fit, num_chromosomes)
            
            if num_chromosomes == 1:
                #print('mutation')
                new_p.append(mutation(selected_chromosomes[0]))
                i+=1
            else:
                #print('crossover')
                x = crossover(selected_chromosomes[0], selected_chromosomes[1], dist)
                new_p.append(x)
                i+=1
                
        
        #print(new_p)
        #print("size " + str(len(new_p)))
        fitness_to_population = eval_population(new_p, dist)
        #print(fitness_to_population)
        
        minimum = new_minimum
        new_minimum = min(fitness_to_population.keys())
        #print(new_minimum)
        f.write(str(new_minimum) + "\n")
        #print(abs(minimum - new_minimum))
        t+=1
        
    #sorted_fitness = sorted(fitness_to_population.keys())
    #print("f({})={}".format(fitness_to_population[sorted_fitness[0]], sorted_fitness[0]))
    f.close()
    