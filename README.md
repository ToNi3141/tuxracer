# Prove of concept
This repository is just a prove of concept for the Rasterix to show, that it is possible to render 3D applications.

It also shows how to integrate the library into your own software projects via cmake.

## How to build
```sh
git clone https://github.com/ToNi3141/tuxracer.git
cd tuxracer
git submodule update --init --recursive
cmake --preset zynq_embedded_linux -DCMAKE_TOOLCHAIN_FILE=Rasterix/toolchains/toolchain_zynq.cmake
cmake --build build/zynq/
```

Copy tuxracer now to your target. Please refer also the documentation in the Rasterix directory how to configure the kernel and how to build the kernel module.

## Build dependencies
This software depends on `TCL` and `SDL3`. It is easy to integrate `TCL`. You can just setup in petalinux your rootfs to include `TCL` and rebuild your rootfs and the SDK. 

`SDL3` is a bit more complicated. To avoid setting the `SDL3_PATH` in the cmake project, just checkout `SDL3` in the same directory where you have checked out tuxracer and build it.
```sh
git clone https://github.com/libsdl-org/SDL.git
cd SDL
git apply ../tuxracer/SDL3BuildFix.patch
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=../tuxracer/Rasterix/toolchains/toolchain_zynq.cmake -DSDL_SYSTEM_ICONV=false
cmake --build build
```
Now copy the SDL library to `/lib` on your target.

Note: SDL requires a window manager for keyboard inputs. You probably want to use a small window manger like matchbox. You can configure via petalinux your rootfs to include the window manager in your image. There are some howtos in the internet how to get it to run. The device tree file and the kernel config in the Rasterix repository include already everything you need to make the framebuffer available (see `Rasterix/lib/driver/dmaproxy/kernel`), only the rootfs must be configured. There are probably enough howto's how to do it in the internet with all required dependencies like [this](https://www.hackster.io/whitney-knitter/create-a-desktop-environment-for-the-te0802-using-petalinux-821ee8#toc-configure-root-filesystem-for-desktop-environment-2). If you use this howto and you use a ZYNQ7000 device, just ignore the `libmali` stuff.

You also have to download the assets. You can find them (together with the original source code) at http://tuxracer.sourceforge.net/download.html

On the first start, tuxracer will create in `~/.tuxracer` a `options` file. Set `data_dir` to the path of your assets, for instance `set data_dir "home/petalinux/tuxracer-data-0.61"` and set `set x_resolution 1024` and `set y_resolution 600`.

By default, matchbox runs as a root user. Copy the `options` from `/home/petalinux/.tuxracer/` to `/home/root/.tuxracer/`. 

## Start tuxracer
Open a terminal in matchbox, load the kernel module and then start tuxracer.