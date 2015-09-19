//
// Created by William Lees on 9/18/15.
//

// TODO: WE NEED SOME WAY OF KNOWING WE'VE RAN OUT OF BLOCKS
// TODO: CREATE A SMART POINTER CLASS THAT CAN IMPLEMENT DEFRAGMENTATION
// TODO: UNIT TESTING


#ifndef GENJIN_POOLALLOCATOR_H
#define GENJIN_POOLALLOCATOR_H

#include "PoolAllocatorBlock.h"

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            class PoolAllocator {
            public:
                /**
                 * Create the PoolAllocator with the specified # of bytes per block and
                 * the size of the pool
                 *
                 * Params itemSize - the # of bytes per block
                 * Params poolSize - the # of blocks in the pool
                 */
                explicit PoolAllocator(unsigned int itemSize, unsigned int poolSize);

                /**
                 * Release a block back to the pool
                 *
                 * Params block - Pointer to the freed block
                 */
                void releasePoolItem(PoolAllocatorBlock* ptr);

                /**
                 * Get a free block
                 */
                PoolAllocatorBlock* getFreeBlock();

            private:
                // Memory
                PoolAllocatorBlock *m_pPool;

            };

        }
    }
}


#endif //GENJIN_POOLALLOCATOR_H
