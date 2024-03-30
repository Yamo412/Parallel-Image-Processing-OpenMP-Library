# Parallel-Image-Processing-OpenMP-Library
OpenMP implementations for image processing

This repository showcases the use of OpenMP for parallelizing image processing tasks, demonstrating the efficiency gains from utilizing parallel computing techniques. The project includes both serial and parallel implementations for applying filters to images, providing a comparison of performance between conventional serial processing and multi-threaded execution with OpenMP.

**Prerequisites**

- GCC compiler with OpenMP support.
- Basic knowledge of C++ and parallel computing concepts.

**Installation**

Clone this repository to your local machine to get started. No additional installation steps are required.

**Compiling**

Use the provided Makefile for easy compilation of the project. To compile, run the following command in your terminal:
```make all```

This will compile both the serial and OpenMP parallel versions of the image processing application.

**Usage**

The applications can be run as follows:

- Serial version:
```./serial <input_image> <mask_file> <output_image>```

- OpenMP Parallel version:
```./openmp <input_image> <mask_file> <output_image> <number_of_threads>```

Example:
```./openmp input.txt mask.txt output.txt 4```

This command processes an image using a specified filter mask with 4 threads in parallel.

**Performance Comparison**

Included in the repository is a performance comparison between the serial and parallel implementations, illustrating the speedup achieved with OpenMP.







