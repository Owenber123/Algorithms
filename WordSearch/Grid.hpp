//
//  Grid.hpp
//  Assignment3A
//
//  Created by Owen Beringer on 10/23/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "d_matrix.hpp"

class Grid{
    
public:
    void read_letters();
    matrix<string> mat;
private:
    int width;
    int length;
};

#endif /* Grid_hpp */
