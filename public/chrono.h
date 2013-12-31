//
//  chrono.h
//  std2
//
//  Created by Jonas Vanthornhout on 22/12/13.
//  Copyright (c) 2013 Jonas Vanthornhout. All rights reserved.
//

#ifndef std2_chrono_h
#define std2_chrono_h

/* The classes below are exported */
#pragma GCC visibility push(default)

#include <chrono>

namespace std2 {
    namespace chrono {
        typedef std::chrono::time_point<std::chrono::system_clock> timepoint;
        
        inline
        timepoint now(){
            return std::chrono::system_clock::now();
        }
        
        template <typename U = std::chrono::milliseconds>
        size_t diff(const timepoint &start, const timepoint &end){
            return std::chrono::duration_cast<U>(end-start).count();
        }
    }
}

#pragma GCC visibility pop

#endif
