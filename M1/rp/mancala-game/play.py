import math

class Play:
    def __init__(self):
        pass

    def humanTurn(self):
        pass

    def computerTurn(self):
        pass

    def negaMaxAlphaBetaPruning(self, game, player, depth, alpha, beta):
        if game.gameOver() or depth == 1:
            bestValue = game.evaluate()
            bestPit = None
            if player == 1:
                bestValue = - bestValue

            return bestValue, bestPit
        
        bestValue = -math.inf
        bestPit = None
        
        for pit in game.state.possibleMoves(game.playerSide[player]):
            pass
    

    def negaMax(self, game, player, depth):
        pass