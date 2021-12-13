#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/mdi.h"

#include "GridFrame.h"
#include "MainFrameConstants.h"
#include "MainFrameView.h"
#include "NodeTypeButtonSelectionProcessor.h"
#include "PlaceableNodeType.h"

/** @brief Main presenter. Defines the logic behind controls. */
class MainFrame : public wxMDIParentFrame {

private:

	PlaceableNodeType  m_currentNodeType;

	MainFrameView m_view;

	/**
	 * @brief Creates new grid sub-window.
	 * @param event 
	*/
	void onMenuNew(wxCommandEvent &event);

	/**
	 * @brief Exits the application.
	 * @param event 
	*/
	void onMenuExit(wxCommandEvent &event);

	/**
	 * @brief Runs the algorithm visualisation.
	 * @param event 
	*/
	void onRunAlgorithmBtnSelected(wxCommandEvent &event);

	/**
	 * @brief Sets the selected node type for placement.
	 * @param event 
	*/
	void onNodeBtnSelected(wxCommandEvent &event);

	/**
	 * @brief Changes the focused childs window current node type to the main window current type.
	 * @param event 
	*/
	void onChildWindowFocusChange(wxChildFocusEvent &event);

	/**
	 * @brief Clears the entire grid.
	 * @param event 
	*/
	void onClearGridBtnSelected(wxCommandEvent &event);

	/** @brief Bind buttons and other controls. */
	void BindEvents();

public:

	/** @brief Constructor. */
	MainFrame();

	/** @brief Destructor. */
	~MainFrame();

	/**
	 * @brief currentNodeType getter.
	 * @return the currentNodeType
	*/
	PlaceableNodeType& getCurrentNodeType();

	/**
	 * @brief view getter.
	 * @return the view.
	*/
	MainFrameView& getView();

};

#endif // !MAINFRAME_H