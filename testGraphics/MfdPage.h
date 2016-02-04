//------------------------------------------------------------------------------
// Class: MfdPage
//
// Description: Example MFD page
//------------------------------------------------------------------------------
#ifndef __oe_example_MfdPage_H__
#define __oe_example_MfdPage_H__

#include "openeaagles/graphics/Page.h"

namespace oe {
namespace example {

class MfdPage : public graphics::Page {
   DECLARE_SUBCLASS(MfdPage,graphics::Page)

public:
   MfdPage();

   bool onEntry() override;

   bool event(const int event, basic::Object* const obj = nullptr) override;
   void updateData(const LCreal dt = 0.0) override;

private:
    LCreal rotate;
    LCreal rotateRate;
    SendData rSD;
};

} // End example namespace
} // End oe namespace

#endif
