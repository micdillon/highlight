highlight
=========

A simple (POSIX compliant) command line utility that highlights a line of input given a regex.

I'm sure there is an existing command that does this, but it was easier to write the code than scower the internet finding the correct command.

Example Usage: 
`cat CMakeCache.txt| hl 'CMAKE_CXX_FLAGS'| less`
This highlights all the lines of CMakeCach.txt containing CMAKE_CXX_FLAGS so we can quickly scan the file for matches.
I like this more than just grepping (or awking) because once you find what you're looking for you have the whole file to look at, not just the line that matched.

TODO:
- Command line options (for color, bold, etc.)
- Multiple matches
