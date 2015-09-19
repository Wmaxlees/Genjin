//
// Created by William Lees on 9/19/15.
//

#ifndef GENJIN_CONFIGURATIONMANAGER_H
#define GENJIN_CONFIGURATIONMANAGER_H

#include "../System.h"
#include "enumerations/BoolConfigKey.h"

namespace Genjin {
    namespace Systems {

        class ConfigurationManager : public System {
        public:
            ConfigurationManager();
            ~ConfigurationManager();

            bool GetBoolConfig(Enumerations::BoolConfigKey key);

        private:
            // Configuration data
            bool m_aBoolConfigData[Enumerations::BoolConfigKey::LAST];

        };

    }
}


#endif //GENJIN_CONFIGURATIONMANAGER_H
