import os
import cv2
import numpy as np
import matplotlib.pyplot as plt

# Set the path to the folder containing the query images
query_path = './queries'

# Set the path to the folder containing the train images
train_path = './License Plates'

# Initiate SIFT detector
sift = cv2.SIFT_create()

# BFMatcher with default params
bf = cv2.BFMatcher()

# Loop through all the query images
for query_file in os.listdir(query_path):
    if query_file.endswith('.png') or query_file.endswith('.jpg'):
        
        # Read in the query image
        query_image = cv2.imread(os.path.join(query_path, query_file), 0)

        # find the keypoints and descriptors with SIFT
        kp1, des1 = sift.detectAndCompute(query_image, None)

        # Initialize variables to keep track of the best match
        best_train_file = None
        best_match_count = 0

        # Loop through all the train images
        for train_file in os.listdir(train_path):
            if train_file.endswith('.png') or train_file.endswith('.jpg'):
                
                # Read in the train image
                train_image = cv2.imread(os.path.join(train_path, train_file), 0)

                # find the keypoints and descriptors with SIFT
                kp2, des2 = sift.detectAndCompute(train_image, None)

                # Match the descriptors using the BFMatcher
                matches = bf.knnMatch(des1, des2, k=2)

                # Apply ratio test
                good = []
                for m, n in matches:
                    if m.distance < 0.75 * n.distance:
                        good.append([m])

                # Keep track of the train image with the highest number of good matches
                if len(good) > best_match_count:
                    best_train_file = train_file
                    best_match_count = len(good)

        # Only display the best train image
        if best_train_file is not None:
            best_train_image = cv2.imread(os.path.join(train_path, best_train_file), 0)
            kp2, des2 = sift.detectAndCompute(best_train_image, None)
            matches = bf.knnMatch(des1, des2, k=2)
            good = []
            for m, n in matches:
                if m.distance < 0.75 * n.distance:
                    good.append([m])
            img3 = cv2.drawMatchesKnn(query_image, kp1, best_train_image, kp2, good, None, flags=2)
            plt.imshow(img3), plt.show()
