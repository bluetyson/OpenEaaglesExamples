//------------------------------------------------------------------------------
// Class: TestStateMachine01
//------------------------------------------------------------------------------
#ifndef __TestStateMach_TestStateMachine01_H__
#define __TestStateMach_TestStateMachine01_H__

#include "openeaagles/basic/StateMachine.h"

namespace Eaagles {
namespace TestStateMach {

//------------------------------------------------------------------------------
// Class: TestStateMachine01
// Description: State Machine Test #1 -- 
//
//    Tests the standard state transition functions (e.g., next(), goTo(), call(),
//    and rtn()), as well as arguments passed and returned.   There's one common
//    state function that's using the standard 'switch' and 'case' statements to
//    select each state's specific code.
//
//------------------------------------------------------------------------------
class TestStateMachine01 : public Basic::StateMachine {
   DECLARE_SUBCLASS(TestStateMachine01,Basic::StateMachine)

public:
   enum { CALL_01 = 11, CALL_02 = 22 };

public:
   TestStateMachine01();

protected:
   // Basic::StateMachine protected interface function
   virtual void preStateProc(const LCreal dt);
   virtual void postStateProc(const LCreal dt);
   virtual unsigned short stateTable(
         const unsigned short cstate,
         const StateTableCode code,
         const LCreal dt=0
      );

private:
   // State specific functions
   void anyStateFunc(const LCreal dt);
};

} // End TestStateMach namespace
} // End Eaagles namespace

#endif	// __TestStateMach_TestStateMachine01_H__
