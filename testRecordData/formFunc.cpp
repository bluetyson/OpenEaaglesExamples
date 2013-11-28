//------------------------------------------------------------------------------
// Form function
//------------------------------------------------------------------------------
#include "formFunc.h"

#include "TestDisplay.h"
#include "TestIoHandler.h"
#include "SimStation.h"

#include "myRecorder/formFunc.h"
#include "xPanel/formFunc.h"

#include "openeaagles/basic/basicFF.h"
#include "openeaagles/basicGL/basicGLFF.h"
#include "openeaagles/gui/glut/glutFF.h"
#include "openeaagles/dis/disFF.h"
#include "openeaagles/instruments/instrumentsFF.h"
#include "openeaagles/ioDevice/ioDeviceFF.h"
#include "openeaagles/otw/otwFF.h"
#include "openeaagles/recorder/recorderFF.h"
#include "openeaagles/sensors/sensorsFF.h"
#include "openeaagles/simulation/simulationFF.h"
#include "openeaagles/vehicles/vehiclesFF.h"


namespace Eaagles {
namespace TestRecordData {

Basic::Object* formFunc(const char* formname)
{
    Basic::Object* newform = 0;

    if ( strcmp(formname, SimStation::getFormName()) == 0 ) {
        newform = new SimStation();
    }
    else if ( strcmp(formname, TestDisplay::getFormName()) == 0 ) {
        newform = new TestDisplay();
    }
    else if ( strcmp(formname, TestIoHandler::getFormName()) == 0 ) {
        newform = new TestIoHandler();
    }

    // Example libraries
    if (newform == 0) newform = MyRecorder::formFunc(formname);
    if (newform == 0) newform = xPanel::formFunc(formname);

    // OpenEaagles packages
    if (newform == 0) newform = Eaagles::Simulation::simulationFormFunc(formname);
    if (newform == 0) newform = Instruments::instrumentsFormFunc(formname);
    if (newform == 0) newform = IoDevice::ioDeviceFormFunc(formname);
    if (newform == 0) newform = Instruments::instrumentsFormFunc(formname);
    if (newform == 0) newform = Vehicle::vehiclesFormFunc(formname);
    if (newform == 0) newform = Recorder::recorderFormFunc(formname);
    if (newform == 0) newform = Sensor::sensorsFormFunc(formname);
    if (newform == 0) newform = Otw::otwFormFunc(formname);
    if (newform == 0) newform = Network::Dis::disFormFunc(formname);
    if (newform == 0) newform = BasicGL::basicGLFormFunc(formname);
    if (newform == 0) newform = Glut::glutFormFunc(formname);
    if (newform == 0) newform = Basic::basicFormFunc(formname);
    return newform;
}

} // End TestRecordData namespace
} // End Eaagles namespace
