import pygame
# ----------------Settings----------------
title, ScreenWidth, ScreenHeight = 'Game Algorithms', 1000, 700
startHeight = 180  # distance y between each node
SPEED = 0.3
quick = True
depth = 80  # distance y between each node
RAYON = 30  # Node Radius
interval = (0, 30)  # Node value Random interval

GRAY = (128, 128, 128)

# ----------------Texts and colors----------------
pygame.font.init()
textFont = pygame.font.SysFont('Arial', 20)
titleFont = pygame.font.SysFont('Arial', 25)
MainFont = pygame.font.SysFont('Arial', 40, bold=True)
colors = [
    # if state -1 then node is invisible
    (100, 100, 100),  # non visité (default)
    (55, 70, 80),  # visité
    (178, 34, 34)  # rouge
]

COLOR = colors[0]
EXPLORED_COLOR = colors[1]
SUCCESS_COLOR = colors[2]

# ----------------Algorithms----------------
MinMaxText, MAX, MIN = [
    'MAX',
    'MIN'
], 0, 1

MinMaxStart = MIN  # MAX or MIN
