# Qt-Organiser5-EDS

Updated to work using Qt v5.7.1 as available on Debian 9

# Install prerequisites
```
sudo apt-get qtpim5-dev
```

# Compile EDS

```
git clone https://github.com/adamboardman/qt-organizer5-eds.git
cd qt-organizer5-eds
mkdir build
cd build
cmake ..
make
sudo make install
```

