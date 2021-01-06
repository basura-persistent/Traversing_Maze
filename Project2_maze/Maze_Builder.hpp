

#ifndef GENERALBACKBONEPROGRAMS_DICTIONARY_HPP
#define GENERALBACKBONEPROGRAMS_DICTIONARY_HPP

#include<iostream>
#include<fstream>
#include<vector>
#include<tuple>
#include<stack>
#include<algorithm>
#include <utility>
using namespace std;

class Maze_Builder {
public:
    Maze_Builder(std::string inputFileName_Dict);
    stack<pair<char, char>>pathFromTo();
    vector<vector<char>>maze_path_generator(stack<pair<char,char>> path_stack);
    // member returns the index of "word" in "words"
    // if "word" is not a member of the dictionary, it
    // returns size(). Size is an indicator that the word is not in the dictionary. See comments for idxOfSuccessorWordFrom
    // to learn how you would use the index that this function returns.
    void printLadder(vector<vector<char>> maze_path_vector);
    pair<char, char> IsAdjacentTo(char row, char column);

    


    ~Maze_Builder();

private:
    pair<int,int> Isadjacent_tuple;
    std::pair<int,int> adjacent_row_column;
    std::vector<std::vector<char>> cells;
    std::vector<vector<bool>> used;
    vector<vector<char>> coordinates_path;
    std::ifstream Maze_BuilderStream;  // use it to open the input file.
    std::ifstream CellStream;
    std::pair<char,char> StartCell;
    std::pair<char,char> TargetCell;
    
    //This function, when called with a word that is in the dictionary 
    //(let's say fate), goes through a loop and for each dictionary word,  
    //uses positionalDiff to determine if it is a neighbor of the given word (fate) 
    //or not. If it is a neighbor, it adds it to a vector. Once finished, the function
    //returns the vector.
    
    // positionalDiff calculates and returns the number of positions
    // where its two arguments differ. For example, it will return
    // 2 if bell and bowl were passed to it (e and o; l and w).
        //adjacent means there is a cell to the left right, bottom, or above it.
        //if the current point from maze and the current point from our path shows adjacency return 1
        //else zero
    pair<char, char> PositionalTest(int row, int column); 


    //finds possible adjacency points that we can explore for each 0 and will check if cell has already been used

    // This function finds a adjacent point to our current point that we havent explored yet.  
    // function returns size(), the number of words in the dictionary.
    // usage:
    // int idx = isAdjacentTo("bell", 5);
    // if( idx == size() ) {
    //     there was not a successor word for "bell" starting with
    //     words[5]
    // } else {
    //     words[idx] is a successor for "bell".
    // }


    void resetPath(); // this function sets all elements of array "used" to false.
    void resetLadder(stack<string> ladder_stack);
    void printCells();
    };


#endif //GENERALBACKBONEPROGRAMS_DICTIONARY_HPP
