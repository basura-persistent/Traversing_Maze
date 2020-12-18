//
// Created by Ali A. Kooshesh on 2020-01-20.
//
using namespace std;

#include<iostream>
#include <algorithm>
#include"Maze_Builder.hpp"
#include<stack>


int main(int argc, char *argv[]) { // the main function.
    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " inputFileNameThatContainsDictionary inputFileNameThatContainsPairsOfWords\n"; // arg[0] gives us the item or foler in compiler
        exit(1);
    }

    std::ifstream CellStream;
    CellStream.open(argv[1], std::ios_base::in);
    if( ! CellStream.is_open()) {
        std::cout << "Unable to open input file ->" << argv[1] << "<-\n";
        exit(2);
    }
    std::cout << "Successfully opened " << argv[1] << std::endl;
    // we just wanted to make sure that the input file exists. So, close it
    // and let the instance of Dictionary open and use it.
    CellStream.close();

    
    Maze_Builder maze_builder(argv[1]);
   
    vector<vector<char>> path_vector = maze_builder.maze_path_generator(maze_builder.pathFromTo());
    if(!path_vector.empty()){
        maze_builder.printLadder(path_vector);
    }
    else{
        cout<<"No path was found in the maze:(";
    }
    

    return 0;
}
