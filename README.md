# Todo App
This is a simple command line todo tracking app meant for my own personal use.

The app currently relies on you running it from the root directory instead of the build directory. You will not get UB if it is not.

## Building
Use the included CMakeLists.txt file. There are currently no dependencies.

``` cmake -B build -G <your generator> ```<br>
``` cmake --build /build ```


### Usage

Running the application without any flags will display any todos you currently have saved.<br>

``` -a ``` To add a new todo<br>
``` -r <title> ``` To remove a todo<br>
``` -f ``` To mark a todo as finished<br>
``` -c ``` To clear all todos<br>
``` -h ``` To list commands<br>


