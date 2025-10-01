# Pomodoro
A CLI Pomodoro timer application in C++ 


## Getting Started with Pomodoro


 * Clone the repository
    ```
    git clone https://github.com/shivaibhavd/Pomodoro_App.git
    ```

<h2 id="windows">Windows</h2>  

* Go to vcpkg directory and Install vcpkg
    ```
    cd vcpkg
    .\bootstrap-vcpkg.bat
    ```

* Build using CMake
    ```
    cd ..
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

* Run the app or tests
    ```
    cd build\Debug
    .\pomodoro.exe
    .\tests.exe
    ```

<h2 id="linux">Linux (Ubuntu)</h2>  

* Install vcpkg 
    ```
    .\bootstrap-vcpkg.sh
    ```

* Build using CMake
    ```
    cd ..
    mkdir build
    cd build
    cmake ..
    make
    ```

* Run the app or tests
    ```
    cd build
    .\pomodoro
    .\tests
    ```
