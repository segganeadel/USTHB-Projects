import numpy as np

class SokoPuzzle:
    def __init__(self,board):
        #height of board is number of lists
        self.height=len(board)
        #length of line
        self.width=len(board[0])


        #creating empty static matrix

        self.board_s = [[" " for _ in range(self.width)] for _ in range(self.height)]

        #creating dynamic matrix

        self.board_d = [[" " for _ in range(self.width)] for _ in range(self.height)]

        #moves
        self.moves = {"U":(-1,0),"D":(1,0),"L":(0,-1),"R":(0,1)}

        #splitting the board to dynamic and static
        for i in range(self.height):
            for j in range(self.width):
                # if wall or target or space add to static board
                if board[i][j] == 'O' or board[i][j]=='S' or board[i][j]==' ':
                    self.board_s[i][j]=board[i][j]
                # if robot get robot pos put and in dynamic board
                elif board[i][j] == 'R' :
                    self.robot_pos =(i,j)
                    self.board_d[i][j]='R'
                #if robot in target get robot pos put target in static and robot in dynamic
                elif board[i][j]=='.' :
                    self.robot_pos=(i,j)
                    self.board_s[i][j]='S'
                    self.board_d[i][j]='R'
                #if box in target put box in dynamic and target in static
                elif board[i][j] == "*":
                    self.board_d[i][j]="B"
                    self.board_s[i][j]="S"
                #if block put block in dynamic and space in static
                else:
                    self.board_s[i][j]=' '
                    self.board_d[i][j]='B'
        
    def isGoal(self):
        board_d = np.array(self.board_d)
        board_s = np.array(self.board_s)
  
        x,y=np.where(np.logical_and(board_s == "S",board_d != "B"))
        if x.any():
            return False
        return True

    def isGoal1(self):
        for i in range(self.height):
            for j in range(self.width):
                if self.board_s[i][j] == "S" and self.board_d[i][j] != "B":
                    return False
        return True


    def doMove(self,m):
        return self.where(self.moves[m])
   
    def where(self,direction):    
        r_x,r_y = self.robot_pos
        r_x+=direction[0]
        r_y+=direction[1]

        if self.board_s[r_x][r_y] == "O" :
            return False
        elif self.board_d[r_x][r_y] != "B":
            self.robot_pos=(r_x,r_y)
            self.board_d[r_x][r_y]="R"
            self.board_d[r_x-direction[0]][r_y-direction[1]]=" "
            return True
        elif self.board_d[r_x+direction[0]][r_y+direction[1]] != "B" and self.board_s[r_x+direction[0]][r_y+direction[1]] != "O":
            self.robot_pos=(r_x,r_y)
            self.board_d[r_x-direction[0]][r_y-direction[1]]=" "
            self.board_d[r_x][r_y]="R"
            self.board_d[r_x+direction[0]][r_y+direction[1]]="B"
            return True
        return False

    def deadlock_map(self):
        deadmap = [[" " for _ in range(self.width)] for _ in range(self.height)]
        for i in range(self.height):
            for j in range(self.width):
                if self.board_s[i][j] ==" ":
                    if (self.board_s[i+1][j] == "O" or self.board_s[i-1][j] == "O") and \
                     (self.board_s[i][j+1] == "O" or self.board_s[i][j-1] == "O"):
                        deadmap[i][j] = "C"
        deadnp = np.array(deadmap)
        x, y = np.where(deadnp == "C")
        locks = list(zip(x, y))
        while locks:
            start = locks.pop()
            for end in locks:
                
                if start[0] == end[0]:
                    up=True
                    down=True
                    step = 1 if start[1]<end[1] else -1
                    for j in range(start[1]+step,end[1],step):
                        if self.board_s[start[0]][j] != " " or self.board_s[start[0]-1][j] != "O":
                            up = False
                        if self.board_s[start[0]][j] != " " or self.board_s[start[0]+1][j] != "O":
                            down = False
                    if up or down:
                        for j in range(start[1]+step,end[1],step):
                            deadmap[start[0]][j]="L"
                
                if start[1] == end[1]:
                    left=True
                    right=True
                    step = 1 if start[0]<end[0] else -1
                    for i in range(start[0]+step,end[0],step):
                        if self.board_s[i][start[1]] != " " or self.board_s[i][start[1]-1] != "O":
                            left = False
                        if self.board_s[i][start[1]] != " " or self.board_s[i][start[1]+1] != "O":
                            right = False
                    if left or right:
                        for i in range(start[0]+step,end[0],step):
                            deadmap[i][start[1]]="L"
                
        return deadmap

    def isLock(self,deadmap):
        deadlock = np.array(deadmap)
        board_d = np.array(self.board_d)
        x,y=np.where(np.logical_and(np.logical_or(deadlock == "C",deadlock == "L"),board_d == "B"))
        if x.any():
            return True
        return False






                    



