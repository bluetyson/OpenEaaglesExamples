//------------------------------------------------------------------------------
// Class: Factory
//------------------------------------------------------------------------------
#include "Factory.h"

#include "openeaagles/basic/Object.h"

#include "SimIoHandler.h"
#include "SimPlayer.h"
#include "SimStation.h"
#include "InstrumentPanel.h"

// class factories
#include "../shared/xZeroMQHandlers/Factory.h"
#include "openeaagles/basic/Factory.h"
#include "openeaagles/basicGL/Factory.h"
#include "openeaagles/gui/glut/Factory.h"
#include "openeaagles/dis/Factory.h"
#include "openeaagles/instruments/Factory.h"
#include "openeaagles/iodevice/Factory.h"
#include "openeaagles/otw/Factory.h"
#include "openeaagles/sensors/Factory.h"
#include "openeaagles/simulation/Factory.h"
#include "openeaagles/dynamics/Factory.h"

#include <cstring>

namespace oe {
namespace example {

Factory::Factory()
{}

basic::Object* Factory::createObj(const char* name)
{
    basic::Object* obj = nullptr;

    // Sim3 Station & IoHandler
    if ( std::strcmp(name, SimStation::getFactoryName()) == 0 ) {
        obj = new SimStation();
    }
     else if ( std::strcmp(name, SimIoHandler::getFactoryName()) == 0 ) {
        obj = new SimIoHandler();
    }

    // Sim3 Player
    else if ( std::strcmp(name, SimPlayer::getFactoryName()) == 0 ) {
        obj = new SimPlayer();
    }

    // InstrumentPanel
    else if ( std::strcmp(name, InstrumentPanel::getFactoryName()) == 0 ) {
        obj = new InstrumentPanel();
    }

   if (obj == nullptr) obj = xZeroMQHandlers::Factory::createObj(name);

   if (obj == nullptr) obj = otw::Factory::createObj(name);
   if (obj == nullptr) obj = dynamics::Factory::createObj(name);
   if (obj == nullptr) obj = sensor::Factory::createObj(name);
   if (obj == nullptr) obj = Simulation::Factory::createObj(name);
   if (obj == nullptr) obj = network::dis::Factory::createObj(name);
   if (obj == nullptr) obj = iodevice::Factory::createObj(name);
   if (obj == nullptr) obj = instruments::Factory::createObj(name);
   if (obj == nullptr) obj = BasicGL::Factory::createObj(name);
   if (obj == nullptr) obj = glut::Factory::createObj(name);
   if (obj == nullptr) obj = basic::Factory::createObj(name);

    return obj;
}

}  // end namespace example
}  // end namespace oe
