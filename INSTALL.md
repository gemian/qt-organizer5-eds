# Qt-Organiser5-EDS

Designed to work using Qt v5.7.1 as available on Debian 9

# Install prerequisites mostly requires compiling qtpim, but make sure you install these first or the qtpim you compile will not have full qml support
```
sudo apt-get build-dep qt5-default
sudo apt-get install build-essential libedataserver1.2-dev libecal1.2-dev qtbase5-dev cmake libicu-dev qt5-default qml-module-qtquick-controls2 qml-module-qtquick-templates2
sudo apt-get install qtdeclarative5-dev qtquickcontrols2-5-dev qml-module-qtgraphicaleffects qml-module-qtqml-models2 qml-module-qtquick-controls qml-module-qtquick-layouts qml-module-qtquick-window2 qml-module-qtquick2
```
qtpim required qtcore private headerfiles, you can take the ones from handyfiles:
```
sudo mkdir /usr/include/x86_64-linux-gnu/qt5/QtCore/private
sudo cp handyfiles/qfactoryloader_p.h /usr/include/x86_64-linux-gnu/qt5/QtCore/private
sudo cp handyfiles/qlibrary_p.h /usr/include/x86_64-linux-gnu/qt5/QtCore/private
```

Pull out sources for qtpim:
```
git clone git://code.qt.io/qt/qtpim.git
```

Patch the files to cope with old qt (qmlWarning => qmlInfo):
```
src/imports/contacts/qdeclarativecontactrelationshipmodel.cpp
src/imports/contacts/qdeclarativecontactrelationship.cpp
src/imports/organizer/qdeclarativeorganizermodel.cpp
src/imports/organizer/qdeclarativeorganizerrecurrencerule.cpp
```

Build qtpim:
```
qmake qtpim.pro
make
sudo make install
```

# Finally compile EDS

```
git clone https://github.com/adamboardman/qt-organizer5-eds.git
cd qt-organizer5-eds
mkdir build
cd build
cmake ..
make
sudo make install
```

