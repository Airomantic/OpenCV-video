cmake_minimum_required(VERSION 3.15)
#项目信息
project(Test_first)

#指定c++标准是c++ 14
set(CMAKE_CXX_STANDARD 14)
## where to find opencv
set(OpenCV_DIR "E:\\CLion\\opencv\\build\\install")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
#指定生成目标，将main.cpp编译成Test_first的可执行文件
add_executable(Test_first main.cpp)
# add libs you need
#set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_xfeatures2d)
# linking
#target_link_libraries(Test_first ${OpenCV_LIBS})

FIND_PACKAGE(OpenCV REQUIRED)
IF (OpenCV_FOUND)
    INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
    TARGET_LINK_LIBRARIES(Test_first ${OpenCV_LIBS})
ELSE (OpenCV_FOUND)
    MESSAGE(FATAL_ERROR "OpenCV library not found")
ENDIF (OpenCV_FOUND)