# eigen
It's the library for Linear algebra calculation.  

# install

# setting
you should add the lines to CMakeLists.txt

~~~
find_package(Eigen3 REQUIRED) 

include_directories(
  ...
  ${EIGEN3_INCLUDE_DIR}
  ...
)
~~~

also include in your program file.

~~~
#include <Eigen/Core>
#include <opencv2/core/eigen.hpp>
~~~
