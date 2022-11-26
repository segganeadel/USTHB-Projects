import pygame
from pygame import time
import sys
from Proprities import GRAY,SIZE,RED,BLACK
import Algorithms
from Button import Button
from math import inf

MAX, MIN = 1, -1
alpha = -inf
beta = +inf

player=MAX

intialValues = [10, 5, 7, 11, 12, 8, 9, 8, 5, 12, 11, 12, 9, 8, 7, 10]



pygame.init()
clock = pygame.time.Clock()
surface = pygame.display.set_mode(SIZE)
surface.fill(GRAY)

""" 
pygame.display.flip()

 """

#root,depth = Algorithms.init(player,intialValues,surface)
#Algorithms.MiniMax(root,player,depth,surface)
#Algorithms.NegaMax(root,player,depth,surface)
#Algorithms.NegaMaxAlphaBetaPruning(root,player,depth,alpha,beta,surface)





button0 = Button((300,200),"Switch player : MAX",surface)
button1 = Button((700,300),"Minimax",surface)
button2 = Button((700,400),"Negamax",surface)
button3 = Button((700,500),"Negamax Alpha-beta Pruning",surface)


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if pygame.mouse.get_pressed()[0]:
            x, y = pygame.mouse.get_pos()
            if button0.box_rect.collidepoint(x, y):
                player = -player
                if player == 1:
                    button0 = Button((300,200),"Switch player : MAX",surface)
                else :
                    button0 = Button((300,200),"Switch player : MIN",surface)
                #switch player
                pass
            if button1.box_rect.collidepoint(x, y):
                surface.fill(GRAY)
                root,depth = Algorithms.init(player,intialValues,surface)
                Algorithms.MiniMax(root,player,depth,surface)
                Algorithms.keepLoop(surface)
            
            if button2.box_rect.collidepoint(x, y):
                surface.fill(GRAY)
                root,depth = Algorithms.init(player,intialValues,surface)
                Algorithms.NegaMax(root,player,depth,surface)
                Algorithms.keepLoop(surface)

            if button3.box_rect.collidepoint(x, y):
                surface.fill(GRAY)
                root,depth = Algorithms.init(player,intialValues,surface)
                Algorithms.NegaMaxAlphaBetaPruning(root,player,depth,alpha,beta,surface)
                Algorithms.keepLoop(surface)

    surface.fill(GRAY)
    button0.draw(surface,BLACK)
    button1.draw(surface,RED)
    button2.draw(surface,RED)
    button3.draw(surface,RED)
    pygame.display.flip()
    clock.tick(60)
