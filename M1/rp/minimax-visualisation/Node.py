from math import inf
import pygame
from pygame import gfxdraw,draw
from Proprities import RADIUS,EXPLORED,RED,COLOR,GRAY,WHITE,textFont,alphaFont


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
        gfxdraw.filled_circle(surface, x, y, RADIUS, COLOR)

    def draw_link(self,surface,parent):
        x1, y1 = self.position
        x2, y2 = parent.position
        draw.line(surface,COLOR, (x1,y1), (x2,y2), 5 )

    def draw_initial(self,surface,stepV):
        x, y = self.position
        x, y = x , y+(stepV)
        rect = pygame.Rect((x,y) , (50,50))
        rect.center = (x , y)
        gfxdraw.box(surface, rect, COLOR)
        if self.value is not None:
            text = f"{self.value}"
            text_surface = textFont.render(text, True, WHITE)
            text_rect = text_surface.get_rect()
            text_rect.center = (x , y)
            surface.blit(text_surface, text_rect)

    def visited(self,surface):
        x, y = self.position
        gfxdraw.filled_circle(surface, x, y, RADIUS, EXPLORED)
        self.displayValue(surface)
        pygame.display.flip()

    def visited_link(self,surface, parent):
        x1, y1 = self.position
        x2, y2 = parent.position
        draw.line(surface,EXPLORED, (x1,y1), (x2,y2), 5 )
        pygame.display.flip()

    def chosen(self,surface):
        x, y = self.position
        gfxdraw.filled_circle(surface, x, y, RADIUS, RED)
        pygame.display.flip()

    def route(self,surface,child,negamax=False):
        x1, y1 = self.position
        x2, y2 = child.position
        draw.line(surface,RED, (x1,y1), (x2,y2), 5 )
        self.visited(surface)
        child.chosen(surface)
        child.displayValue(surface,negamax)
        pygame.display.flip()


    def displayValue(self,surface,negamax=False):  
        if self.value is not None:
            value = self.value
            if negamax:
                value = -value
            text = f"{value}"
            text_surface = textFont.render(text, False, WHITE)        
            text_rect = text_surface.get_rect()
            text_rect.center = (self.position[0], self.position[1])
            surface.blit(text_surface, text_rect)
            pygame.display.flip()

    @staticmethod
    def displayAlphaBeta(surface,node,alpha,beta):
        x, y = node.position

        text = f" α : {alpha} "
        text_render = alphaFont.render(text, True, WHITE, GRAY)
        rect = text_render.get_rect()
        rect.center = (x, y-RADIUS-35)
        surface.blit(text_render, rect)
        
        text = f" β : {beta} "
        text_render = alphaFont.render(text, True, WHITE, GRAY)
        rect = text_render.get_rect()
        rect.center = (x, y-RADIUS-20)
        surface.blit(text_render, rect)

        pygame.display.flip()

    def displayAlphaBetaLast(surface,node,alpha,beta):
        x, y = node.position

        text = f" α : {alpha} "
        text_render = alphaFont.render(text, True, WHITE, GRAY)
        rect = text_render.get_rect()
        rect.center = (x, y+RADIUS+20)
        surface.blit(text_render, rect)
        
        text = f" β : {beta} "
        text_render = alphaFont.render(text, True, WHITE, GRAY)
        rect = text_render.get_rect()
        rect.center = (x, y+RADIUS+35)
        surface.blit(text_render, rect)

        pygame.display.flip()

