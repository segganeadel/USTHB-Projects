from math import inf,log2,floor
from Node import Node
import pygame
from Proprities import SPEED,SIZE,WHITE,RED,textFont
import sys
import time
from Button import Button

MAX = 1
MIN = -1


def MiniMax(node:Node, player:int, depth:int,surface): # Initial depth is 5

    checkEvent()
    time.sleep(SPEED)

    if depth == 1:
        # Display the current node’s value and mark it as explored
        node.visited(surface)
        #node.displayValue(surface)
    else:
        # Mark the current node as explored
        node.visited(surface)
        listChildren = [node.leftChild, node.rightChild]
        
        if player == MAX: # MAX = +1
            bestValue = -inf
            bestPath = None

            for child in listChildren:
                # Mark the link between the current node and the child node as explored
                child.visited_link(surface,node)
                # Apply the MiniMax function on each child
                MiniMax(child, -player, depth-1,surface) 
                if child.value > bestValue:
                    bestValue = child.value
                    bestPath = child

        else: # if the player is MIN (MIN = -1)
            bestValue = +inf
            bestPath = None
            for child in listChildren:
                # Mark the link between the current node and the child node as explored
                child.visited_link(surface,node)
                # Apply the MiniMax function on each child
                MiniMax(child, -player, depth-1,surface) 
                if child.value < bestValue:
                    bestValue = child.value
                    bestPath = child

        node.value = bestValue
        node.path = bestPath
        # Display the best path and the current node’s value
        node.route(surface,node.path)

        return bestValue


def NegaMax(node:Node, player:int, depth:int,surface): # Initial depth is 5
    
    checkEvent()
    time.sleep(SPEED)

    if depth == 1:
        if player == MIN:
            node.value = -node.value
        # Display the current node’s value and mark it as explored
        node.visited(surface)
    else:
        # Mark the current node as explored
        node.visited(surface)
        listChildren = [node.leftChild, node.rightChild]
        bestValue = -inf
        bestPath = None
        for child in listChildren:
            # Mark the link between the current node and the child node as explored
            child.visited_link(surface,node)
            NegaMax (child, -player, depth-1,surface) # Apply the NegaMax function on each child
            child.value = -child.value
            if child.value > bestValue:
                bestValue = child.value
                bestPath = child
        node.value = bestValue
        node.path = bestPath
        # Display the best path and the current node’s value
        node.route(surface,node.path,True)
        

def NegaMaxAlphaBetaPruning(node:Node, player:int, depth:int, alpha:int, beta:int,surface):

    checkEvent()
    time.sleep(SPEED)

    node.alpha = alpha
    node.beta = beta

    # Initially, depth=5, alpha=-inf and beta=+inf
    if depth == 1:

        if player == MIN:
            node.value = -node.value
        # Display the current node’s value and mark it as explored
        node.visited(surface)
        # Display the values of alpha and beta
        Node.displayAlphaBetaLast(surface,node,alpha,beta)
    else:
        # Mark the current node as explored
        node.visited(surface)
        # Display the values of alpha and beta

        listChildren = [node.leftChild, node.rightChild]
        bestValue = -inf
        bestPath = None
        for child in listChildren:
            # Mark the link between the current node and the child node as explored
            child.visited_link(surface,node)

            NegaMaxAlphaBetaPruning(child, -player, depth-1, -beta, -alpha,surface)
            child.value = -child.value
            if child.value > bestValue:
                bestValue = child.value
                bestPath = child
            if bestValue > alpha:
                alpha = bestValue
                # Display the new value of alpha
                Node.displayAlphaBeta(surface,node,alpha,beta)
            if beta <= alpha:
                break
        node.value = bestValue
        node.path = bestPath
        # Display the best path and the current node’s value
        node.route(surface,node.path,True)


def checkEvent():
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
            

def valueToNode(values:list,surface,SIZE):

    stepH = SIZE[0]//(len(values)+2)
    depth = floor(log2(len(values)+1))
    stepV = SIZE[1]//(depth+3)

    x=2*stepH
    y=SIZE[1]-2*stepV

    nodes=[]
    for value in values:
        node=Node(value=value,x=x,y=y)
        node.draw_initial(surface,stepV)
        nodes.append(node)
        x+=stepH
        pygame.display.flip()
    return nodes,stepH,stepV,depth+1



def buildTree(nodes:list,surface,stepV:int,stepH:int,player):
    if (len (nodes) != 1):
        newNodes=[]
        root=[]


        if player == -1:
            text = "MIN"
        else:
            text = "MAX"
        text_surface = textFont.render(text, True, WHITE)
        text_rect = text_surface.get_rect()
        text_rect.center = (stepH, nodes[0].position[1])
        surface.blit(text_surface, text_rect)


        while nodes:
            leftChild:Node = nodes.pop(0)
            rightChild:Node = nodes.pop(0)
            parent = Node(leftChild,rightChild)
            parent.position=((leftChild.position[0]+rightChild.position[0])//2,leftChild.position[1]-stepV)
            newNodes.append(parent)

            leftChild.draw_link(surface,parent)
            rightChild.draw_link(surface,parent)
            leftChild.draw_noeud(surface)
            rightChild.draw_noeud(surface)
        root = buildTree(newNodes,surface,stepV,stepH,-player)
        return root
    if player == -1:
        text = "MIN"
    else:
        text = "MAX"
    text_surface = textFont.render(text, True, WHITE)
    text_rect = text_surface.get_rect()
    text_rect.center = (stepH, nodes[0].position[1])
    surface.blit(text_surface, text_rect)

    nodes[0].draw_noeud(surface)
    pygame.display.flip()
    return nodes[0]


def init(player,intialValues:list,surface) :
    intialNodes,stepH,stepV,depth = valueToNode(intialValues,surface,SIZE)
    root = buildTree(intialNodes,surface,stepV,stepH,player)
    return root,depth

def keepLoop(surface):
    button0 = button0 = Button((1200,100),"Return",surface)
    button0.draw(surface,RED)
    pygame.display.flip()
    loop = True
    clock = pygame.time.Clock()
    while loop:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if pygame.mouse.get_pressed()[0]:
                x, y = pygame.mouse.get_pos()
                if button0.box_rect.collidepoint(x, y):
                    loop = False
        clock.tick(60)