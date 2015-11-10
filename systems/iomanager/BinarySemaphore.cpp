//
// Created by William Lees on 9/23/15.
//

#include "BinarySemaphore.h"

#include <thread>

namespace Genjin {
    namespace Systems {
        namespace IOManager {

            void BinarySemaphore::p() {
                // Free the resource
                this->m_IsFree = true;
            }

            void BinarySemaphore::v() {
                // Check if the resource is free and pause while it is not
                while (!this->m_IsFree) {
                    std::this_thread::sleep_for(1000000000);
                }

                // Claim the resource
                this->m_IsFree = false;
            }

        }
    }
}
