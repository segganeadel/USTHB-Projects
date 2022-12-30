from mancalaboard import MancalaBoard
from game import Game
from play import Play

board = MancalaBoard()
game = Game(board, 2)


print(game.state.possibleMoves(1))
print(game.state.possibleMoves(2))
print(game.gameOver())

while(not game.gameOver()):
    if game.playerSide == 1: 
        game = Play.humanTurn(game)
    else:
        game = Play.computerTurn(game)

print("winner is Player: ",game.findWinner())
print(game.state)


