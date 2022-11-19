from math import inf


MAX = 1
MIN = -1


def MiniMax(node, player:int, depth:int): # Initial depth is 5
    if (depth == 1):
        # Display the current node’s value and mark it as explored
        pass
    else:
        # Mark the current node as explored
        pass
        listChildren = [node.leftChild, node.rightChild]
        
        if (player == MAX): # MAX = +1
            bestValue = -inf
            bestPath = None
            for child in listChildren:
                pass
                # Mark the link between the current node and the child node as explored
                MiniMax(child, -player, depth-1) # Apply the MiniMax function on each child
                if child.value > bestValue:
                    bestValue = child.value
                    bestPath = child

        else: # if the player is MIN (MIN = -1)
            bestValue = +inf
            bestPath = None
            for child in listChildren:
                pass
                # Mark the link between the current node and the child node as explored4
                MiniMax(child, -player, depth-1) # Apply the MiniMax function on each child
                if child.value < bestValue:
                    bestValue = child.value
                    bestPath = child

    node.value = bestValue
    node.path = bestPath
    # Display the best path and the current node’s value


def NegaMax(node, player, depth): # Initial depth is 5

    if depth == 1:
        if player == MIN:
            node.value = -node.value
        # Display the current node’s value and mark it as explored
    else:
        # Mark the current node as explored
        listChildren = [node.leftChild, node.rightChild]
        bestValue = -inf
        bestPath = None
        for child in listChildren:
            # Mark the link between the current node and the child node as explored
            NegaMax (child, -player, depth-1) # Apply the NegaMax function on each child
            child.value = -child.value
            if child.value > bestValue:
                bestValue = child.value
                bestPath = child
    node.value = bestValue
    node.path = bestPath
    # Display the best path and the current node’s value

def NegaMaxAlphaBetaPruning(node, player, depth, alpha, beta):
    # Initially, depth=5, alpha=-inf and beta=+inf
    if depth == 1:
        if player == MIN:
            node.value = - node.value
        # Display the current node’s value and mark it as explored
        # Display the values of alpha and beta
    else:
        # Mark the current node as explored
        # Display the values of alpha and beta
        listChildren = [node.leftChild, node.rightChild]
        bestValue = -inf
        bestPath = None
        for child in listChildren:
            # Mark the link between the current node and the child node as explored
            NegaMaxAlphaBetaPruning(child, -player, depth-1, -beta, -alpha)
            child.value = -child.value
            if child.value > bestValue:
                bestValue = child.value
                bestPath = child
            if bestValue > alpha:
                alpha = bestValue
                # Display the new value of alpha
            if beta <= alpha:
                break
    node.value = bestValue
    node.path = bestPath
    # Display the best path and the current node’s value