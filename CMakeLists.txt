cmake_minimum_required(VERSION 3.3)
project(genjin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp systems/memorymanager/MemoryManager.cpp systems/memorymanager/MemoryManager.h systems/System.h systems/memorymanager/StackAllocator.cpp systems/memorymanager/StackAllocator.h systems/logging.h systems/memorymanager/exception/OutOfMemoryException.h systems/memorymanager/DoubleStackAllocator.cpp systems/memorymanager/DoubleStackAllocator.h systems/memorymanager/exception/BadStackPointerException.h systems/memorymanager/PoolAllocator.cpp systems/memorymanager/PoolAllocator.h systems/memorymanager/PoolAllocatorBlock.cpp systems/memorymanager/PoolAllocatorBlock.h systems/memorymanager/exception/BlockTooSmallException.h systems/configurationmanager/ConfigurationManager.cpp systems/configurationmanager/ConfigurationManager.h systems/configurationmanager/exception/BadConfigKeyException.h systems/configurationmanager/exception/BadConfigKeyException.h systems/configurationmanager/enumerations/BoolConfigKey.h systems/iomanager/BinarySemaphore.cpp systems/iomanager/BinarySemaphore.h)
add_executable(genjin ${SOURCE_FILES})