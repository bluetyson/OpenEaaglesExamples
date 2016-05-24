
#ifndef __TestWindow_H__
#define __TestWindow_H__

//-------------------------------------------------------
// Class: TestWindow
//
// Description: Event Handler Object
//-------------------------------------------------------
class TestWindow : public FXMainWindow
{
   FXDECLARE(TestWindow)

private:

   FXGLCanvas* glcanvas;         // GL Canvas to draw into
   FXRealSpinner* speedcontrol;  // Spinner for speed
   FXGLVisual* glvisual;         // OpenGL visual
   FXdouble rts;
   FXTime lasttime;
   int spinning;                 // Is box spinning
   double angle;                 // Rotation angle of box
   FXDataTarget dt_rts;

protected:
   TestWindow() {}

public:

   // We define additional ID's, starting from the last one used by the base class+1.
   // This way, we know the ID's are all unique for this particular target.
   enum {
     ID_CANVAS=FXMainWindow::ID_LAST,
     ID_SPIN,
     ID_SPINFAST,
     ID_STOP,
     ID_TIMEOUT,
     ID_CHORE,
     ID_MULTISAMPLE_OFF,
     ID_MULTISAMPLE_2X,
     ID_MULTISAMPLE_4X,
     ID_SPEED
   };

   // Message handlers
   long onMouseDown(FXObject*, FXSelector, void*);
   long onMouseUp(FXObject*, FXSelector, void*);
   long onMouseMove(FXObject*, FXSelector, void*);
   long onExpose(FXObject*, FXSelector, void*);
   long onConfigure(FXObject*, FXSelector, void*);
   long onCmdSpin(FXObject*, FXSelector, void*);
   long onUpdSpin(FXObject*, FXSelector, void*);
   long onCmdStop(FXObject*, FXSelector, void*);
   long onUpdStop(FXObject*, FXSelector, void*);
   long onTimeout(FXObject*, FXSelector, void*);
   long onChore(FXObject*, FXSelector, void*);
   long onCmdSpinFast(FXObject*, FXSelector, void*);
   long onUpdSpinFast(FXObject*, FXSelector, void*);
   long onCmdMultiSample(FXObject*, FXSelector, void*);
   long onUpdMultiSample(FXObject*, FXSelector, void*);
   long onUpdSpeed(FXObject*, FXSelector, void*);

public:

   TestWindow(FXApp* a);

   // initialize
   void create();

   void drawScene();

   virtual ~TestWindow();
};

#endif
