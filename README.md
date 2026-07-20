# wave-equation-solver

> Accurate numerical solution to the one-dimensional wave equation.

## Overview

The wave-equation-solver project implements a numerical solution to the one-dimensional wave equation, a fundamental equation in physics describing the propagation of a wave through a medium. This implementation uses finite difference methods to discretize the spatial and temporal derivatives, providing a reliable and efficient tool for simulating wave phenomena. By leveraging this technology, researchers and engineers can model and analyze complex wave dynamics in various fields, such as acoustics, electromagnetism, and oceanography.

## Features

- **Numerical stability**: Robust finite difference schemes ensure accurate and stable solutions.
- **Flexibility**: Supports variable grid sizes, time steps, and boundary conditions.
- **Scalability**: Optimized for performance on modern computing architectures.
- **Portability**: Cross-platform compatibility with Linux, macOS, and Windows.
- **Documentation**: Extensive code comments and API documentation for ease of use.
- **Testing**: Thorough unit tests and integration tests ensure correctness and reliability.
- **Modularity**: Separated code into logical modules for easy maintenance and extension.
- **Performance**: Optimized for fast execution and minimal memory usage.
- **Customizability**: Allows users to modify and extend the implementation to suit specific needs.

## Getting Started

### Prerequisites

- C compiler (gcc or clang)
- CMake build system (version 3.10 or later)
- A modern Unix-like operating system (Linux, macOS, or Windows Subsystem for Linux)

### Installation

```bash
# Clone the repository
git clone https://github.com/your-username/wave-equation-solver.git

# Navigate to the project directory
cd wave-equation-solver

# Create a build directory
mkdir build

# Configure the build
cmake -DCMAKE_BUILD_TYPE=Release .

# Build the project
cmake --build .

# Install the project (optional)
sudo cmake --build . --target install
```

### Usage

```bash
# Run the solver with default parameters
./wave_equation_solver

# Run the solver with custom parameters
./wave_equation_solver -c <grid_size> -t <time_step> -b <boundary_condition>
```

## Architecture

The project structure is organized into the following directories:

- `src/`: Source code for the solver implementation
- `tests/`: Unit tests and integration tests for the solver
- `docs/`: Documentation and API reference for the solver
- `build/`: Build artifacts and intermediate files

Key files and their roles:

- `wave_equation_solver.c`: Main program and entry point for the solver
- `wave_equation.h`: Header file for the wave equation solver implementation
- `utils.c`: Utility functions for numerical computations and data structures
- `utils.h`: Header file for utility functions

## API Reference

The public API is documented in the `wave_equation.h` header file.

## Testing

```bash
# Run unit tests
cmake --build . --target test

# Run integration tests
./integration_test
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Commit changes
4. Push and open a PR

## License

MIT License

Copyright (c) 2026 SamyAlderson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.