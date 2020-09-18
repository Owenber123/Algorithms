//
//  main.cpp
//  Assignment 5B
//
//  Created by Owen Beringer on 12/6/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "main.hpp"
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

int main()
{
    vector<string> mazes = {"maze1.txt","maze2.txt","maze3.txt"};
    
    ifstream fin;
    
    for (int i = 0; i < 3; i++){
        
        // Read the maze from the file.
        string fileName = mazes[i];
    
        fin.open(fileName.c_str());
        if (!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }
    
        try
        {
            graph g;
            while (fin && fin.peek() != 'Z')
            {
                maze m(fin);
                m.mapMazeToGraph(g);
                int dest = m.getMap(m.rows - 1, m.cols - 1);
                cout << "Destination = " <<  dest << endl;
                dfs(g, dest);
                cout << "Path = " << endl;
                while(!dfsStack.empty())
                {
                    cout << dfsStack.top() << endl;
                    dfsStack.pop();
                }
            }
        }
        catch (indexRangeError &ex)
        {
            cout << ex.what() << endl;
            exit(1);
        }
        catch (rangeError &ex)
        {
            cout << ex.what() << endl;
            exit(1);
        }
        fin.close();
        cout << "\n\n\n\n\n";
    }
}
