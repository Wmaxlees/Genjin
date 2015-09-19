//
// Created by William Lees on 9/18/15.
//

#include "DoubleStackAllocator.h"
#include "exception/OutOfMemoryException.h"
#include "exception/BadStackPointerException.h"

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            DoubleStackAllocator::DoubleStackAllocator() {
                DoubleStackAllocator(DEFAULT_DOUBLE_ALLOCATOR_STACK_SIZE);
            }

            /**
             * Constructor
             *
             * Initializes the stack with the specified size in bytes
             */
            DoubleStackAllocator::DoubleStackAllocator(unsigned int size) {
                this->m_pData = new byte[size];
                this->m_StackCapacity = size;
                this->m_CurrentStackBottomMarker = 0;
                this->m_CurrentStackTopMarker = size;
            }

            DoubleStackAllocator::~DoubleStackAllocator() {
                delete [] m_pData;
            }

            void *DoubleStackAllocator::topAlloc(unsigned int bytes) {
                // Check if there is enough space
                if (this->m_CurrentStackTopMarker - bytes < this->m_CurrentStackBottomMarker) {
                    Exception::OutOfMemoryException outOfMemoryException;
                    throw outOfMemoryException;
                }

                // Generate the space
                void *ptr = &this->m_pData[this->m_CurrentStackTopMarker-bytes];
                this->m_CurrentStackTopMarker -= bytes;

                return ptr;
            }

            void *DoubleStackAllocator::bottomAlloc(unsigned int bytes) {
                // Check if there is enough space
                if (this->m_CurrentStackBottomMarker + bytes > m_CurrentStackTopMarker) {
                    Exception::OutOfMemoryException outOfMemoryException;
                    throw outOfMemoryException;
                }

                // Generate the space
                void *ptr = &this->m_pData[this->m_CurrentStackBottomMarker];
                this->m_CurrentStackBottomMarker += bytes;

                return ptr;
            }

            void DoubleStackAllocator::topRollBackToMarker(Marker marker) {
                // Sanity check
                if (this->m_CurrentStackTopMarker > marker) {
                    Exception::BadStackPointerException badStackPointerException;
                    throw badStackPointerException;
                }

                this->m_CurrentStackTopMarker = marker;
            }

            void DoubleStackAllocator::bottomRollBackToMarker(Marker marker) {
                // Sanity check
                if (this->m_CurrentStackBottomMarker < marker) {
                    Exception::BadStackPointerException badStackPointerException;
                    throw badStackPointerException;
                }

                this->m_CurrentStackBottomMarker = marker;
            }

            DoubleStackAllocator::Marker DoubleStackAllocator::topGetMarker() {
                return this->m_CurrentStackTopMarker;
            }

            DoubleStackAllocator::Marker DoubleStackAllocator::bottomGetMarker() {
                return this->m_CurrentStackBottomMarker;
            }

            void DoubleStackAllocator::clear() {
                this->m_CurrentStackBottomMarker = 0;
                this->m_CurrentStackTopMarker = this->m_StackCapacity;
            }

            void DoubleStackAllocator::topClear() {
                this->m_CurrentStackTopMarker = this->m_StackCapacity;
            }

            void DoubleStackAllocator::bottomClear() {
                this->m_CurrentStackBottomMarker = 0;
            }

        }
    }
}