/**
 * 
 * AUTHOR:  W. Max Lees <max.lees@gmail.com>
 * DATE:    Sept. 13th, 2015    
 */

#include "StackAllocator.h"
#include "exception/OutOfMemoryException.h"
#include "../logging.h"
#include "exception/BadStackPointerException.h"

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            const int StackAllocator::DEFAULT_ALLOCATOR_STACK_SIZE = 256;

            StackAllocator::StackAllocator() {
                StackAllocator(DEFAULT_STACK_ALLOCATOR_SIZE);
            }

            StackAllocator::StackAllocator(unsigned int size) {
                this->m_pData = new byte[size];
                this->m_StackCapacity = size;
                this->m_CurrentStackTop = 0;
            }

            StackAllocator::~StackAllocator() {
                delete [] this->m_pData;
            }

            void* StackAllocator::alloc(unsigned int bytes) {
                // Check if there is enough memory left
                if (this->m_CurrentStackTop + bytes > this->m_StackCapacity) {
                    Exception::OutOfMemoryException outOfMemoryException;
                    throw outOfMemoryException;
                }

                // Get the location of the free data
                void* ptr = &this->m_pData[m_CurrentStackTop];

                // Advance the pointer
                this->m_CurrentStackTop += bytes;

                // Return the pointer
                return ptr;
            }

            void StackAllocator::rollBackToMarker(Marker marker) {
                // Sanity check
                if (this->m_CurrentStackTop < marker) {
                    Exception::BadStackPointerException badStackPointerException;
                    throw badStackPointerException;
                }

                this->m_CurrentStackTop = marker;
            }

            StackAllocator::Marker StackAllocator::getMarker() {
                return this->m_CurrentStackTop;
            }

            void StackAllocator::clear() {
                LOG_INFO("Clearing " << m_CurrentStackTop << " Bytes from StackAllocator")
                this->m_CurrentStackTop = 0;
            }

        }
    }
}
