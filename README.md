# test_hasher
Simple Android x86 hasher implementation.
Hashing logic is implemented using 256 bytes chunks and then checked against stock crypto_generalhash implementation.
Project is organized using ndk-build system.
Tested on Arch Linux with Nexus 5 x86 Android (29 API).

## Requirements
- libsodium 1.0.18 -> https://download.libsodium.org/libsodium/releases/libsodium-1.0.18-stable.tar.gz,
- Android NDK 18b -> https://dl.google.com/android/repository/android-ndk-r18b-linux-x86_64.zip, 
- greatest unit test library -> https://github.com/silentbicycle/greatest/tree/7f89ba4c5fdb5c6b776d5d8e4dcb17cb77cbe789
Resulting binary is statically linked with libsodium and libhasher (hashing logic implementation).

## Project structure
- `./makefiles` -> entry points for ndk-build configuration
- `./src/greatest` -> unit test library and simple tests (statically linked with libsodium and libhasher)
- `./src/hasher` -> hashing logic implementation which results to libhasher Android x86 library for static linking
- `./src/main` -> main execution logic and arguments parse (statically linked with libsodium and libhasher)
- `./src/sodium` -> compiled Android x86 library for static linking (compilation routine in `build.sh` file)

## Compilation
Compilation script compiles libsodium using `$LIBSODIUM_SRC/dist-build/android-x86.sh`, then places libsodium.a and header files into `./src/sodium`.
After that compilation proceeds using ndk-build.

`$ ANDROID_NDK_HOME=<SET_YOUR_ANDROID_NDK_HOME> LIBSODIUM_SRC=<SET_YOUR_LIBSODIUM_SRC_DIRECTORY> PROJECT_DIR=<SET_PROJECT_PATH> /path/to/build.sh`

(example:
`$ ANDROID_NDK_HOME=/home/user/android-ndk-r18b LIBSODIUM_SRC=/home/user/libsodium-stable PROJECT_DIR=/home/user/test_hasher /home/user/test_hasher/build.sh`
)

After that push `$PROJECT_DIR/libs/x86/main` and `$PROJECT_DIR/libs/hasher_unittest` via adb and execute:

`$ adb push $PROJECT_DIR/libs/x86/hasher_unittest /data/local/tmp`
`$ adb push $PROJECT_DIR/libs/x86/main /data/local/tmp`
`$ adb shell`

## Usage
Inside adb shell:
`$$ cd /data/local/tmp`
`$$ ./hasher_unittest`
`$$ ./main 123`
(result must be "F5D67BAE73B0E10D0DFD3043B3F4F100ADA014C5C37BD5CE97813B13F5AB2BCF" without quotes, hex-encoded )