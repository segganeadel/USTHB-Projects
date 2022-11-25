import pygame
from pygame import gfxdraw,draw
from Proprities import WHITE,COLOR,RED,textFont
class Button:
    """Create a button, then blit the surface in the while loop"""
 
    def __init__(self, pos, text, surface):
        x, y = pos
        text_surface = textFont.render(text, True, WHITE)
        text_rect = text_surface.get_rect()
        text_rect.center = (x , y)
        box_rect = pygame.Rect((x , y),(300,60))
        box_rect.center = (x , y)
        self.box_rect = box_rect
        self.text_surface = text_surface
        self.text_rect = text_rect
        
    def draw(self,surface,color):
        gfxdraw.box(surface, self.box_rect, color)
        surface.blit(self.text_surface, self.text_rect)
        
  
def mainloop():
    """ The infinite loop where things happen """
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            button1.click(event)
        button1.show()
        clock.tick(30)
        pygame.display.update()