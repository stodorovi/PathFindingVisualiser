#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/mdi.h"

#include "GridFrame.h"
#include "PathfindingAppConstants.h"

class MainFrame : public wxMDIParentFrame {

private:

	wxMenuBar *m_menuBar;

	wxToolBar *toolBar;

	void initMenuBar();

	void onMenuNew(wxCommandEvent &event);

	void onMenuExit(wxCommandEvent &event);

	void BindEvents();

public:

	MainFrame();
	~MainFrame();

};

#endif // !MAINFRAME_H