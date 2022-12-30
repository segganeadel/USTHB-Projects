from math import inf
from copy import deepcopy
from game import Game
from mancalaboard import MancalaBoard
class Play:
    @staticmethod
    def humanTurn(game:Game):
        print(game.state)
        print(game.state.possibleMoves(1))
        #best_node = input("Selectionez parmis les choix :") 
        bestValue, best_node = Play.MiniMaxAlphaBeta2(game,5 , -inf, inf) 
        print("Human Player played: ", best_node)
        game.playerSide = game.state.doMove(1, best_node)
        print(game.playerSide)
        return game

    @staticmethod
    def computerTurn(game : Game, depth = 3 ):
        print(game.state)
        print(game.state.possibleMoves(2))
        bestValue, best_node ,iterations= Play.MiniMaxAlphaBeta(game, depth, -inf, inf)
        print("Computer played: ", best_node, "in iterations: ", iterations)
        game.playerSide = game.state.doMove(2, best_node)
        print(game.playerSide)
        return game

    @staticmethod
    def MiniMaxAlphaBeta(game:Game, depth:int, alpha:int, beta:int):
        iterations = 0
        if game.gameOver() or depth == 0:
            bestValue = game.evaluate()
            bestPit = None
            iterations += 1
            return bestValue, bestPit , iterations

        maximizer = True if game.playerSide == 2 else False

        bestValue = -inf if maximizer else inf
        bestPit = None

        for pit in game.state.possibleMoves(game.playerSide):
            child_game:Game = deepcopy(game)
            child_game.playerSide = child_game.state.doMove(game.playerSide, pit)
            value, _ , iterations= Play.MiniMaxAlphaBeta(child_game, depth-1, alpha, beta)
            iterations += 1

            if maximizer:
                if value > bestValue:
                    bestValue = value
                    bestPit = pit
                alpha = max(alpha, bestValue)
            else:
                if value < bestValue:
                    bestValue = value
                    bestPit = pit
                beta = min(beta, bestValue)
                
            if beta <= alpha:
                return bestValue, bestPit , iterations
        return bestValue, bestPit , iterations
   
    @staticmethod
    def MiniMaxAlphaBeta2(game:Game, depth:int, alpha:int, beta:int) -> int:

        if game.gameOver() or depth == 0:
            bestValue = game.evaluate()
            bestPit = None
            return bestValue, bestPit

        maximizer = True if game.playerSide == 2 else False

        bestValue = -inf if maximizer else inf
        bestPit = None

        children = game.ordered_children()
        for pit in children:
            child_game:Game = deepcopy(game)
            child_game.playerSide = child_game.state.doMove(game.playerSide, pit)
            value, _ = Play.MiniMaxAlphaBeta2(child_game, depth-1, alpha, beta)
            if maximizer:
                if value > bestValue:
                    bestValue = value
                    bestPit = pit
                alpha = max(alpha, bestValue)
            else:
                if value < bestValue:
                    bestValue = value
                    bestPit = pit
                beta = min(beta, bestValue)
                
            if beta <= alpha:
                return bestValue, bestPit
        return bestValue, bestPit
 