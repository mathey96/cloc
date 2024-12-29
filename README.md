## Build
<br/>Before building you will have to build and install the notcurses library
<br/>(https://github.com/dankamongmen/notcurses) (read the INSTALL.md) for guide to installation.

<br/>After successful installation of notcurses, do:

~~~ console
mkdir build
cd build
cmake ..
make
~~~

## Controls

 | Option                     | Key   |
 |----------------------------|-------|
 | quit                       | q     |
 | to change to next font     | n     |
 | to change to previous font | p     |
 | stopwatch mode             | s     |
 | reset stopwatch            | r     |
 | change color               | l     |
 | animation                  | a     |
 | pause stopwatch            | SPACE |
 | clock mode                 | c     |
 | help menu                  | h     |

## Demo

![](https://github.com/mathey96/cloc/blob/dev-branch/demo.gif)

https://github.com/user-attachments/assets/647b6f37-4ef0-4e5f-b3e9-2093055b813f


## Other

<br/> Simple short example of generating font with figlet cmd:

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
