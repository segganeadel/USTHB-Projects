from math import inf
from copy import deepcopy
from game import Game

class Play:
    def __init__(self):
        pass

    def humanTurn(state :Game, curent_player):
        
        print(state.state.possibleMove(curent_player))
        move = input("Selectionez parmis les choix :")
        
        curent_player = state.state.doMove(curent_player, move)
        return curent_player

    def computerTurn(game : Game, curent_player, depth = 6 ):
        if len(game.state.possibleMove(curent_player)) > 0:
            best_node = Play.NegaMaxAlphaBetaPruning(game, game.playerSide[curent_player], depth, game.alpha, game.beta)
            curent_player = game.state.doMove(curent_player, best_node[1])

        return curent_player, game


    def NegaMaxAlphaBetaPruning(self, game, player, depth, alpha, beta):
        if game.gameOver() or depth == 1:
            bestValue = game.evaluate()
            bestPit = None

            if player == 1:
                bestValue = - bestValue
            return bestValue, bestPit
        
        bestValue = -inf
        bestPit = None
        
        for pit in game.state.possibleMoves(game.playerSide[player]):
            pass
            child_game = deepcopy(game)
            child_game.state.doMove(game.playerSide[player], pit)
            value, _ = Play.NegaMaxAlphaBetaPruning (child_game, -player, depth-1, -beta, -alpha)
            value = - value
            if value > bestValue:
                bestValue = value
                bestPit =pit
            if bestValue > alpha:
                alpha = bestValue
            if beta <= alpha:
                break
        return bestValue, bestPit