/**
 * 
 * AUTHOR:  W. Max Lees <max.lees@gmail.com>
 * DATE:    Sept. 13th, 2015    
 */

#ifndef _H_MEMORY_MANAGER
#define _H_MEMORY_MANAGER

#include "System.h"

namespace Genjin {
    namespace Systems {

        class MemoryManager : public System
        {
        public:
            void InitializeSystem();
            void ShutdownSystem();

        private:
            MemoryManager();
            ~MemoryManager();

        };

    }
}

#endif  // _H_MEMORY_MANAGER
