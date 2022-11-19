import pygame, sys
from pygame.locals import *
import search
import node
import sokoPuzzle
import time
import numpy as np


board1 = [['O', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'S', ' ', 'B', ' ', 'O'],
        ['O', ' ', 'O', 'R', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O']]

board2 = [['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O'],
        ['O', ' ', ' ', 'O', 'O', 'O', ' ', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', 'O', '.', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', ' ', 'O', ' ', 'O'],
        ['O', ' ', ' ', 'B', ' ', ' ', 'O', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', ' ', 'O', ' ', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]

board3 = [['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', ' ', ' ', ' ', 'O', ' ', ' ', 'O'],
        ['O', ' ', ' ', 'B', 'R', ' ', ' ', 'O'],
        ['O', ' ', ' ', ' ', 'O', 'B', ' ', 'O'],
        ['O', 'O', 'O', 'O', 'O', ' ', 'S', 'O'],
        ['O', 'O', 'O', 'O', 'O', ' ', 'S', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]

board4 = [['O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'O', ' ', ' ', 'O', 'O', 'O'],
        ['O', 'O', ' ', ' ', 'O', 'O', 'O'],
        ['O', 'O', ' ', '*', ' ', ' ', 'O'],
        ['O', 'O', 'B', 'O', 'B', ' ', 'O'],
        ['O', ' ', 'S', 'R', 'S', ' ', 'O'],
        ['O', ' ', ' ', ' ', ' ', 'O', 'O'],
        ['O', 'O', 'O', ' ', ' ', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O']]

board5 = [['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'S', 'O', ' ', ' ', 'O', 'O'],
        ['O', ' ', ' ', ' ', ' ', 'B', ' ', 'O', 'O'],
        ['O', ' ', 'B', ' ', 'R', ' ', ' ', 'S', 'O'],
        ['O', 'O', 'O', ' ', 'O', ' ', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'B', 'O', ' ', 'O', 'O', 'O'],
        ['O', 'O', 'O', ' ', ' ', 'S', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]

board6 = [
        ['O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'S', ' ', 'O', ' ', 'R', 'O'],
        ['O', ' ', ' ', 'O', 'B', ' ', 'O'],
        ['O', 'S', ' ', ' ', 'B', ' ', 'O'],
        ['O', ' ', ' ', 'O', 'B', ' ', 'O'],
        ['O', 'S', ' ', 'O', ' ', ' ', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O']]

board7 = [
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'S', 'S', 'S', ' ', 'O', 'O', 'O'],
        ['O', ' ', 'S', ' ', 'B', ' ', ' ', 'O'],
        ['O', ' ', ' ', 'B', 'B', 'B', ' ', 'O'],
        ['O', 'O', 'O', 'O', ' ', ' ', 'R', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]

board8 = [
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', ' ', ' ', ' ', ' ', 'O', 'O', 'O'],
        ['O', ' ', ' ', ' ', 'B', ' ', ' ', 'O'],
        ['O', 'S', 'S', 'S', '*', 'B', 'R', 'O'],
        ['O', ' ', ' ', ' ', 'B', ' ', ' ', 'O'],
        ['O', ' ', ' ', ' ', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]

board9 = [
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'S', ' ', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', ' ', ' ', 'O', 'O', 'O', 'O'],
        ['O', 'S', ' ', 'S', ' ', 'O', 'O', 'O', 'O'],
        ['O', ' ', 'B', ' ', 'B', 'B', ' ', ' ', 'O'],
        ['O', 'O', 'O', 'S', ' ', ' ', 'B', 'R', 'O'],
        ['O', 'O', 'O', ' ', ' ', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]


Game = sokoPuzzle.SokoPuzzle(board6)
deadlock = Game.deadlock_map()
print(np.array(Game.board_s))
print(np.array(deadlock))
Snode = node.Node(Game)
elapsed = time.perf_counter()

#child , step = search.Search.breadthFirst(Snode)
child , step = search.Search.A(Snode,3,deadlock)


if child : 
    route = child.moves
    states = child.getSolution()
else: route = "No route found"
result ="Number of steps is: " + str(step) +"\nRoute is: " + str(route)
print(f"{elapsed:0.3f}")
print(result)


               
def render(surface, board_d, board_s, board_dead):
    for row_index, row in enumerate(board_d):
        for col_index, column in enumerate(row):
            position_x = (col_index+1)*64
            position_y = (row_index+1)*64


            loaded = pygame.image.load(asset[" "]).convert_alpha()
            surface.blit(loaded, (position_x, position_y))            
            loaded = pygame.image.load(asset[board_s[row_index][col_index]]).convert_alpha()
            surface.blit(loaded, (position_x, position_y))            
            if board_dead[row_index][col_index] != " ":
                loaded = pygame.image.load(asset[board_dead[row_index][col_index]]).convert_alpha()
                surface.blit(loaded, (position_x, position_y))
            if column != " ":
                loaded = pygame.image.load(asset[board_d[row_index][col_index]]).convert_alpha()
                surface.blit(loaded, (position_x, position_y))

asset = {
    "R":   "./Assets/player.png",
    "O":   "./Assets/wall.png",
    " ":   "./Assets/ground.png",
    "S":   "./Assets/target.png",
    "B":   "./Assets/box.png",
    "*":   "./Assets/targetfull.png",
    "C":   "./Assets/deadlockcoin.png",
    "L":   "./Assets/deadlockline.png",
    ".":   "./Assets/player.png"
}


pygame.init()
DISPLAYSURF = pygame.display.set_mode((64*(len(Game.board_d[0])+2),64*(len(Game.board_d)+2)))
pygame.display.set_caption('Sokoban AI')
DISPLAYSURF.fill((0, 0, 0))

text = f"Steps : {step} Moves : {len(route)}"
text_font = pygame.font.SysFont("arial", 30)
text_render = text_font.render(text, False, (255, 255, 255))

i=0
while True: # main game loop
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    render(DISPLAYSURF, states[i], Game.board_s,deadlock)
    pygame.display.flip()
    if i<len(states)-1:i+=1
    DISPLAYSURF.blit(text_render, (10, 10))
    time.sleep(0.4)    
    pygame.display.update()
