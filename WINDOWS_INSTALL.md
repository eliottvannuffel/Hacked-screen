# 🪟 Windows Installation Guide

This guide shows you how to install Qt on Windows **without creating any accounts**.

## 🚀 **Option 1: vcpkg (Recommended)**

vcpkg is Microsoft's package manager and the easiest way to install Qt without accounts.

### **Step 1: Install vcpkg**
```cmd
# Open Command Prompt as Administrator
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
```

### **Step 2: Install Qt**
```cmd
.\vcpkg install qt5-base
```

### **Step 3: Build the project**
```cmd
cd <your-project-directory>
build.bat
```

## 🐧 **Option 2: MSYS2**

MSYS2 provides a Unix-like environment for Windows with easy package management.

### **Step 1: Install MSYS2**
1. Download from: https://www.msys2.org/
2. Run the installer
3. Open MSYS2 terminal

### **Step 2: Install Qt**
```bash
pacman -S mingw-w64-x86_64-qt5-base mingw-w64-x86_64-qt5-widgets
pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc
```

### **Step 3: Build the project**
```bash
cd <your-project-directory>
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

## 🍫 **Option 3: Chocolatey**

Chocolatey is a popular Windows package manager.

### **Step 1: Install Chocolatey**
Run PowerShell as Administrator and execute:
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

### **Step 2: Install Qt**
```cmd
choco install qt5
```

### **Step 3: Build the project**
```cmd
cd <your-project-directory>
build.bat
```

## 📦 **Option 4: Manual Download**

Download Qt offline installers directly from Qt's servers.

### **Step 1: Download Qt**
1. Go to: https://download.qt.io/official_releases/qt/
2. Navigate to the version you want (e.g., `5.15/5.15.2/`)
3. Download the offline installer:
   - `qt-opensource-windows-x86-5.15.2.exe` (32-bit)
   - `qt-opensource-windows-x64-5.15.2.exe` (64-bit)

### **Step 2: Install Qt**
1. Run the downloaded installer
2. Choose "Skip" when asked to create an account
3. Select the components you need (Qt 5.15.2, MinGW, etc.)

### **Step 3: Build the project**
```cmd
cd <your-project-directory>
build.bat
```

## 🔧 **Option 5: Using Qt Official Installer (Account Required)**

If you don't mind creating a free account:
1. Go to: https://www.qt.io/download
2. Create a free account
3. Download Qt Online Installer
4. Install Qt with your account

## 📋 **Prerequisites**

### **Required Tools:**
- **Git**: Download from https://git-scm.com/download/win
- **CMake**: Download from https://cmake.org/download/
- **Visual Studio**: Community edition is free from Microsoft
- **Or MinGW**: Alternative compiler

### **Installation Order:**
1. Install Git
2. Install CMake
3. Install Qt (using any method above)
4. Install Visual Studio or MinGW
5. Build the project

## 🎯 **Recommended Setup**

For beginners, I recommend:
1. **vcpkg** (Option 1) - Easiest and most reliable
2. **MSYS2** (Option 2) - Good for Unix-like development
3. **Manual Download** (Option 4) - Most control

## 🐛 **Troubleshooting**

### **Common Issues:**

**"Qt not found" error:**
- Ensure Qt is in your PATH
- Try setting `CMAKE_PREFIX_PATH` to Qt installation directory

**Build errors:**
- Make sure you have the right compiler (Visual Studio or MinGW)
- Check that Qt and CMake versions are compatible

**Fullscreen not working:**
- Run the application as Administrator
- Check Windows display settings

### **PATH Setup:**
If Qt is not found automatically, add to your PATH:
```
C:\Qt\5.15.2\mingw81_64\bin
C:\Qt\Tools\mingw810_64\bin
```

## ✅ **Verification**

After installation, verify Qt is working:
```cmd
qmake --version
```

You should see Qt version information.

---

**Happy building! 🎉** 