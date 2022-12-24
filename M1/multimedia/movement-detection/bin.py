def binarySearch(bloc1,searchBox,searchImg,bloc_width,bloc_height,width,height,span):
    mse = +inf
    limitX = (searchBox[1][0] - bloc_width) + 1
    limitY = (searchBox[1][1] - bloc_height)+ 1
    box2_coordinates = None


    for y in range(searchBox[0][1],limitY,bloc_height):
        for x in range(searchBox[0][0],limitX,bloc_width):
                bloc2 = searchImg[y:y+bloc_height,x:x+bloc_width]
                temp = MSE(bloc1,bloc2)
                if temp < mse:
                    mse = temp
                    box2_coordinates=[(x,y),(x+bloc_width,y+bloc_height)]
    searchBox = get_searchBox(box2_coordinates,width,height,span)
    print(searchBox,span)
    if searchBox[1][0] - searchBox[0][0] <= bloc_width or searchBox[1][1] - searchBox[0][1] <= bloc_height:
        return box2_coordinates
    else:
        return_value = binarySearch(bloc1,searchBox,searchImg,bloc_width,bloc_height,width,height,span//2)
        return return_value
