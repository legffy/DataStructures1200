HOMEWORK 1: Spotify Playlists


NAME:  Randy Taylor


COLLABORATORS AND OTHER RESOURCES:
https://en.cppreference.com/w/cpp/string/basic_string
https://en.cppreference.com/w/cpp/container/vector
https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  6 hours 30 minutes






MISC. COMMENTS TO GRADER:  



## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your
own? What kinds of errors did you get? How did you fix them?

What parts of the assignment did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this assignment? How well
did the development and testing process go for you?

One issue that I had during development and testing was considering white space. It was simple dealing with add and remove
because, with any line like 'add "Bohemian Rhapsody" Queen' or 'remove "Wonderwall" Oasis' the remove and add both stop at the same index.
So when it came to carving out the song I just would assign a certain index for add or remove and then pick the song. This wasn't as simple
with the move action however. This is due to the index of the next movement being at the end. 
While it was easy to get the index due to using a simple function like size()-1 to get the element at the end of the string, the biggest
issue was the white space between the index and the song. Though after some testing I came up with just subtracting 2 because that gets rid 
of the index and the whitespace between the song. Even though I thought I dealt with the worst, unfortunatly I came across the issue of
addressing the current song. This issue became really prevalent when dealing with the move,next and previous parts of the playlist functionality. 
When the barebones of all the actions was done I thought I was good. I would just move current around based using next or previous. I did this at
first and made it so that current was in the right place most of the time. Despite this effort a couple songs would tend to be off.
After looking through the actions file I figured out was the move action wasn't functioning correctly. Ater a bit more testing I realized that if
the current song was supposed to be moved it wouldn't be. At first I thought it there was something wrong with the way I considered whitespace
with the next and previous functions. I saw some progress but in the end it didn't matter. Finally I realized that I needed to consider
current when I adding a file. The solution that worked for me was creating a function that would return a song without current. The way I added
this into the move action was making a temporary song variable without current and comparing it to the song I wanted to move. Then I moved the 
orignal song and to the right spot. These were my biggest challenges trying to get the correct output. I think that this homework was a good
introduction to C++ as it helped me get used to the syntax of the new language. 
