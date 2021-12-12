#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/mdi.h"

#include "GridFrame.h"
#include "MainFrameConstants.h"
#include "MainFrameView.h"
#include "NodeTypeButtonSelectionProcessor.h"
#include "PlaceableNodeType.h"

class MainFrame : public wxMDIParentFrame {

private:

	PlaceableNodeType  m_currentNodeType;

	MainFrameView m_view;

	void onMenuNew(wxCommandEvent &event);

	void onMenuExit(wxCommandEvent &event);

	void onRunAlgorithmBtnSelected(wxCommandEvent &event);

	void onNodeBtnSelected(wxCommandEvent &event);

	void onChildWindowFocusChange(wxChildFocusEvent &event);

	void onClearGridBtnSelected(wxCommandEvent &event);

	void BindEvents();

public:

	MainFrame();

	~MainFrame();

	PlaceableNodeType& getCurrentNodeType();

	MainFrameView& getView();

};

#endif // !MAINFRAME_H