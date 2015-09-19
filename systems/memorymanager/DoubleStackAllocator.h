//
// Created by William Lees on 9/18/15.
//

#ifndef GENJIN_DOUBLESTACKALLOCATOR_H
#define GENJIN_DOUBLESTACKALLOCATOR_H
namespace Genjin {
    namespace Systems {
        namespace MemoryManager {

            class DoubleStackAllocator {
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
                DoubleStackAllocator();

                /**
                 * Constructor
                 *
                 * Initializes the stack with the specified size in bytes
                 */
                DoubleStackAllocator(unsigned int size);

                /**
                 * Destructor
                 *
                 * Frees the allocated memory from the stack
                 */
                ~DoubleStackAllocator();

                /**
                 * Allocate a new chunck of memory with the given size from
                 * the top of the stack
                 *
                 * Param bytes = size in bytes of memory to allocate
                 */
                void *topAlloc(unsigned int bytes);

                /**
                 * Allocate a new chunck of memory with the given size from
                 * the bottom of the stack
                 *
                 * Param bytes = size in bytes of memory to allocate
                 */
                void *bottomAlloc(unsigned int bytes);

                /**
                 * Rolls back the top stack to a specified pointer location
                 * deleting all the data above that marker
                 *
                 * Param marker = the marker to roll the stack back to
                 */
                void topRollBackToMarker(Marker marker);

                /**
                 * Rolls back the bottom stack to a specified pointer location
                 * deleting all the data above that marker
                 *
                 * Param marker = the marker to roll the stack back to
                 */
                void bottomRollBackToMarker(Marker marker);

                /**
                 * Get the marker that points to the top of the stack
                 */
                Marker topGetMarker();

                Marker bottomGetMarker();

                /**
                 * Moves the stack pointer back to the bottom of the stack
                 * effectively rerolling the stack to the beginning.
                 */
                void clear();

                void topClear();

                void bottomClear();

            private:
                // Block of memory where the data is kept
                typedef unsigned char byte;
                byte *m_pData;

                // Location of the top of the stack
                Marker m_CurrentStackTopMarker;
                Marker m_CurrentStackBottomMarker;
                Marker m_StackCapacity;

                // Default memory size
                const static int DEFAULT_DOUBLE_ALLOCATOR_STACK_SIZE;

            };

        }
    }
}


#endif //GENJIN_DOUBLESTACKALLOCATOR_H
