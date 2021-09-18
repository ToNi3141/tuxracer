# Prove of concept
This repository is just a prove of concept for the RasteriCEr to show, that it is possible to render 3D applications.

The port is not complete. It might be a bit hard to get into a 3D scene because not all buttons are implemented and there is also no mouse support. To start a game, press ```enter``` to get to the main menu, press ```p``` to start a practice and then press again ```enter``` to start the game. You can then use the left and right arrow buttons to control tux.

## How to build 
```
git clone https://github.com/ToNi3141/tuxracer.git
cd tuxracer
git checkout RasteriCErPort
git submodule init
git submodule update

cd RasteriCEr/rtl/top/Verilator
make 
```
Now build the tuxracer Qt project.

For further build details, check the simulation section in the ```RasteriCEr/README.md```.

You also have to download the assets. You can find them (together with the original source code) at http://tuxracer.sourceforge.net/download.html

tuxracer will create in ```~/.tuxracer``` a ```options``` file. Set ```data_dir``` to the path of your assets, for instance ```set data_dir "~/tuxracer-data-0.61"```

Note: For unknown reason, when you start tuxracer without a debugger, it will crash. I don't know why. So, always use a debugger when you start it.