/**
 * 
 * AUTHOR:  W. Max Lees <max.lees@gmail.com>
 * DATE:    Sept. 13th, 2015    
 */

#ifndef _H_STACK_ALLOCATOR
#define _H_STACK_ALLOCATOR

namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            /**
             * A single ended stack memory allocator. Should only be accessed
             * through the MemoryManagement module.
             */
            class StackAllocator {

            public:

                /**
                 * Marker that represents a location in the stack
                 */
                typedef unsigned int Marker;

                /**
                 * Constructor
                 *
                 * Uses the overloaded constructor StackAllocator(int) to
                 * initialize the instance with the default stack size
                 */
                StackAllocator();

                /**
                 * Constructor
                 *
                 * Initializes the stack with the specified size in bytes
                 */
                StackAllocator(unsigned int size);

                /**
                 * Destructor
                 *
                 * Frees the allocated memory from the stack
                 */
                ~StackAllocator();

                /**
                 * Allocate a new chunck of memory with the given size from
                 * the stack
                 *
                 * Param bytes = size in bytes of memory to allocate
                 */
                void* alloc(unsigned int bytes);

                /**
                 * Rolles back the stack to a specified pointer location
                 * deleting all the data above that marker
                 *
                 * Param marker = the marker to roll the stack back to
                 */
                void rollBackToMarker(Marker marker);

                /**
                 * Get the marker that points to the top of the stack
                 */
                Marker getMarker();

                /**
                 * Moves the stack pointer back to the bottom of the stack
                 * effectively rerolling the stack to the beginning.
                 */
                void clear();

            private:
                // Block of memory where the data is kept
                typedef unsigned char byte;
                byte* m_pData;

                // Location of the top of the stack
                Marker m_CurrentStackTop;
                Marker m_StackCapacity;

                // Default memory size
                const static int DEFAULT_ALLOCATOR_STACK_SIZE;

            };

        }
    }
}

#endif  // _H_STACK_ALLOCATOR
