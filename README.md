# Image Processor Collection

Collection of Image Processors to be tested using Panoramix.

## Installing external dependencies

### Dependencies managed by conan
- Catch2
- OpenCV

Run the following script for installing the dependencies:

```bash
sh conan_install.sh
```

## Building the project

### Using CMake

To compile any target in the project, you can directly use CMake. Create a build directory manually and generate the 
Makefiles in it. 

```bash
mkdir build && cd build
cmake ..
make
```

TODO:
- Add more image processors.
- Unit testing.