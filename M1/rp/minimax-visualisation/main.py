import pygame
import sys
from Tree import Tree

pygame.init()
screen = pygame.display.set_mode([500, 500])
# Run until the user asks to quit
running = True
while running:

    # Did the user click the window close button?
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Fill the background with white
    screen.fill((128, 128, 128))
    # Draw a solid blue circle in the center
    Tree.render()
    # Flip the display
    pygame.display.blit()

# Done! Time to quit.
pygame.quit()
sys.exit()