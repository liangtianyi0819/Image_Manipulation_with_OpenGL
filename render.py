# TODO: you will need to install cv2
# Run "pip3 install opencv-python" in CLI

import cv2
import sys

# Kaleidoscope requires numpy. Uncomment this line and install it if you need to.
import numpy as np

# Store command line arguments in variables
# TODO: change the next line to store the filename
filename = sys.argv[1]
manip = sys.argv[2]

# Open the image file
img = cv2.imread('../' + filename)
# Get the dimensions (in pixels) of the image
dimensions = img.shape
# Copy the original image into an image for manipulation
img_manip = cv2.resize(img, (dimensions[1], dimensions[0]))
# TODO: Store white in a list, where each of the three parts is on a scale of [0, 255]
white = [255, 255, 255]
for x in range(dimensions[0]):
    for y in range(dimensions[1]):
        if manip == 'flip':
            img_manip[x, y] = img[dimensions[0]-1-x, y]
        elif manip == 'mirror':
            # TODO: mirror the image and store in img_manip[x, y]
            img_manip[x, y] = img[x, dimensions[1]-1-y]
        elif manip == 'invert':
            # TODO: invert the image and store in img_manip[x, y]
            # Hint: img[x, y] returns the color of the pixel at that coordinate.
            # You can invert by subtracting that color from white.
            currPoint = []
            img_manip[x, y][0] = white[0] - img[x, y][0]
            img_manip[x, y][1] = white[1] - img[x, y][1]
            img_manip[x, y][2] = white[2] - img[x, y][2]

# Displays the original image in the top left corner of the screen.
image = 'Original image'
cv2.namedWindow(image)
cv2.moveWindow(image, 0, 0)
cv2.imshow(image, img)
# TODO: Display the manipulated image alongside the original image.
mani = "Manipulated image"
cv2.namedWindow(mani)
cv2.moveWindow(mani, dimensions[0], dimensions[1])
cv2.imshow(mani, img_manip)

# TODO: Create a kaleidoscope image, display it, and save it to a file.
# This line puts two images side-by-side in one window.
horizontal_concat = np.concatenate((img, img_manip), axis=1)
# TODO: Save the image using the imwrite method from cv2
cv2.imwrite('../' + "kaleidoscope.jpg", horizontal_concat)

# TODO: Show the image
cv2.imshow('Horizontal Concatenation!', horizontal_concat)

# Infinite loop to keep the windows open until the escape key is pressed.
while True:
    k = cv2.waitKey(1)
    if k == 27:
        cv2.destroyAllWindows()
        exit()

