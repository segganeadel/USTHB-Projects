# import computer vision library(cv2) in this code
import cv2
import math

img_path = "im1.jpg"
image_c = cv2.imread(img_path)
image = cv2.cvtColor(image_c,cv2.COLOR_BGR2GRAY)
#image=image_c

# mentioning absolute path of the image
#cv2.GaussianBlur(src, ksize, sigmaX, sigmaY, borderType)
#borderType: This specify boundaries of an image while kernel is applied on borders of an image.
# cv2.BORDER_DEFAULT: gfedcb|abcdefgh|gfedcba

n = 5
sigma = 2.0

sigma1 = sigma**2
sigma2 = sigma**2 + sigma**2





blur_img = cv2.GaussianBlur(image, (105,105), sigma , borderType = cv2.BORDER_DEFAULT)
blur_img = cv2.GaussianBlur(blur_img, (105,105), sigma , borderType = cv2.BORDER_DEFAULT)

blur_img2 = cv2.GaussianBlur(image, (105,105),sigma2 , borderType = cv2.BORDER_DEFAULT)


    # show the image on the newly created image window
cv2.imshow('Blur image',blur_img)
cv2.imwrite("im1b.png", blur_img)

cv2.imshow('Blur image 1',blur_img2)
cv2.imwrite("im1c.png", blur_img2)

cv2.waitKey(0)
