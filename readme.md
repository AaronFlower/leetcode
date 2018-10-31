## Leetcode Problems Set

### Init
```
git clone https://github.com/AaronFlower/leetcode.git
```
### Install Google Test Framework
```
cd leetcode
./pre-build.sh
```

### Run All Test

```
cd build
cmake ..
make 
make test
```

### Run Single Problem Test

```
cd build
cmake ..
make
./282-ExpressionAddOperations/test282
```

### Debug in XCode
```
mkdir Xcode
cd Xcode
cmake -G Xcode ..
open leetCode.xcodeproj 
```
