/**
 * 
 * AUTHOR:  W. Max Lees <max.lees@gmail.com>
 * DATE:    Sept. 13th, 2015    
 */

#ifndef _H_SYSTEM
#define _H_SYSTEM

namespace Genjin {
    namespace Systems {

        class System {

        public:
            virtual void InitializeSystem() = 0;
            virtual void ShutdownSystem() = 0;

        protected:
            System() {}
            ~System() {}

        };

    }
}


#endif  // _H_SYSTEM
