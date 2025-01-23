# Feedback Kushal 23 Jan
1) Implementation of run in app source file is too long, later if you need to add more cases you will have to modify the whole run block. Try to write code which can be modified later easily.
2) Instead of using cout, maybe write a string stream class to write in console like the notifier class.
3) Don't use auto wherever not required. It should be used in cases where you don't know the return type.
4) Write more tests for bad cases like when the use passes 0 break duration, etc.
5) Usage of Singleton Pattern for Timer class was a right decision, maybe you can do the logging as well by implementing a logger class. You can use boost for implementing that class (just a suggestion)