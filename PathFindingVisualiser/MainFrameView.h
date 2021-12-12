#ifndef MAIN_FRAME_VIEW
#define MAIN_FRAME_VIEW

#include "wx/button.h"
#include "wx/imagpng.h"
#include "wx/mdi.h"
#include "wx/accel.h"
#include "wx/toolbar.h"

#include "MainFrameViewConstants.h"
#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class MainFrame;

class MainFrameView {

private:

	MainFrame		  *m_mainFrame;

	wxMenuBar         *m_menuBar;

	wxMenu            *m_menuFile;
	wxMenuItem        *m_menuFileNew;
	wxMenuItem        *m_menuFileExit;

	wxToolBar         *m_toolBar;

	wxButton          *m_RunAlgorithmBtn;
	wxBitmap           m_runAlgorithmImage;

	wxBitmap           m_startNodeImage;
	wxToolBarToolBase *m_startNodeBtn;

	wxBitmap           m_endNodeImage;
	wxToolBarToolBase *m_endNodeBtn;

	wxBitmap           m_blockNodeImage;
	wxToolBarToolBase *m_blockNodeBtn;

	wxBitmap           m_eraseNodeImage;
	wxToolBarToolBase *m_eraseNodeBtn;

	wxBitmap           m_newGridImage;
	wxToolBarToolBase *m_newGridBtn;

	wxBitmap           m_clearGridImage;
	wxToolBarToolBase *m_clearGridBtn;

	void initMenuBar();

	void initToolBar();

public:

	MainFrameView(MainFrame* mainFrame);

	wxMenuBar* getMenuBar() const;

	wxMenu* getMenuFile() const;
	wxMenuItem* getMenuFileNew() const;
	wxMenuItem* getMenuFileExit() const;

	wxToolBar* getToolBar() const;

	wxButton* getRunAlgorithmBtn() const;

	wxToolBarToolBase* getStartNodeBtn() const;
	wxToolBarToolBase* getEndNodeBtn() const;
	wxToolBarToolBase* getBlockNodeBtn() const;
	wxToolBarToolBase* getEraseNodeBtn() const;

	wxToolBarToolBase* getNewGridBtn() const;

	wxToolBarToolBase* getClearGridBtn() const;

};

#endif // !MAIN_FRAME_VIEW