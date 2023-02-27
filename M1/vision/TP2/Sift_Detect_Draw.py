import cv2 as cv
img = cv.imread('im1.jpg')
gray= cv.cvtColor(img,cv.COLOR_BGR2GRAY)
sift = cv.SIFT_create()
#kp = sift.detect(gray,None)

kp, des = sift.detectAndCompute(gray, None)
print(len(kp))
print(len(des))
""" i=1
for k in kp:
    print("keypoint" + str(i))
    print(k.pt,k.size,k.angle,k.response)
    i += 1

for d in des:
    print(d) """