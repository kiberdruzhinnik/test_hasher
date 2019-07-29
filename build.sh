#!/bin/sh

if [ -z ${LIBSODIUM_SRC+x} ]; then echo "LIBSODIUM_SRC is unset"; exit; fi
if [ -z ${PROJECT_DIR+x} ]; then echo "PROJECT_DIR is unset"; exit; fi
if [ -z ${ANDROID_NDK_HOME+x} ]; then echo "ANDROID_NDK_HOME is unset"; exit; fi

cd $LIBSODIUM_SRC
dist-build/android-x86.sh
cd libsodium-android-i686
cp -rf include $PROJECT_DIR/src/sodium
cp -rf lib/libsodium.a $PROJECT_DIR/src/sodium/libsodium.a
cd $PROJECT_DIR
export NDK_PROJECT_PATH=$PROJECT_DIR
$ANDROID_NDK_HOME/ndk-build NDK_APPLICATION_MK=makefiles/Application.mk