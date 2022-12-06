import cv2
import numpy as np
from math import inf

box_coordinates = []

# mouse callback function
def draw_rect(event, x, y, flags, param):
    global box_coordinates 
    if event == cv2.EVENT_LBUTTONDOWN:
        box_coordinates=[(x, y)] 
      
    elif event == cv2.EVENT_LBUTTONUP:
        box_coordinates.append((x, y)) 
        cv2.rectangle(img, (box_coordinates[0][0], box_coordinates[0][1]), 
        (box_coordinates[1][0], box_coordinates[1][1]), (0, 0, 255), 2)
        cv2.imshow("image", img) 
            
	
img = cv2.imread("image072.png")
cv2.namedWindow('image')
cv2.setMouseCallback('image', draw_rect)

while(True):
	cv2.imshow('image', img)
	k = cv2.waitKey(1) & 0xFF
	if k == 27:
		break
print(box_coordinates)
cv2.destroyAllWindows()

img1 = cv2.imread('image072.png')
grayImg1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
# Cropping an image
bloc1 = grayImg1[box_coordinates[0][1]:box_coordinates[1][1], box_coordinates[0][0]:box_coordinates[1][0]] 
print(bloc1)

# Display cropped image
cv2.imshow("cropped", bloc1)
cv2.waitKey(0)