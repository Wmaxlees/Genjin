//
// Created by William Lees on 9/19/15.
//

#include "ConfigurationManager.h"
#include "exception/BadConfigKeyException.h"

namespace Genjin {
    namespace Systems {

        ConfigurationManager::ConfigurationManager() {

        }

        ConfigurationManager::~ConfigurationManager() {

        }

        bool ConfigurationManager::GetBoolConfig(Enumerations::BoolConfigKey key) {
            // Sanity check
            if (key >= Enumerations::BoolConfigKey::LAST) {
                Exception::BadConfigKeyException badConfigKeyException;
                throw badConfigKeyException;
            }

            return this->m_aBoolConfigData[key];
        }

    }
}