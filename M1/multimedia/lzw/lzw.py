import pickle
import cv2
import numpy as np


def compress(input):
    DICTIONARY_SIZE = 256
    dic = {}
    output = []
    w = ""
    
    for i in range(0, DICTIONARY_SIZE):
        dic[str(i).zfill(3)] = i

    for k in input:
        wk = w + str(int(k)).zfill(3)
        if wk in dic.keys():
            w = wk
        else:
            output.append(dic[w])
            dic[wk] = DICTIONARY_SIZE
            DICTIONARY_SIZE+=1
            w = str(int(k)).zfill(3)

    if w != "":
        output.append(dic[w])
    return output

def decompress(input):
    DICTIONARY_SIZE = 256
    dictionary = {}
    result = ""
    for i in range(0, DICTIONARY_SIZE):
        dictionary[i] = str(i).zfill(3)

    previous = int(input[0])
    result += dictionary[previous]
    input = input[1:]
    
    for current in input:
        pre_output = ""
        if current in dictionary.keys():
            pre_output = dictionary[current]
        else:
            pre_output = dictionary[previous]+dictionary[previous][:3]
        result += pre_output
        dictionary[DICTIONARY_SIZE] = dictionary[previous] + pre_output[:3]
        previous = current
        DICTIONARY_SIZE+= 1
    result =[int(result[i:i+3]) for i in range(0, len(result), 3)]
    return result








img = cv2.imread("./cablecar.bmp", 0)
#For black and white uncomment
#_, img = cv2.threshold(img, 100, 255, cv2.THRESH_BINARY)
width,height = img.shape
imgFlat=img.flatten()
compressedFile = compress(imgFlat)

output = open("./compressed_image", "wb")
pickle.dump(compressedFile, output)
output.close()


input = pickle.load(open("./compressed_image", "rb"))

uncompimg = decompress(input)
uncompimg = np.array(uncompimg)
uncompimg = uncompimg.reshape(width,height)
cv2.imwrite("decompressedimg_gray.bmp",uncompimg)


var = np.count_nonzero(img-uncompimg)
print("La difference entre les images est : " + str(var)+ " pixels")
output.close()
           
