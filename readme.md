## Pack
An open-source C++ library to pack triangles/rectangles into a canvas (or bigger rectangle)

#### Build Status
<img src="https://travis-ci.com/wasimusu/pack.svg?branch=master" width="100">


### Authors
- Bikalpa Khatiwada
- Wasim Akram Khan

### Features
Pack rectangles or triangles.

### Platform Support
* Tested for C++11 to C++20
* Build support for CMake
* Tested for Linux 18.04

### Compile
```
cd pack
mkdir build
cd build
cmake ..
make
```

### Sample Code
```
    #include <bits/stdc++.h>
    #include "../src/pack.cpp"
    
    using namespace std;
    
    int main(){
        vector<BoundingBox> rects;
        for (int i = 0; i < 4; i++) {
            rects.emplace_back(BoundingBox(10, 10, 10, 10));
        }
        pack_rectangles(rects, 10, 40);
    
        std::cout << "\nPacking squares in a horizontal grid " << endl;
        for (int i = 0; i < rects.size(); i++) {
            std::cout << rects[i].index_r << ", " << rects[i].index_c << std::endl;
        }
        
        return 0;    
    }

```

### Upcoming features
* Add support for Clang.
* Add suport for Bazel build
* Test for Windows 10.