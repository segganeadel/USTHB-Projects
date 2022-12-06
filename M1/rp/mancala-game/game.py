class Game:
    def __init__(self, mancalaBoard, player):
        self.state = mancalaBoard
        self.playerSide = player

    def gameOver(self):
        gameOver = True

        # si des graines restent dans la fosse du joueur 1 
        for fosse in self.state.getFosses1():
                if self.state.board[fosse] != 0:
                    gameOver = False
                    break

        # transferer les graines
        if gameOver:
                for fosse in self.state.getFosses2():
                    self.state.board[2] += self.state.board[fosse]
                    self.state.board[fosse] = 0                     
                return gameOver

        # si des graines restent dans la fosse du joueur 2    
        for fosse in self.state.getFosses2():
                if self.state.board[fosse] != 0:
                    gameOver = False
                    break

        if gameOver:
                for fosse in self.state.getFosses1():
                    self.state.board[1] += self.state.board[fosse]
                    self.state.board[fosse] = 0                     
                return gameOver

        return False

    def findWinner(self):
        if self.state.board[1] > self.state.board[2]:
            return 1, self.state.board[1]
        else: 
            return 2, self.state.board[2]

    def evaluate(self):
        return self.state.board[1] - self.state.board[2]
