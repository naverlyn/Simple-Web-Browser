# Simple-Web-Browser
A Simple Split Web Browser using GTK3 and Glade *only opening Google Meet and Google Classroom at the same time

# Prerequisite

1. cmake
2. gcc
3. Glade
4. libgtk-3-dev
5. libwebkit2gtk-4.0-dev

Note: Make sure cmake and gcc are installed.
# Install

1. install Glade first.

`sudo apt update && sudo apt install glade -y`
> note that you can skip this if you don't want to see the ui.

2. install libgtk-3-dev

`sudo apt install libgtk-3-dev -y`

2. install libwebkit2gtk-4.0-dev and documentation

`sudo apt install libwebkit2gtk-4.0-dev libwebkit2gtk-4.0-doc`

3. build the source using make

`make`

4. run with

`./web-browser`
