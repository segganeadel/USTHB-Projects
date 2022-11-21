import pygame
import sys
import Proprities
import Algorithms
from math import inf

MAX, MIN = 1, -1
SIZE = 1400, 800


pygame.init()
surface = pygame.display.set_mode(SIZE)
surface.fill((128, 128, 128))

alpha = -inf
beta = +inf

player=MIN


intialValues = [10, 5, 7, 11, 12, 8, 9, 8, 5, 12, 11, 12, 9, 8, 7, 10]
#intialValues = [10, 5, 7, 11, 12, 8, 9, 8]
intialNodes,stepH,stepV,depth = Algorithms.valueToNode(intialValues,surface,SIZE,player)
root = Algorithms.buildTree(intialNodes,surface,stepV,stepH,player)
root = root.pop()
print(type(root))
print(root.leftChild.position)
print(root.leftChild.leftChild.position)

#Algorithms.MiniMax(root,player,depth,surface)
Algorithms.NegaMax(root,player,depth,surface)
#Algorithms.NegaMaxAlphaBetaPruning(root,player,depth,alpha,beta,surface)


launch = True
while launch:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            launch = False
            pygame.quit()
            sys.exit()

