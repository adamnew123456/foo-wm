This is an ongoing list of bugs and planned features. If you are looking for something to contribute, this would be a good starting point. The codebase of foo-wm is small and hackable. Contributions are welcomed.

Bugs
====
- 'set screen_padding_(top|left|right|bottom)' does not take immediate affect
- 1 Child containers within containers
- 'containerize' 'containerize' -- case of the missing container
- brotherNode() in tree.c, node->parent = brother->parent ?
    * This could potentially break the old node's brothers and node parent child ptr
- Destroying last client doesn't focus container / set focusedNode
    * Tree: 
        - Container (1)
            * Container (2)
            * Client (3)
            * Client (4)
            * Client (5) [Focus]
    * 'kill' 'kill' 'kill' 'focus pc -1' ==> causes crash
    * void focus asserts focusedNode?
- mark'ing and jump'ing to a client doesn't restore the client but the container
- First client launched if no root (on start) should be just a client and not part of a container
    * When 2nd client launched, if there is a client, a container should be created

Fixed Bugs
==========
- 'focus brother delta' updates view node, but does not set global viewNode


Planned Features
================
- Implement Floating Layout for Containers
  * Mostly will be an update to placeNode in tree.c
  * Will need to modify events.c as well
- WM Hints/Atoms
- reparent command (shifts a node into another container)
- transpose command (given two node ids - switch)
- Socket responses for commands in command.c
- Title and Tab bar / Window Decorations 
- Multi-Monitor
- Percent Fill for Nodes whose parent is Vertical/Horizontal mode (Resize)
- If 2 (Container) Nodes in a Parent, and 1 Destroyed -->  Last Container becomes Client
- kill command should work for container nodes not just client nodes
