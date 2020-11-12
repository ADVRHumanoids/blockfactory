# Install

!!! info "Disclaimer"
    BlockFactory has been widely tested on `Ubuntu 16:04` and `Ubuntu 18.04` with Matlab `R2017b`. If you face any issue either with your OS or Matlab version, please submit an [Issue](https://github.com/robotology/blockfactory/issues).

## Requirements

- Supported Operating Systems
	- GNU/Linux
	- macOS
	- Windows
- C++14 compiler
- CMake 3.5

BlockFactory provides three components, listed here below with their dependencies. If a component dependency is not found, the component is not built.

|                  | `Core` | `SimulinkCoder` | `Simulink`             |
| ---------------- | ------ | --------------- | ---------------------- |
| **Dependencies** | ~      | ~               | - Matlab<br>- Simulink |

!!! note
    Simulink Coder is not a build dependency of the `SimulinkCoder` component. Of course, you must have it if you want to generate C++ code from a Simulink model.

## Installation

If all the dependencies are met, proceed with the following instructions:

!!! example "From sources"

    Substitute to `<install-prefix>` the absolute path where you want to install the project.

    ````tab="GNU/Linux and macOS"
    git clone https://github.com/robotology/blockfactory.git
    mkdir -p blockfactory/build && cd blockfactory/build
    cmake .. -DCMAKE_INSTALL_PREFIX=<install-prefix>
    cmake --build .
    cmake --build . --target install
    ````

    ````tab="Windows"
    git clone https://github.com/robotology/blockfactory.git
    mkdir -p blockfactory/build && cd blockfactory/build
    cmake .. -DCMAKE_INSTALL_PREFIX=<install-prefix>
    cmake --build . --config Release
    cmake --build . --config Release --target install
    ````

## Configuration

### Matlab

BlockFactory provides the support of:

- **Simulink** by shipping a generic [MEX Level-2 S-Function S-Functions](https://it.mathworks.com/help/simulink/sfg/what-is-an-s-function.html)
- **Simulink Coder** by shipping a TLC file to achieve [Wrapper Inlined S-Functions](https://it.mathworks.com/help/rtw/tlc/inlining-s-functions.html)

These two files are installed in the `<install-prefix>/mex` folder, which should be added to the [Matlab search path](https://it.mathworks.com/help/matlab/matlab_env/what-is-the-matlab-search-path.html).

### Plugins

The archictecture of BlockFactory is based on a plugin system. The libraries containing the blocks must be found in the filesystem.
Add to the following environment variable all the folders that contain BlockFactory plugins:

!!! example "Environment"

    ````tab="GNU/Linux and macOS"
    export BLOCKFACTORY_PLUGIN_PATH=/installfolder1/subfolder1/blockfactory:/installfolder2/subfolder2/blockfactory/:<...>
    ````

    ````tab="Windows"
    $env:BLOCKFACTORY_PLUGIN_PATH = "C:\installfolder1\subfolder1\blockfactory;C:\installfolder2\subfolder2\blockfactory:<...>";
    ````
