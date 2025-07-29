# 🎭 HACKED - Belgian Themed System Simulation

A humorous, fullscreen desktop application that simulates a "hacked system" with a Belgian theme. This is a **completely harmless entertainment application** built with C++ and Qt.

## 🎯 **What it does**

- Displays a fullscreen "hacked system" interface
- Features Belgian-themed ASCII art (waffles and fries)
- Shows animated "hacking" messages
- Automatically takes a screenshot after 30 seconds
- Requires typing "chicon" to exit

## 🛡️ **Safety & Privacy**

- **100% Harmless**: No actual system modifications
- **No Network Access**: Completely offline
- **No Data Collection**: No personal information gathered
- **Local Screenshots Only**: Screenshots saved locally to `~/Pictures/`
- **Easy Exit**: Type "chicon" to exit anytime

## 🚀 **Features**

- **Fullscreen Interface**: Immersive experience
- **Large, Readable Text**: Optimized for fullscreen viewing
- **Automatic Screenshots**: Captures the interface after 30 seconds
- **Professional UI**: Clean, modern design
- **Cross-Platform**: Works on Linux, Windows, and macOS

## 📋 **Requirements**

- Qt5 or Qt6
- CMake 3.16+
- C++17 compatible compiler
- Linux/Windows/macOS

## 🔧 **Installation**

### **Linux (Ubuntu/Debian):**
```bash
# Install dependencies
sudo apt update
sudo apt install -y qtbase5-dev qt5-qmake cmake build-essential

# Clone and build
git clone <repository-url>
cd <repository-name>
chmod +x build.sh
./build.sh
```

### **macOS:**
```bash
# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install dependencies
brew install qt cmake

# Clone and build
git clone <repository-url>
cd <repository-name>
chmod +x build.sh
./build.sh
```

### **Windows:**
```bash
# Option 1: Using vcpkg (Recommended - No account needed)
# Install vcpkg first
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install

# Install Qt via vcpkg (correct package names)
.\vcpkg install qt5-base

# Option 2: Using MSYS2 (No account needed)
# Download MSYS2 from: https://www.msys2.org/
# Then run:
pacman -S mingw-w64-x86_64-qt5-base mingw-w64-x86_64-qt5-widgets

# Option 3: Using Chocolatey (No account needed)
# Install Chocolatey first, then:
choco install qt5

# Option 4: Manual download (No account needed)
# Download Qt offline installers from:
# https://download.qt.io/official_releases/qt/
# Look for "qt-opensource-windows-x86-5.15.2.exe" or similar

# Option 5: Using Qt official installer (Account required)
# https://www.qt.io/download (requires free account)

# After installing Qt, install CMake:
# Download from: https://cmake.org/download/

# Clone repository
git clone <repository-url>
cd <repository-name>

# Build using batch file
build.bat

# Or manually:
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A x64
cmake --build . --config Release
```

### **Build from source (all platforms):**
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 🎮 **Usage**

### **Linux:**
```bash
cd build
./HACKED
```

### **macOS:**
```bash
cd build
./HACKED.app/Contents/MacOS/HACKED
```

### **Windows:**
```bash
cd build\Release
HACKED.exe
```

### **Controls:**
- **Exit**: Type "chicon" in the password field and press Enter
- **Screenshot**: Automatically taken after 30 seconds
- **Fullscreen**: Application runs in fullscreen mode

## 📸 **Screenshots**

The application automatically takes a screenshot after 30 seconds and saves it to:
- **Linux/macOS**: `~/Pictures/hacked_screenshot_YYYYMMDD_HHMMSS.png`
- **Windows**: `%USERPROFILE%\Pictures\hacked_screenshot_YYYYMMDD_HHMMSS.png`

## 🎨 **Customization**

You can easily modify the application by editing `HACKED.cpp`:
- Change colors and fonts
- Modify messages and ASCII art
- Adjust timing and behavior
- Add new features

## 🔒 **Security Notice**

This application is:
- ✅ **Safe to run**
- ✅ **No system modifications**
- ✅ **No network access**
- ✅ **No data collection**
- ✅ **Easy to exit**

## 📄 **License**

This project is for educational and entertainment purposes only.

## 🤝 **Contributing**

Feel free to submit issues, feature requests, or pull requests!

## ⚠️ **Disclaimer**

This is a **harmless entertainment application**. It does not perform any actual hacking or system modifications. Use responsibly and only on systems you own or have permission to use.

## 🐛 **Troubleshooting**

### **Build Issues:**
- Ensure Qt5 or Qt6 is properly installed
- Check that CMake version is 3.16 or higher
- Verify C++17 compiler support

### **Runtime Issues:**
- **Linux**: Install `libxcb-xinerama0` if fullscreen doesn't work
- **macOS**: Grant accessibility permissions if needed
- **Windows**: Run as administrator if fullscreen fails

## 🚀 CI/CD Pipeline

This project uses GitHub Actions for automated CI/CD:

### 🔄 **Automated Workflows**

1. **Continuous Integration** (`ci.yml`)
   - Runs on every commit to `main` and `develop`
   - Builds and tests on Linux, macOS, and Windows
   - Validates code quality and documentation

2. **Security Scanning** (`security.yml`)
   - Weekly vulnerability scans with Trivy
   - CodeQL analysis for security issues
   - License and dependency checks

3. **Automated Testing** (`test.yml`)
   - Unit tests and integration tests
   - Platform compatibility validation
   - Documentation validation

4. **Version Bump** (`version-bump.yml`)
   - Automatically bumps version on commits to `main`
   - Creates new Git tags (v1.0.1, v1.0.2, etc.)
   - Updates CMakeLists.txt and Info.plist

5. **Release Pipeline** (`release.yml`)
   - Triggers on version tags (v*)
   - Builds tarballs for all platforms
   - Creates GitHub releases with downloads

### 📦 **Release Process**

1. **Commit to main branch** → Automatic version bump
2. **New tag created** → Triggers release build
3. **Multi-platform build** → Linux, macOS, Windows tarballs
4. **GitHub release** → Automatic upload of artifacts

### 🎯 **Manual Release**

To create a manual release:

```bash
# Create and push a new tag
git tag -a v1.1.0 -m "Release v1.1.0"
git push origin v1.1.0
```

This will automatically trigger the release pipeline and create a new GitHub release with downloadable tarballs.

### 📊 **Workflow Status**

Check the [Actions tab](https://github.com/yourusername/hacked/actions) to see the status of all workflows.

---

**🇧🇪 Made with Belgian humor 🇧🇪** 