
#include "factory.h"

#include "openeaagles/base/Object.h"

#include "TestDisplay.h"
#include "TestStation.h"
#include "DspRadar.h"
#include "DspRwr.h"
#include "TdAzPtr.h"
#include "TdElevPtr.h"

#include "openeaagles/simulation/factory.h"
#include "openeaagles/models/factory.h"
#include "openeaagles/networks/dis/factory.h"
#include "openeaagles/instruments/factory.h"
#include "openeaagles/graphics/factory.h"
#include "openeaagles/gui/glut/factory.h"
#include "openeaagles/base/factory.h"

#include <cstring>

namespace oe {
namespace test {

base::Object* factory(const char* name)
{
    base::Object* obj = nullptr;

    if ( std::strcmp(name, TestStation::getFactoryName()) == 0 ) {
        obj = new TestStation();
    }
    else if ( std::strcmp(name, TestDisplay::getFactoryName()) == 0 ) {
        obj = new TestDisplay();
    }
    else if ( std::strcmp(name, DspRadar::getFactoryName()) == 0 ) {
        obj = new DspRadar();
    }
    else if ( std::strcmp(name, DspRwr::getFactoryName()) == 0 ) {
        obj = new DspRwr();
    }
    else if ( std::strcmp(name, TdAzPtr::getFactoryName()) == 0 ) {
        obj = new TdAzPtr();
    }
    else if ( std::strcmp(name, TdElevPtr::getFactoryName()) == 0 ) {
        obj = new TdElevPtr();
    }

    if (obj == nullptr) obj = simulation::factory(name);
    if (obj == nullptr) obj = models::factory(name);
    if (obj == nullptr) obj = instruments::factory(name);
    if (obj == nullptr) obj = dis::factory(name);
    if (obj == nullptr) obj = graphics::factory(name);
    if (obj == nullptr) obj = glut::factory(name);
    if (obj == nullptr) obj = base::factory(name);

    return obj;
}

}
}