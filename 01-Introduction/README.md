# AIoT Diploma Introduction Unit

----------
## Setup Arduino IDE

1.  Install Arduino IDE from [**Arduino** Official Site](https://arduino.cc).
2. Install **ESP32** core in Arduino following the next tutorial [Tutorial](https://randomnerdtutorials.com/installing-esp32-arduino-ide-2-0/).

    a helper link :
    `https://dl.espressif.com/dl/package_esp32_index.json`

3. Install [**CP2102 Driver**](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

----------

## Setup PlatformIO IDE
1. Download and Install [**VSCode** Editor](https://code.visualstudio.com/Download).
    - *Optional:* Setup color theme (Beautiful UI).
    - *Optional:* Setup Icon theme (Material Icon Theme).
    - *Optional:* Setup Font (Monaco/Fira Code/JetBrains Mono).
    
2. Download and Install [**Python** 3.11](https://docs.platformio.org/en/latest/faq/install-python.html).

3. Download and Install [**Git**](https://www.atlassian.com/git/tutorials/install-git#windows). 

4. Within **VSCode** Extentions tab, find and install **PlatformIO IDE** extension.

    ![PlatformIO within VSCode Extensions](images/PlatformIO%20Extension.JPG)

## Setup C++ Compiler
1. Ensure C++ [Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) is installed.
2. Install Mingw-w64 via [MSYS2](https://www.msys2.org).
    - Run [MSYS2 MinGW UCRT] and execute:
      - `pacman -S --needed base-devel mingw-w64-x86_64-toolchain` (Accept the default to install all the members).
      - `pacman -S mingw-w64-x86_64-gdb` for debugging.
    - [Add both binaries url to the PATH environment variable](https://stackoverflow.com/a/44272417), defaults are:
      - `C:\msys64\ucrt64\bin`
      - `C:\msys64\mingw64\bin`
    - Reload Visual Studio Code.