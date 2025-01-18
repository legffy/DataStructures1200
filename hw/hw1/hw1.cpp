#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// Used to troubleshoot
// Prints out the current state of the playlist
void printVec(std::vector<std::string> vec){
    // Iterates throughout the vector of strings and prints out all instances
    for(int i = 0;i<vec.size();i++){
        std::cout << vec[i] << std::endl;
    }
    std::cout <<std::endl;
}

// Given a string in this case a song returns a song without "current" in the string
std::string withoutCurrent(std::string song){
    std::string temp = song;
    int currLoc = song.find(" current");
    if(currLoc != std::string::npos){
        temp = temp.substr(0, currLoc);
    }
    return temp;
}

// Checks if a string is in a vector of strings
// In this case for a Spotify playlist checks if the given song is in the playlist
bool inPlaylist(std::vector<std::string> pL, std::string song){
    for(int s = 0; s < pL.size(); s++){
        std::string temp = withoutCurrent(pL[s]);
        if(song == temp){
            return true;
        }
    }
    return false;
}
// gets the number at the end of the move index by checking to see what the number is no matter how many digits it is 
int numberAtEnd(const std::string& input) {
    std::string numberStr = "";

    // Start from the end of the string and move backward
    for (int i = input.size() - 1; i >= 0; --i) {
        if (input[i] >= '0' && input[i] <= '9') {
            numberStr = input[i] + numberStr; // Prepend the digit to the result
        } else if (!(input[i] >= '0' && input[i] <= '9')) {
            // Stop if non-digit is found after collecting digits
            break;
        }
    }

    // If a number is found convert and return it
        return std::stoi(numberStr);
}

int main(int argc, char* argv[]){
    //Creates playlist
    std::vector<std::string> playlist;
    
    // Original playlist file name
    std::string oPLFN = std::string(argv[1]);
    
    // Original actions file name
    std::string oAFN = std::string(argv[2]);
    
    // Output file
    std::string oF = std::string(argv[3]);

    // Input stream for the original playlist file
    std::ifstream inputFileOP(oPLFN);
    
    // Input stream for the actions file
    std::ifstream inputFileOA(oAFN);

    // Output stream for the resulting playlist
    std::ofstream outputFile(oF);

    // Used to fetch the current song or action in a file
    std::string line;
    std::string action;

    // Adds all songs from the input playlist file to the playlist vector
    while(getline(inputFileOP, line)){
        playlist.push_back(line);
    }

    // Used to determine where the song begins based on a given action
    // In the output file, there's an action and then a song 
    // Example: "remove "Wonderwall" Oasis"
    int pos = 0;

    // Iterates through the actions file to add, move, remove, or go to the next/previous song
    while(getline(inputFileOA, action)){
        // Adds a song to the playlist
        if(action.find("add") != std::string::npos){
            // Song always starts at index 4
            pos = 4;
            playlist.push_back(action.substr(pos));
        
        // Removes a song from the playlist
        } else if(action.find("remove") != std::string::npos){
            // Song always starts at index 7
            pos = 7;
            std::string song = action.substr(pos);
            // Checks if the song is in the playlist and removes it based on the given action
            if(inPlaylist(playlist, song)){
                for(int i = 0; i < playlist.size(); i++){
                    if(song == playlist[i]){
                        playlist.erase(playlist.begin() + i);
                        break;
                    }
                }
            }

        // Moves a song to a new position in the playlist
        } else if(action.find("move") != std::string::npos){
            // Song always starts at index 5
            pos = 5;
            // Calculates the length of the song name (excluding "move" and the final index)
            int endNum = action.size()- pos - std::to_string(numberAtEnd(action)).size()-1;
            // The target position in the playlist
            int indexAtEnd = numberAtEnd(action);
            std::string mover = action.substr(pos, endNum);

            // Checks if the song is in the playlist
            if(inPlaylist(playlist, mover)){
                int tempPos = 0;
                for(int i = 0; i < playlist.size(); i++){
                    std::string temp = withoutCurrent(playlist[i]);
                    if(mover == temp){
                        tempPos = i;
                        break;
                    }
                }
                // Removes the song from its current position and inserts it at the new position
                std::string movedSong = playlist[tempPos];
                playlist.erase(playlist.begin() + tempPos);
                playlist.insert(playlist.begin() + indexAtEnd - 1, movedSong);
            }

        // Moves to the next song in the playlist
        } else if(action.find("next") != std::string::npos){
            for(int i = 0; i < playlist.size(); i++){
                if(playlist[i].find(" current") != std::string::npos){
                    // Finds the index of the "current" marker in the song
                    int currI = playlist[i].find(" current");
                    playlist[i] = playlist[i].substr(0, currI);
                    // If at the end of the playlist, loop back to the first song
                    if(i == playlist.size() - 1){
                        playlist[0] = playlist[0] + " current";
                    } else {
                        playlist[i + 1] = playlist[i + 1] + " current";
                    }
                    i++;
                    break;
                }
            }

        // Moves to the previous song in the playlist
        } else if(action.find("previous") != std::string::npos){
            for(int i = 0; i < playlist.size(); i++){
                if(playlist[i].find(" current") != std::string::npos){
                    // Finds the index of the "current" marker in the song
                    int currI = playlist[i].find(" current");
                    playlist[i] = playlist[i].substr(0, currI);
                    // If at the beginning of the playlist, loop back to the last song
                    if(i == 0){
                        playlist[playlist.size() - 1] = playlist[playlist.size() - 1] + " current";
                    } else {
                        playlist[i - 1] = playlist[i - 1] + " current";
                    }
                    i++;
                    break;
                }
            }
        }
    }

    // Writes the final state of the playlist to the output file
    for(int i = 0; i < playlist.size(); i++){
        outputFile << playlist[i] << std::endl;
    }

    // Closes all file streams
    inputFileOP.close();
    inputFileOA.close();
    outputFile.close();
}
