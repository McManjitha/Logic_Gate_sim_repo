# Python program to move the image
# with the mouse

# Import the library pygame
import pygame
from pygame.locals import *

# Take colors input
YELLOW = (235, 255, 150)
BLUE = (0, 0, 255)
default_gate_size = (100, 100)
default_menu_size = (600, 80)

# Construct the GUI game
pygame.init()

# Set dimensions of game GUI
w, h = 640, 640
screen = pygame.display.set_mode((w, h), pygame.RESIZABLE)

# menu bar
menu = pygame.image.load('./images/MENU.jpg')
menu = pygame.transform.scale(menu, default_menu_size)

# Take image as input
andImg = pygame.image.load('./images/AND.jpg')
andImg = pygame.transform.scale(andImg, default_gate_size)
andImg.convert()
orImg = pygame.image.load('./images/OR.jpg')
orImg = pygame.transform.scale(orImg, default_gate_size)
orImg.convert()
notImg = pygame.image.load('./images/NOT.jpg')
notImg = pygame.transform.scale(notImg, default_gate_size)
notImg.convert()
xorImg = pygame.image.load('./images/XOR.jpg')
xorImg = pygame.transform.scale(xorImg, default_gate_size)
xorImg.convert()

# Draw rectangle around the image
rect = andImg.get_rect()
rect.center = w // 2, h // 2

# Set running and moving values
running = True
moving = False

imageList = []



# Setting what happens when game
# is in running state
while running:

    for event in pygame.event.get():

        # Close if the user quits the
        # game
        if event.type == QUIT:
            running = False

        # Making the image move
        elif event.type == MOUSEBUTTONDOWN:
            #if event.pos < 80 and event.pos < 200:

            if rect.collidepoint(event.pos):
                moving = True

        # Set moving as False if you want
        # to move the image only with the
        # mouse click
        # Set moving as True if you want
        # to move the image without the
        # mouse click
        elif event.type == MOUSEBUTTONUP:
            moving = False

        # Make your image move continuously
        elif event.type == MOUSEMOTION and moving:
            rect.move_ip(event.rel)

    # Set screen color and image on screen
    screen.fill(YELLOW)
    screen.blit(menu, (0, 0))
    screen.blit(andImg, rect)

    # Construct the border to the image
    pygame.draw.rect(screen, BLUE, rect, 2)

    # Update the GUI pygame
    pygame.display.update()

# Quit the GUI game
pygame.quit()