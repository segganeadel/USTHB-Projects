import numpy as np
import cv2
from matplotlib import pyplot as plt
import math

# Code from:
# https://opencv24-python-tutorials.readthedocs.io/en/latest/py_tutorials/py_feature2d/py_matcher/py_matcher.html

# Prepared for M1IV students, by Prof. Slimane Larabi
#===================================================

img1 = cv2.imread('./img1.jpg',0) # queryImage
img2 = cv2.imread('./img2.jpg',0) # trainImage

img1 = cv2.resize(img1,[400,400])
img2 = cv2.resize(img2,[400,400])

Ox=8.96257767*(math.exp(2))
Oy=2.28124505*(math.exp(2))

# Initiate SIFT detector
sift = cv2.SIFT_create()

# find the keypoints and descriptors with SIFT
kp1, des1 = sift.detectAndCompute(img1,None)
kp2, des2 = sift.detectAndCompute(img2,None)
# print(des1[0],kp1[0].pt)

# BFMatcher with default params
bf = cv2.BFMatcher()
matches = bf.knnMatch(des1,des2, k=2)
# Sort them in the order of their distance.
# matches = sorted(matches, key = lambda x:x.distance)

# Apply ratio test
good = []
match=[]
for m,n in matches:
    if m.distance < 0.75*n.distance:
        print(m.queryIdx, m.trainIdx, m.distance, n.queryIdx, n.trainIdx, n.distance, n.imgIdx)
        good.append([m])      
# cv2.drawMatchesKnn expects list of lists as matches.

# Get the first match
print(len(good))

firstmatch = good[1]


# Get the keypoints corresponding to the match
kp1_idx = firstmatch[0].queryIdx
kp2_idx = firstmatch[0].trainIdx
kpp1 = kp1[kp1_idx]
kpp2 = kp2[kp2_idx]

# Get the coordinates of the keypoints
ul, vl = kpp1.pt
ur, vr = kpp2.pt

fx=3.58341189*(math.exp(3))
fy=2.87934608*(math.exp(4))
b=4


# Print the coordinates
#print(f"Image 1 match coordinates: ({ul}, {vl})")
#print(f"Image 2 match coordinates: ({ur}, {vr})")

X=(b*(ul-Ox))/(ul-ur)
Y=(b*fx*(ul-Ox))/(fy*(ul-ur))
Z=(b*fx)/(ul-ur)
print("X=",X)
print("Y=",Y)
print("Z=",Z)


firstmatch = [firstmatch]

img3 = cv2.drawMatchesKnn(img1,kp1,img2,kp2,firstmatch, None, flags=2)



print

plt.imshow(img3),plt.show()