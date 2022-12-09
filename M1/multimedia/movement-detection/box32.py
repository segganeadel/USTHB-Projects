import cv2
import numpy as np
from math import inf


def MSE(block1, block2):
    return np.sum((block1.astype("float") - block2.astype("float")) ** 2) / float(block1.shape[0] * block1.shape[1])

def search(bloc1,green_box):
    mse = +inf
    for j in range(green_box[0][1],(green_box[1][1]-bloc_height)+1):
        for i in range(green_box[0][0],(green_box[1][0]-bloc_width)+1):
                bloc2 = Yimg2[i:i+bloc_height,j:j+bloc_width]
                #print(bloc2.shape)
                #print(green_box)
                
                
                temp = MSE(bloc1,bloc2)
                if temp < mse:
                    mse = temp
                    box2_coordinates=[(j,i),(j+bloc_height,i+bloc_width)]
                    print(box2_coordinates)
                    
    print("yeeeew")
    print(box2_coordinates)
    print("\n")
    return box2_coordinates

def get_searchBox(coordinates):

    if coordinates[0][0] < span : topLeftX = 0
    else : topLeftX = coordinates[0][0] - span

    if coordinates[0][1] < span : topLeftY = 0
    else : topLeftY = coordinates[0][1] - span

    if coordinates[1][0] > width - span : bottomRightX = width
    else : bottomRightX = coordinates[1][0] + span

    if coordinates[1][1] > height - span : bottomRightY = height
    else : bottomRightY = coordinates[1][1] + span

    return [(topLeftX,topLeftY),(bottomRightX,bottomRightY)]
    

def draw_greenBox(img,coordinates):
    cv2.rectangle(img, 
    (coordinates[0][0], coordinates[0][1]), 
    (coordinates[1][0], coordinates[1][1]), 
    (0 , 255, 0), 2)

def draw_redBox(img,coordinates):
    cv2.rectangle(img, 
    (coordinates[0][0], coordinates[0][1]), 
    (coordinates[1][0], coordinates[1][1]), 
    (0, 0, 255), 2)


bloc_width = 128
bloc_height =128
seuil = 50
span = 100

image1 = "image072.png"
image2 = "image092.png"


img1 = cv2.imread(image1)
img2 = cv2.imread(image2)


Timg1 = cv2.cvtColor(img1, cv2.COLOR_BGR2XYZ)
Yimg1 = Timg1[:,:,0]

Timg2 = cv2.cvtColor(img2, cv2.COLOR_BGR2XYZ)
Yimg2 = Timg2[:,:,0]



width = Yimg1.shape[0]
height = Yimg1.shape[1]



""" for j in range (0,height-bloc_height,bloc_height):
    for i in range(0,width-bloc_width,bloc_width):
        bloc1 = Yimg1[i:i+bloc_height,j:j+bloc_width]
        bloc2 = Yimg2[i:i+bloc_height,j:j+bloc_width]
        if seuil < MSE(bloc1,bloc2):
            coordinates = [(j,i),(j+bloc_width,i+bloc_height)]
            draw_redBox(img1,coordinates)
            greenBox = get_searchBox(coordinates)
            #greenBox = search(bloc1,searchBox)
            draw_greenBox(img2,greenBox) """

i,j = height-bloc_height,width-bloc_width
coordinates = [(j,i),(j+bloc_width,i+bloc_height)]
draw_redBox(img1,coordinates)
greenBox = get_searchBox(coordinates)
print(greenBox)
#greenBox = search(bloc1,searchBox)
draw_greenBox(img2,greenBox)

#box = [(55, 55), (155, 155)]

#draw_greenBox(img1,box)


cv2.imshow("Result", img1) 
cv2.imshow("Shift", img2) 
cv2.waitKey(0)