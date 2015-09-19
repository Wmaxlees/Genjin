//
// Created by William Lees on 9/19/15.
//

#ifndef GENJIN_CONFIGURATIONMANAGER_H
#define GENJIN_CONFIGURATIONMANAGER_H

#include "System.h"

namespace Genjin {
    namespace Systems {

        class ConfigurationManager : public System {
        public:
            ConfigurationManager();
            ~ConfigurationManager();

            enum BoolConfigKey {
                // GRAPHICS
                GRAPHICS_FULLSCREEN = 0,

                BOOL_CONFIG_NULL
            };

            bool GetBoolConfig(BoolConfigKey key);

        private:
            // Configuration data
            bool m_aBoolConfigData[BOOL_CONFIG_NULL];

        };

    }
}


#endif //GENJIN_CONFIGURATIONMANAGER_H
