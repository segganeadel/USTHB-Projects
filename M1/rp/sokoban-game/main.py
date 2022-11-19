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
boards= [board1,board2,board3,board4,board5]
boards1= [board6,board7,board8,board9]
boards += boards1
f = open("result.txt", "w")

for index,board in enumerate(boards):

        Game = sokoPuzzle.SokoPuzzle(board)
        deadlock = Game.deadlock_map()
        Snode = node.Node(Game)
        elapsed = time.perf_counter()

        #child , step = search.Search.breadthFirst(Snode)
        child , step = search.Search.A(Snode,3,deadlock)


        if child : route = child.moves
        else: route = "No route found"
        boardbench = "board"+str(index+1)+" = "+str(step)+"\n"
        f.write(boardbench)
        result ="board"+str(index+1)+" ,Number of steps is: " + str(step) +"\nRoute is: " + str(route)
        print(f"{elapsed:0.3f}")
        print(result)

f.close()