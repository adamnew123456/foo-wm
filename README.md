fifo-wm: FIFO Window Manager
============================
The premise is quite simple, a window manager which is configured and used exclusivly through talking to a FIFO. 

This should be considered unusable pre-alpha software. I'm using fifo-wm on a daily basis though it doesn't have support for many basic window managment functions (ICCCM/EWMH). Regardless, here is some explanations of how things are currently set up.

The Tree
--------
All windows are stored as nodes within a tree data structure. The tree is made up of two fundamental types of nodes. 

1. A **client** node
	- Hold 1 X Window
	- A **client** always has a parent
	- A **client** cannot have any children

2. A **container** node
	- 1 or more **client** nodes 
	- 1 or more **container** nodes

FIFO Commands
-------------
The FIFO specified in src/config.h must be made with `mkfifo wm-fifo`. Once the FIFO is created you may use several commands to interact with the window manager by simply echoing to the FIFO like so:

`echo "dump" > wm-fifo`

Commands that may be sent to the FIFO are listed below:

### dump
Dumps a tree view of the root container to STDERR.
```
[0]=> Container (Vertical)
	Client
	[1]=> Container (Horizontal)
		Client
		Client
		Client
```

### layout [vertical/horizontal/grid/tabbed/max]
Updates the layout of the current container. Currenly only vertical and horizontal layouts are supported, although future layouts planned include: floating, max, and tabbed.

### view [parent/child]
Controls the view of the screen. [*parent*] sets the view to the parent of the current view. [*child*] sets the view to the next child approximating the focused node. Switching the focus node allows you to view / zoom in on different nodes.


### focus
The focus command switches the client which is currently focused.

#### focus cycle [next/previous]
Using focus cycle allows you to cycle through client in your current container.

#### focus direction [left/up/right/down]


### select [parent]
Selects the parent container


### containerize
If the current client is in a container with 2 or more other clients, containerize creates  new container and parents the current client into this new container.


Inspiration
------
Inspirations include: 
DWM, monsterwm, catwm, dminiwm, i3, herbstluftwm, wmii, and tinywm
