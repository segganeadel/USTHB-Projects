from collections import deque
import numpy as np

class Search:

    

    """ Uninformed/Blind Search """
    @staticmethod
    def breadthFirst(initial_node,deadlock=None):
        deadmaps=[]
        # Check if the start element is the goal
        if initial_node.state.isGoal():
            return initial_node, 0

        # Create the OPEN FIFO queue and the CLOSED list
        open = deque([initial_node]) # A FIFO queue
        closed = list()

        step = 0
        while True:
            #print (f'*** Step {step} ***')
            step +=1
            
            # Check if the OPEN queue is empty => goal not found 
            if len(open) == 0:
                return None, -1
            
            # Get the first element of the OPEN queue
            current = open.popleft()


            # Put the current node in the CLOSED list
            closed.append(current)

            # Generate the successors of the current node
            succ = current.succ()
            while succ:
                child = succ.popleft()

                if deadlock and child.state.board_d not in deadmaps and child.state.isLock(deadlock):
                        deadmaps.append(child.state.board_d)
                        continue

                # Check if the child is not in the OPEN queue and the CLOSED list
                if (child.state.board_d not in [n.state.board_d for n in closed] and \
                    child.state.board_d not in [n.state.board_d for n in open]):

                    # Put the child in the OPEN queue 
                    open.append(child)    

                    # Check if the child is the goal
                    if child.state.isGoal():
                        #print (f'*** Step {step} ***')
                        print ("Goal reached")
                        return child, step   

    @staticmethod
    def A(initial_node, heuristic=1,deadlock=None):
        deadmaps=[]
        # Check if the start element is the goal
        if initial_node.state.isGoal():
            return initial_node, 0

        # Create the OPEN FIFO queue and the CLOSED list
        initial_node.costHeur(heuristic)

        open = [initial_node]
        closed = list()

        step = 0
        while True:
            #print (f'*** Step {step} ***')
            step += 1

            # Check if the OPEN queue is empty => goal not found 
            if len(open) == 0:
                return None, -1
        
            #calculate node with least heuristic
            current = min(open, key=lambda x: x.costH)

            # if child.state.isGoal():
            # return child, step


            open.remove(current)
            # Put the current node in the CLOSED list
            closed.append(current)

            if current.state.isGoal():
                print ("Goal reached") 
                return current, step 

            if deadlock and current.state.board_d not in deadmaps and current.state.isLock(deadlock):
                deadmaps.append(current.state.board_d)
                continue
            # Generate the successors of the current node
            succ = current.succ()

            while succ:
                child = succ.popleft()
                 
                child.costHeur(heuristic)

                if child.state.board_d in [n.state.board_d for n in open]:
                    index = [n.state.board_d for n in open].index(child.state.board_d)
                    if open[index].costH > child.costH:
                        open.remove(open[index])
                        open.append(child) 

                elif child.state.board_d in [n.state.board_d for n in closed]:
                    index = [n.state.board_d for n in closed].index(child.state.board_d)
                    if closed[index].costH > child.costH:
                        closed.remove(closed[index])
                        open.append(child)

                else: open.append(child)






