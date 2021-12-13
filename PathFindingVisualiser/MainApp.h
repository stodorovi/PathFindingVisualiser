#ifndef MAINAPP_H
#define MAINAPP_H

#include "wx/wx.h"

#include "MainFrame.h"

/** @brief Main application. */
class MainApp : public wxApp {

private:
	
	MainFrame* m_mainFrame;


public:

	/** @brief Constructor. */
	MainApp();

	/** @brief Destructor. */
	~MainApp();

	/**
	 * @brief Creates the main frame.
	 * @return 
	*/
	virtual bool OnInit();

};

#endif // !MAINAPP_H
