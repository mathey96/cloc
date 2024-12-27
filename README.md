## Build
<br/>before building you will have to build and install the notcurses library
<br/>(https://github.com/dankamongmen/notcurses) (read the INSTALL.md) for guide to installation.

<br/>after successful installation of notcurses, do:

~~~ console
mkdir build
cd build
cmake ..
make
~~~

## Demo

![](https://github.com/mathey96/cloc/blob/dev-branch/demo.gif)

## Other

<br/> simple short example of generating font with figlet cmd:

~~~ console
seq 0 9 | figlet
~~~

<br/>header files:
~~~ console
<br/>echo -e "standard\nlean\nmini\nmono9\nmono12\nsmmono12\nsmscript\nsmshadow\nsmslant" | parallel 'seq 0 9 | figlet -f {} > {}.h' &&
<br/>echo -e "standard\nlean\nmini\nmono9\nmono12\nsmmono12\nsmscript\nsmshadow\nsmslant" | parallel ' echo ":" | figlet -f {} >> {}.h'
~~~

<br/>figlet fonts should be located at:
<br/>/usr/share/figlet
<br/>and many more are available on the internet
