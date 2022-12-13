from mancalaboard import MancalaBoard
class Game:
    def __init__(self, mancalaBoard:MancalaBoard, player:int):
        self.state = mancalaBoard
        self.playerSide = player

    def gameOver(self):
        if not self.state.possibleMoves(1):
            for fosse in MancalaBoard.fosses2():
                self.state.board['1'] += self.state.board[fosse]
                self.state.board[fosse] = 0
            return True
        elif not self.state.possibleMoves(2):
            for fosse in MancalaBoard.fosses1():
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
        return self.state.board['1'] - self.state.board['2']
