from mancalaboard import MancalaBoard
from copy import deepcopy
class Game:
    def __init__(self, mancalaBoard:MancalaBoard, player:int, move = None, heuristic = None):
        self.state = mancalaBoard
        self.playerSide = player
        self.heuristic = heuristic
        self.move = move
        self.replay = False

    def gameOver(self):
        if not self.state.possibleMoves(1):
            for fosse in MancalaBoard.fosse2:
                self.state.board['1'] += self.state.board[fosse]
                self.state.board[fosse] = 0
            return True
        if not self.state.possibleMoves(2):
            for fosse in MancalaBoard.fosse1:
                self.state.board['2'] += self.state.board[fosse]
                self.state.board[fosse] = 0
            return True
        return False

    def findWinner(self):
        if self.state.board['1'] > self.state.board['2']:
            return 1, self.state.board['1']
        else: 
            return 2, self.state.board['2']

    def evaluate(self):
        self.heuristic = self.state.board['2'] - self.state.board['1']
        return self.heuristic
    
    def ordered_children(self):
        children = []
        
        for move in self.state.possibleMoves(self.playerSide):
            clone_game = deepcopy(self)
            clone_game.playerSide = clone_game.state.doMove(self.playerSide, move)
            clone_game.move = move
            clone_game.evaluate()
            children.append(clone_game)

        rev = True if self.playerSide == 2 else False
        children.sort(key=lambda x: x.heuristic, reverse=rev)

        children = [game.move for game in children]
        return children
