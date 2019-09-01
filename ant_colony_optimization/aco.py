import pdb
import numpy as np
import random
import copy
import pickle
import sys

#random.seed(1)

def eval(X, dist):
    s = 0
    for i in range(1, len(X)):
        s += dist[X[i-1]][X[i]]
    return s

def roulette(probabilities):
    r = random.random()
    pos = 0
    s = probabilities[pos][1]

    while s < r and pos < len(probabilities):
        pos += 1
        s += probabilities[pos][1]

    if pos == len(probabilities):
        pos -= 1

    return probabilities[pos][0]

if '__main__' == __name__:
    #np.set_printoptions(threshold=np.nan)
    T = 100 # num iteratii
    alfa = 1.0 #how much the ants takes in consideration the pheromone trail
    beta = 10.0 #how much the ants takes in consideration the distance between the cities
    evaporate_rate = 0.5 #percent of the pheromone that evaporates
    e = 5.0 #the multiplication value for the pheromone intensity of the elitist ant
    Q = 100.0 # Direct proportional with the quantity of pheromone deposited

    f = open("dist.pkl", "rb")
    dist = pickle.load(f)

    f.close()
    f = open("e" + sys.argv[1] + ".txt", "w")

    n = dist.shape[0] # num cities
    m = 10 #dist.shape[0] # num ants

    ants = []
    shortest_tour = []
    length_shortest = sys.maxsize

    #print(n)
    #print(dist)

    feromone_trails = np.full(dist.shape, 10 ** -6)
    #print(feromone_trails)

    cities = list(range(n))

    #print(cities)

    for k in range(m):
        city = random.choice(cities)
        ants.append(city)
        cities.remove(city)

    #print(ants)
    #print(sorted(ants))

    #main loop
    for t in range(T):
        #pdb.set_trace()
        tours = [[]] * m
        for k in range(m):
            tours[k] = [ants[k]] # deep deep

        # compute tour for every ant
        for k in range(m):
            for _ in range(n-1):
                # visitied_cities = tours[k]
                #current_city = ants[k]
                probabilities = []
                for j in range(n):
                    if j not in tours[k]:
                        s = 0
                        for not_visited in set(range(n)) - set(tours[k]):
                            s += (feromone_trails[ants[k]][not_visited] ** alfa) * ((1/dist[ants[k]][j]) ** beta)

                        probabilities.append((j, ((feromone_trails[ants[k]][j] ** alfa) * ((1/dist[ants[k]][j]) ** beta))/s))

                #chosen_city = probabilities.index(max(probabilities)) # city with highest prob.
                #print(roulette(probabilities))
                #pdb.set_trace()
                chosen_city = roulette(probabilities)
                ants[k] = chosen_city
                tours[k].append(chosen_city)
                #pdb.set_trace()

        #pdb.set_trace()
        # update the best tour
        for tour in tours:
            l = eval(tour, dist)
            if l < length_shortest:
                shortest_tour = copy.deepcopy(tour) #deep
                length_shortest = l

        print(length_shortest)

        f.write(str(length_shortest) + "\n")
        f.flush()
        #pdb.set_trace()
        #global update for the pheromone trails
        new_feromone_trails = np.copy(feromone_trails)
        for i in range(n):
            for j in range(i+1, n):
                tk = []
                for k in range(m):
                    if abs(tours[k].index(i) - tours[k].index(j)) == 1:
                        tk.append(Q/eval(tours[k], dist))
                    else:
                        tk.append(0)


                delta = sum(tk)
                #pdb.set_trace()

                te = 0
                if abs(shortest_tour.index(i) - shortest_tour.index(j)) == 1:
                    te = Q/length_shortest

                #print("d: " + str(delta))
                #print("te: " + str(te))
                #pdb.set_trace()
                new_feromone_trails[i][j]  = (1-evaporate_rate)*feromone_trails[i][j] + delta + e*te

        feromone_trails = copy.deepcopy(new_feromone_trails)
        #print(feromone_trails)

    f.close()


