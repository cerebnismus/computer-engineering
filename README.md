# Google Test For Mac

GoogleTest is a framework based on the xUnit architecture. This framework is to write test for C++ code and valid for the most common platforms. Installation

## Getting Started

To build and install goolge test library, first, we must install python and cmake in our development environment.

### Prerequisites

CMake
To obtain CMake follow this link to go to the CMake webpage. Once you reach de webpage, download the latest binary version for Unix or you can use:
```
brew install cmake
```

Python
If you nedd to download python, ho to python downloads web site. We need python 2.7 version.
```
brew install python
```

### Installing

GoogleTest
Finally we have to download google test library sources. Downlaod them from the GoogleTest web site, clicking on "gtest-1.5.0.tar.gz". Store the download file in your computer.
Once the sources file is on your PC, open a shell console. Navigate to your download directory and extract the archive by typing:
```
tar -xzvf gtest-version.tar.gz
```

Or you can use git repository:
```
git clone https://github.com/google/googletest.git
```

If you have a trouble with git:
```
sudo xcode-select --install
sudo xcode-select --reset
```

For build the library type:
```
cd googletest
mkdir mybuild
cd mybuild
cmake -G"Unix Makefiles" ..
make
```

Now, to install the built library type:
```
cp -r ~/googletest/googletest/include/gtest /usr/local/include
cp ~/googletest/mytest/lib/lib*.a /usr/local/lib
```

## Authors

* **Oguzhan Ince** - *Sakarya University* - [oguzhanlarca](https://github.com/oguzhanlarca)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
