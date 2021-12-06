#include "MainFrame.h"


MainFrame::MainFrame()
    : wxMDIParentFrame(nullptr,
                       MAIN_FRAME_ID,
                       MAIN_FRAME_TITLE,
                       wxDefaultPosition,
                       MAIN_FRAME_DEFAULT_SIZE) {

    SetMinSize(wxSize(640, 420));

    initMenuBar();

    BindEvents();

}

MainFrame::~MainFrame() {
}

void MainFrame::initMenuBar() {

    m_menuBar = new wxMenuBar();
    this->SetMenuBar(m_menuBar);

    wxMenu *menuFile = new wxMenu();
    menuFile->Append(FILE_MENU_NEW_ID,
                     FILE_MENU_NEW_TEXT);

    menuFile->AppendSeparator();

    menuFile->Append(FILE_MENU_EXIT_ID,
                     FILE_MENU_EXIT_TEXT);

    m_menuBar->Append(menuFile,
                      FILE_MENU_TEXT);

}

void MainFrame::onMenuNew(wxCommandEvent &event) {

    GridFrame *gridFrame = new GridFrame(this,
                                         wxT("New Grid"));

    gridFrame->Show();

}

void MainFrame::onMenuExit(wxCommandEvent &event) {
    
    Close();

    event.Skip();

}

void MainFrame::BindEvents() {

    Bind(wxEVT_COMMAND_MENU_SELECTED,
         &MainFrame::onMenuNew,
         this,
         FILE_MENU_NEW_ID);

    Bind(wxEVT_COMMAND_MENU_SELECTED,
         &MainFrame::onMenuExit,
         this,
         FILE_MENU_EXIT_ID);

}
