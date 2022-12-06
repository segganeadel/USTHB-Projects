import numpy as np

class MancalaBoard:
    def __init__(self):
        self.board={"A":4, "B":4, "C":4, "D":4, "E":4, "F":4,
                    "G":4, "H":4, "I":4, "J":4, "K":4, "L":4,
                    1:0, 2:0}

        self.fosses1=('A', 'B', 'C', 'D', 'E', 'F')

        self.fosses2=('G', 'H', 'I', 'J', 'K', 'L')

        self.next = {'A':'B', 'B':'C', 'C':'D', 'D':'E', 'E':'F', 'F':'1', '1':'L', 
                     'L':'K', 'K':'J', 'J':'I', 'I':'H', 'H':'G','G':'2', '2':'A'}

        self.opposite = {'A':'G', 'B':'H', 'C':'I', 'D':'J', 'E':'K','F':'L', 
                         'G':'A', 'H':'B', 'I':'C', 'J':'D','K':'E', 'L':'F'}

    def getBoard(self):
        return self.board
    
    def getFosses1(self):
        return self.fosses1
    
    def getFosses2(self):
        return self.fosses2
    

    # mouvements possibles
    # retourne une list des codes ASCII des fosses
    def possibleMoves(board):
        possibleMoves = []
        for i in range(ord('A'), ord('L')+1):
            if board[chr(i)] !=0:
                possibleMoves.append(chr(i))

        return possibleMoves

    def doMove(self, player, position):
        graines = self.board[position]

        # si au moins une graine se trouve dans une fosse
        while graines > 0:
            position = self.next[position] 

            # si le point de départ est le magasin
            if (player == '1' and position == '2') or (player == '2' and position == '1'):
                continue
            self.board[position] += 1
            graines -= 1

            # si on a fini dans une fosse fiha zero 
            if player == '1' and position in self.fosses1 and self.board[position] == 1:
                oppositePosition = self.opposite[position]
                self.board['1'] += self.board[oppositePosition]+1
                self.board[oppositePosition] = 0
                self.board[position] = 0

            if player == '2' and position in self.fosses2 and self.board[position] == 1:
                oppositePit = self.opposite[position]
                self.board['2'] += self.board[oppositePosition]+1
                self.board[oppositePosition] = 0 
                self.board[position] = 0

            if (position == player == '1') or (position == player == '2'):
                return player
            if player == '1':
                return '2'
            elif player == '2':
                return '1'