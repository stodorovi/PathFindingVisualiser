#ifndef MAINAPP_H
#define MAINAPP_H

#include "wx/wx.h"
#include "MainFrame.h"

class MainApp : public wxApp {

private:
	
	MainFrame* m_mainFrame;


public:

	MainApp();
	~MainApp();

	virtual bool OnInit();

};

#endif // !MAINAPP_H
