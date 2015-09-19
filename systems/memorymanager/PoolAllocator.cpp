//
// Created by William Lees on 9/18/15.
//

#include "PoolAllocator.h"

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            PoolAllocator::PoolAllocator(unsigned int itemSize, unsigned int poolSize) {
                this->m_pPool = nullptr;

                for (int i = poolSize; i >= 0; --i) {
                    PoolAllocatorBlock *ptr = new PoolAllocatorBlock(itemSize);

                    // Add the block if it is blank
                    if (this->m_pPool == nullptr) {
                        this->m_pPool = ptr;
                    }

                    // Otherwise, insert the block to the front of the queue
                    else {
                        this->releasePoolItem(ptr);
                    }
                }
            }

            void PoolAllocator::releasePoolItem(PoolAllocatorBlock* ptr) {
                ptr->setNext(this->m_pPool);
                this->m_pPool = ptr;
            }

            PoolAllocatorBlock* PoolAllocator::getFreeBlock() {
                /* TODO
                 * if (we're out of memory) {
                 *     Exception::OutOfMemoryException outOfMemoryException;
                 *     throw outOfMemoryException;
                 * }
                 */

                // Get a handle on the next free block
                PoolAllocatorBlock* ptr = this->m_pPool;

                // Remove the block from the queue
                this->m_pPool = this->m_pPool->getNext();

                // Return the item
                return ptr;
            }

        }
    }
}
