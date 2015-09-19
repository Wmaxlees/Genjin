//
// Created by William Lees on 9/18/15.
//

#include "PoolAllocatorBlock.h"

#include "exception/BlockTooSmallException.h"

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            PoolAllocatorBlock::PoolAllocatorBlock(byte blockSize) {
                // Make sure block size is large enough to hold pointer
                if (sizeof(this->m_pData) < blockSize) {
                    Exception::BlockTooSmallException blockTooSmallException;
                    throw blockTooSmallException;
                }

                // Allocate the memory
                this->m_pData = new byte[blockSize];
            }

            PoolAllocatorBlock::~PoolAllocatorBlock() {
                delete [] this->m_pData;
            }

            void PoolAllocatorBlock::setNext(PoolAllocatorBlock *ptr) {
                *this->m_pData = (long)ptr;
            }

            PoolAllocatorBlock *PoolAllocatorBlock::getNext() {
                // TODO: TEST BOTH OF THESE
                // return (PoolAllocatorBlock*)(*this->m_pData);

                long ptrData = (long)this->m_pData[0] << 56;
                ptrData |= (long)this->m_pData[1] << 48;
                ptrData |= (long)this->m_pData[2] << 40;
                ptrData |= (long)this->m_pData[3] << 32;
                ptrData |= (long)this->m_pData[4] << 24;
                ptrData |= (long)this->m_pData[5] << 16;
                ptrData |= (long)this->m_pData[6] << 8;
                ptrData |= (long)this->m_pData[7];

                return (PoolAllocatorBlock*)ptrData;

            }

            void *PoolAllocatorBlock::getBlock() {
                return this->m_pData;
            }

        }
    }
}