import random

N_QUEENS = 8
POPULATION_SIZE = 100
MUTATE_FLAG = True
MUTATE_PROB = 0.1
MAX_ITER = 500



class Chromosome:
    def __init__(self, seq = None):
        if seq == None : # Creation of a new chromosome in the initial population
            self.sequence = list()
            for i in range(N_QUEENS):
                self.sequence.append(random.randint(0, N_QUEENS-1))
        else: # Creation of a new chromosome with crossover
            self.sequence = seq
        self.fitness = None


    def setFitness(self):

        # Number of horizontal collisions
        horizontal_collisions = 0
        for i in range(0, N_QUEENS-1):
            for j in range(i+1, N_QUEENS):
                if self.sequence[i] == self.sequence[j]:
                    horizontal_collisions += 1
        
        # Number of diagonal collisions
        diagonal_collisions = 0
        for i in range(0, N_QUEENS-1):
            for j in range(i+1, N_QUEENS-1):
                if abs(i-j) == abs(self.sequence[i]-self.sequence[j]):
                    diagonal_collisions += 1
        # for 8x8 chess: fitness = 28 – (number of collisions)
        self.fitness = (N_QUEENS*( N_QUEENS-1)/2) - (horizontal_collisions + diagonal_collisions)


    def mutate(self):
        p = random.random()
        if p < MUTATE_PROB:
            col = random.randint(0, N_QUEENS-1)
            self.sequence[col] = random.randint(0, N_QUEENS-1)

chromosome = Chromosome()
chromosome.setFitness()
print(chromosome.sequence,chromosome.fitness)

