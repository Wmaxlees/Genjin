//
// Created by William Lees on 9/18/15.
//

#ifndef GENJIN_POOLALLOCATORBLOCK_H
#define GENJIN_POOLALLOCATORBLOCK_H

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            class PoolAllocatorBlock {
            private:
                typedef unsigned char byte;

            public:
                /**
                 * Initialize the block to the specified memory block size
                 *
                 * Param blockSize - The size of data to be stored in the block
                 * this must be greater than the pointer size for the system
                 */
                explicit PoolAllocatorBlock(byte blockSize);

                /**
                 * Destroy the object
                 */
                ~PoolAllocatorBlock();

                /**
                 * Set a pointer to the next item in the memory pool
                 *
                 * Functionality is undefined when data is present in the
                 * data block
                 *
                 * Param ptr - The pointer to the next item
                 */
                void setNext(PoolAllocatorBlock* ptr);

                /**
                 * Get the pointer to the next item in the memory pool
                 *
                 * Functionality is undefined when data is present in the
                 * data block
                 */
                PoolAllocatorBlock* getNext();

                /**
                 * Get the data block
                 */
                void* getBlock();
            private:
                // Data
                byte *m_pData;
            };

        }
    }
}


#endif //GENJIN_POOLALLOCATORBLOCK_H
