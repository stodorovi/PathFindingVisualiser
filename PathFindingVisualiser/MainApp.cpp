#include "MainApp.h"
#include "MainApp.h"

wxIMPLEMENT_APP(MainApp);

MainApp::MainApp()
	:m_mainFrame{ nullptr } {
}

MainApp::~MainApp() {
}

bool MainApp::OnInit() {

	m_mainFrame = new MainFrame();
	m_mainFrame->Show();
	m_mainFrame->Centre ();

	return true;

}
