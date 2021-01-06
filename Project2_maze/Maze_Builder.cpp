
using namespace std;
#include <iostream>
#include <fstream>
#include "Maze_Builder.hpp"
#include <tuple>
#include <utility>
#include<stack>

Maze_Builder::Maze_Builder(std::string inputFileName_Dict) {
    // open inputFileName and store its contents, which is a collection of
    // cells, one per line, in vector, "cells".

    CellStream.open(inputFileName_Dict);
    if(!CellStream.good()) throw "I/o error";
    
    string line; 
    vector<int>column;

    int r = 0;
    while (getline(CellStream, line)){
        vector<char> row;
        vector<bool> false_row;
        for(int c = 0; c < line.length(); c++){
            row.push_back(line.at(c));
            false_row.push_back(false);
           
        }
        cells.push_back(row);
        used.push_back(false_row);
        r++;
    }

    for (int y =0; y<cells.size(); y++){
        char front = cells[y].front();
        if(front == '0'){
            StartCell = make_pair(y, 0);
        }

    }

    for (int y_2 = 0; y_2<cells.size(); y_2++){
        char back = cells[y_2].back();
        if(back == '0'){
            TargetCell = make_pair(y_2, cells[0].size()-1);
        }

    }
    int StartCell_var_row = StartCell.first;
    int StartCell_var_column = StartCell.second;
    int TargetCell_var_row = TargetCell.first;
    int TargetCell_var_column = TargetCell.second;

    std::cout<<"created cell vector with"<<cells.size();
    std::cout << "Creating an instance of Maze_Builder with input file: " << inputFileName_Dict << std::endl;

      
}


Maze_Builder::~Maze_Builder() {
    // close the input stream if it was successfully opened.
    if(CellStream.is_open())
        CellStream.close();
}


pair<char, char> Maze_Builder::PositionalTest(int row_pos, int colum_pos){    
         if(cells.at(row_pos).at(colum_pos+1) == '0' && !used[row_pos][colum_pos+1]){  //to the right
            pair<char,char> Position_pair = make_pair(row_pos, colum_pos+1);
            return Position_pair;
         }
        if(cells.at(row_pos-1).at(colum_pos) == '0' && !used[row_pos-1][colum_pos]){// check above 
            pair<char,char> Position_pair = make_pair(row_pos-1, colum_pos);
            return Position_pair;
          }
        if(cells.at(row_pos+1).at(colum_pos) == '0' && !used[row_pos+1][colum_pos]){// check below
            pair<char,char> Position_pair = make_pair(row_pos+1, colum_pos);
            return Position_pair;
          }  
        if(cells.at(row_pos).at(colum_pos-1) == '0' && !used[row_pos][colum_pos-1]){ //to the left
            pair<char,char> Position_pair = make_pair(row_pos, colum_pos-1);
            return Position_pair;
          }
    
        pair<char,char> Position_pair = make_pair(cells.size(), cells.size());
        return Position_pair;
    }
    
stack<pair<char, char>>Maze_Builder::pathFromTo(){
    //add stacked pairs to get top coordinates
    stack<pair<char,char>> path_stack;
    int row = StartCell.first;
    int column = StartCell.second;
    path_stack.push( make_pair(row, column));
    
    while(!path_stack.empty()){
        int path_stack_row = path_stack.top().first;
        int path_stack_column = path_stack.top().second;
        pair<char, char> v = PositionalTest(path_stack_row, path_stack_column);
        int a = v.first;
        int b = v.second;
        if(a == cells.size()){
            used.at(path_stack_row).at(path_stack_column) = true;//if there is no successor set what you just used 
            path_stack.pop();            
        }
        else{
            path_stack.push(make_pair(a, b));
            used.at(a).at(b) = true;
            int d = TargetCell.first;
            int e = TargetCell.second;
            if(a == d && b == e){
                break;
            }

        }
    }
    return path_stack;
}

    vector<vector<char>>Maze_Builder::maze_path_generator(stack<pair<char,char>> path_stack){//put a stack tuple in here instead
        //while the stack is not empty
                //input blank spaces for every row column pair listed in path_cells_stack to cells vector
                //pop the stack each time 
        //once the stack is empty/ the path is completed return our newly formed cells vector
        while(!path_stack.empty()){
            cells.at(path_stack.top().first).at(path_stack.top().second) = ' ';
            path_stack.pop();
        }
    return cells; 
    }

    void Maze_Builder::printLadder(vector<vector<char>> cells){
        for(int row_3 = 0; row_3< cells.size(); row_3++){
            for(int column_4 = 0; column_4< cells[0].size(); column_4++){
                if(column_4 % 15 == 0){
                    cout<<endl;
                }
                cout<<cells[row_3][column_4];
            }
        }
    }
