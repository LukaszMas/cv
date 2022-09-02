# How-To Enable backtracing with gdb and OpenCV

Ref OpenCV link: [OpenCV setBreakOnError][1]
Ref Guide: [Stackoverflow][2]

1. To make the program crash because OpenCV did an invalid operation before it
   would throw cv::Exception normally, add following line before any OpenCV
   code (C++):
      - `cv::setBreakOnError(true);`
      - This will make it easy to backtrace the line of error with gdb

[1]: <https://docs.opencv.org/4.x/db/de0/group__core__utils.html#gae4904ef072dede53cf161d9a6869083f> "docs.opencv.org - setBreakOnError()"
[2]: <https://stackoverflow.com/questions/12687684/how-to-find-out-what-is-causing-cvexception-at-memory-location> "stackoverflow.com"
