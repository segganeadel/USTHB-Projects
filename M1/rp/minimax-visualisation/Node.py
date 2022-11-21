from math import inf
import pygame
from pygame import gfxdraw,draw
import time
from Proprities import RAYON,SPEED,EXPLORED_COLOR,SUCCESS_COLOR,COLOR,textFont,MainFont,titleFont


class Node:
    def __init__(self,leftChild=None,rightChild=None,value=None,path=None,x=0,y=0):
        self.leftChild=leftChild
        self.rightChild=rightChild
        self.value=value
        self.path=path
        self.position = (x,y)
        self.alpha = -inf
        self.beta = +inf

    def draw_noeud(self,surface):
        x, y = self.position
        gfxdraw.filled_circle(surface, x, y, RAYON, COLOR)

        """
        if self.value is not None:
            text = f"{self.value}"
            text_surface = textFont.render(text, True, (255, 255, 255))
            text_rect = text_surface.get_rect()
            text_rect.center = (x, y)
            surface.blit(text_surface, text_rect)
        """

    def draw_link(self,surface,parent):
        x1, y1 = self.position
        x2, y2 = parent.position
        draw.line(surface,COLOR, (x1,y1), (x2,y2), 5 )

    def draw_initial(self,surface,stepV):
        x, y = self.position
        x, y = x , y+(stepV//1.7)
        rect = pygame.Rect((x,y) , (50,50))
        rect.center = (x , y)
        gfxdraw.box(surface, rect, COLOR)
        if self.value is not None:
            text = f"{self.value}"
            text_surface = textFont.render(text, True, (255, 255, 255))
            text_rect = text_surface.get_rect()
            text_rect.center = (x , y)
            surface.blit(text_surface, text_rect)

    def visited(self,surface):
        x, y = self.position
        gfxdraw.filled_circle(surface, x, y, RAYON, EXPLORED_COLOR)
        self.displayValue(surface)
        pygame.display.flip()

    def chosen(self,surface):
        x, y = self.position
        gfxdraw.filled_circle(surface, x, y, RAYON, SUCCESS_COLOR)
        self.displayValue(surface)
        pygame.display.flip()

    def visited_link(self,surface, parent):
        x1, y1 = self.position
        x2, y2 = parent.position
        draw.line(surface,EXPLORED_COLOR, (x1,y1), (x2,y2), 5 )
        self.visited(surface)
        parent.visited(surface)
        pygame.display.flip()

    def route(self,surface, parent):
        x1, y1 = self.position
        x2, y2 = parent.position
        draw.line(surface,SUCCESS_COLOR, (x1,y1), (x2,y2), 5 )
        self.chosen(surface)
        parent.chosen(surface)
        pygame.display.flip()


    def displayValue(self,surface):  
        if self.value is not None:
            text = f"{self.value}"
            text_surface = textFont.render(text, False, (255, 255, 255))        
            text_rect = text_surface.get_rect()
            text_rect.center = (self.position[0], self.position[1])
            surface.blit(text_surface, text_rect)
            pygame.display.flip()

    @staticmethod
    def displayAlphaBeta(surface, noeud):
        CURRENT_COLOR = SUCCESS_COLOR if noeud.alpha != float(
            '-inf') else GRAY_COLOR
        CURRENT_COLOR_B = SUCCESS_COLOR_B if noeud.beta != float(
            'inf') else GRAY_COLOR

        x, y = noeud.position
        text = f"A : {noeud.alpha}"
        text_font = pygame.font.SysFont("Comic Sans MS", 15)
        text_render = text_font.render(text, False, CURRENT_COLOR)
        surface.blit(text_render, (x-20, y-RAYON-40))

        text = f"B : {noeud.beta}"
        text_font = pygame.font.SysFont("Comic Sans MS", 15)
        text_render = text_font.render(text, False, CURRENT_COLOR_B)
        surface.blit(text_render, (x-20, y-RAYON-25))

        time.sleep(SPEED)
        pygame.display.flip()


