import pygame
import subprocess

# gate class
class Logic_Gate:
    def __init__(self, name, total_index, index, input = False):
        self.name = pygame.image.load(name)
        self.type = pygame.transform.scale(self.name, (100, 100))
        self.total_index = total_index
        self.index = index
        self.rect = self.type.get_rect()
        self.Xcor = 0
        self.Ycor = 100
        self.center = (self.Xcor//2, self.Ycor//2)
        self.moving = False
        self.connect = False
        self.input = input
        screen.blit(self.type, (self.Xcor, self.Ycor))

    def select(self):
        pygame.draw.rect(screen, (0, 0, 255), self.rect, 3)


class Wire:
    def __init__(self, begin_index, end_index):
        self.begin_gate_index = begin_index
        self.end_gate_index = end_index

# initialize the pygame
pygame.init()

# create the screen
w, h = 1100, 700
screen = pygame.display.set_mode((w, h), pygame.RESIZABLE)
line_width = 5
menu_size = (600, 100)
menu_size_2 = (300, 100)