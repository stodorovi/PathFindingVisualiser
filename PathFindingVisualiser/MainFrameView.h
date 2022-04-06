#ifndef MAIN_FRAME_VIEW
#define MAIN_FRAME_VIEW

#include "wx/button.h"
#include "wx/combobox.h"
#include "wx/imagpng.h"
#include "wx/mdi.h"
#include "wx/toolbar.h"

#include "MainFrameViewConstants.h"
#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class MainFrame;

/** @brief Main frame view. Defines the look of the main frame. */
class MainFrameView {

private:

	MainFrame		  *m_mainFrame;

	wxMenuBar         *m_menuBar;

	wxMenu            *m_menuFile;
	wxMenuItem        *m_menuFileNew;
	wxMenuItem        *m_menuFileExit;

	wxToolBar         *m_toolBar;

	wxBitmap           m_newGridImage;
	wxToolBarToolBase *m_newGridBtn;

	wxComboBox        *m_algorithmComboBox;

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

	wxBitmap           m_clearGridImage;
	wxToolBarToolBase *m_clearGridBtn;

	/** @brief Initialise the menu bar and its elements. */
	void initMenuBar();

	/** @brief Initialise the tool bar and its elements. */
	void initToolBar();

public:

	/**
	 * @brief Constructor.
	 * @param mainFrame - frame to define the look for.
	*/
	MainFrameView(MainFrame* mainFrame);

	/**
	 * @brief menuBar getter.
	 * @return wxMenuBar*
	*/
	wxMenuBar* getMenuBar() const;

	/**
	 * @brief menuFile getter.
	 * @return the menuFile
	*/
	wxMenu* getMenuFile() const;

	/**
	 * @brief menuFileNew getter.
	 * @return the menuFileNew
	*/
	wxMenuItem* getMenuFileNew() const;

	/**
	 * @brief menuFileExit getter.
	 * @return the menuFileExit
	*/
	wxMenuItem* getMenuFileExit() const;

	/**
	 * @brief toolBar getter.
	 * @return the toolBar
	*/
	wxToolBar* getToolBar() const;

	/**
	 * @brief runAlgorithmBtn getter.
	 * @return the runAlgorithmBtn
	*/
	wxButton* getRunAlgorithmBtn() const;

	/**
	 * @brief startNodeBtn getter.
	 * @return the startNodeBtn
	*/
	wxToolBarToolBase* getStartNodeBtn() const;

	/**
	 * @brief endNodeBtn getter.
	 * @return the endNodeBtn
	*/
	wxToolBarToolBase* getEndNodeBtn() const;

	/**
	 * @brief blockNodeBtn getter.
	 * @return the blockNodeBtn
	*/
	wxToolBarToolBase* getBlockNodeBtn() const;

	/**
	 * @brief eraseNodeBtn getter.
	 * @return the eraseNodeBtn
	*/
	wxToolBarToolBase* getEraseNodeBtn() const;

	/**
	 * @brief newGridBtn getter.
	 * @return the newGridBtn
	*/
	wxToolBarToolBase* getNewGridBtn() const;

	/**
	 * @brief clearGridBtn getter.
	 * @return the clearGridBtn
	*/
	wxToolBarToolBase* getClearGridBtn() const;

	/**
	 * @brief algorithmComboBox getter
	 * @return the algorithmComboBox
	*/
	wxComboBox *getAlgorithmComboBox() const;

};

#endif // !MAIN_FRAME_VIEW