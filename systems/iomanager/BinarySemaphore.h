//
// Created by William Lees on 9/23/15.
//

#ifndef GENJIN_BINARYSEMAPHORE_H
#define GENJIN_BINARYSEMAPHORE_H

namespace Genjin {
    namespace Systems {
        namespace IOManager {


            class BinarySemaphore {
            public:
                /**
                 * Release the resource
                 */
                void p();

                /**
                 * Attempt to gain access to the resource. Thread will block
                 * if resource isn't free
                 */
                void v();

            private:
                bool m_IsFree;
            };

        }
    }
}


#endif //GENJIN_BINARYSEMAPHORE_H
