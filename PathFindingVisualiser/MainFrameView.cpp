#include "MainFrameView.h"

#include "MainFrame.h"

MainFrameView::MainFrameView(MainFrame *mainFrame)
    : m_mainFrame{mainFrame} {

    initMenuBar();

    initToolBar();

}

void MainFrameView::initMenuBar() {

    m_menuBar = new wxMenuBar();
    m_mainFrame->SetMenuBar(m_menuBar);

    m_menuFile = new wxMenu();

    m_menuFileNew = new wxMenuItem(m_menuFile,
                                   MainFrameViewConstants::FILE_NEW_ID,
                                   MainFrameViewConstants::FILE_NEW_TEXT,
                                   MainFrameViewConstants::FILE_NEW_TEXT);

    m_menuFileExit = new wxMenuItem(m_menuFile,
                                    MainFrameViewConstants::FILE_EXIT_ID,
                                    MainFrameViewConstants::FILE_EXIT_TEXT,
                                    MainFrameViewConstants::FILE_EXIT_TEXT);

    m_menuFile->Append(m_menuFileNew);
    m_menuFile->AppendSeparator();
    m_menuFile->Append(m_menuFileExit);

    m_menuBar->Append(m_menuFile,
                      MainFrameViewConstants::FILE_MENU_TEXT);

}

void MainFrameView::initToolBar() {



    m_toolBar = m_mainFrame->CreateToolBar(wxHORIZONTAL,
                                           MainFrameViewConstants::TOOL_BAR_ID);

    m_RunAlgorithmBtn = new wxButton(m_toolBar,
                                     MainFrameViewConstants::RUN_ALGORITHM_ID,
                                     MainFrameViewConstants::RUN_ALGORITHM_TEXT);

    wxStaticText *toolbarPaddingLeft = new wxStaticText(m_toolBar,
                                                        wxID_ANY,
                                                        wxEmptyString,
                                                        wxDefaultPosition,
                                                        wxSize{MainFrameViewConstants::PADDING_SIZE,
                                                               0});
    m_toolBar->AddControl(toolbarPaddingLeft);

    wxImage::AddHandler(new wxPNGHandler);

    m_newGridImage = wxBitmap(MainFrameViewConstants::NEW_GRID_IMG_PATH,
                              wxBITMAP_TYPE_PNG);
    m_newGridBtn = m_toolBar->AddTool(MainFrameViewConstants::NEW_GRID_ID,
                                      MainFrameViewConstants::FILE_NEW_TEXT,
                                      m_newGridImage,
                                      MainFrameViewConstants::FILE_NEW_TEXT);

    m_toolBar->AddSeparator();

    m_toolBar->AddControl(m_RunAlgorithmBtn);

    m_toolBar->Realize();

    m_toolBar->AddSeparator();

    m_runAlgorithmImage = wxBitmap(MainFrameViewConstants::RUN_ALGORITHM_IMG_PATH,
                                   wxBITMAP_TYPE_PNG);
    m_RunAlgorithmBtn->SetBitmap(m_runAlgorithmImage);


    m_startNodeImage = wxBitmap(MainFrameViewConstants::START_NODE_IMG_PATH,
                                wxBITMAP_TYPE_PNG);

    m_endNodeImage = wxBitmap(MainFrameViewConstants::END_NODE_IMG_PATH,
                              wxBITMAP_TYPE_PNG);

    m_blockNodeImage = wxBitmap(MainFrameViewConstants::BLOCK_NODE_IMG_PATH,
                                wxBITMAP_TYPE_PNG);

    m_eraseNodeImage = wxBitmap(MainFrameViewConstants::ERASE_NODE_IMG_PATH,
                                wxBITMAP_TYPE_PNG);

    m_clearGridImage = wxBitmap(MainFrameViewConstants::CLEAR_GRID_IMG_PATH,
                                wxBITMAP_TYPE_PNG);

    m_startNodeBtn = m_toolBar->AddTool(MainFrameViewConstants::START_NODE_ID,
                                        MainFrameViewConstants::START_NODE_TEXT,
                                        m_startNodeImage,
                                        MainFrameViewConstants::START_NODE_TEXT,
                                        wxITEM_CHECK);

    m_endNodeBtn =  m_toolBar->AddTool(MainFrameViewConstants::END_NODE_ID,
                                       MainFrameViewConstants::END_NODE_TEXT,
                                       m_endNodeImage,
                                       MainFrameViewConstants::END_NODE_TEXT,
                                       wxITEM_CHECK);

    m_blockNodeBtn = m_toolBar->AddTool(MainFrameViewConstants::BLOCK_NODE_ID,
                                        MainFrameViewConstants::BLOCK_NODE_TEXT,
                                        m_blockNodeImage,
                                        MainFrameViewConstants::BLOCK_NODE_TEXT,
                                        wxITEM_CHECK);

    m_eraseNodeBtn = m_toolBar->AddTool(MainFrameViewConstants::ERASE_NODE_ID,
                                        MainFrameViewConstants::ERASE_NODE_TEXT,
                                        m_eraseNodeImage,
                                        MainFrameViewConstants::ERASE_NODE_TEXT,
                                        wxITEM_CHECK);

    m_toolBar->AddSeparator();

    m_clearGridBtn = m_toolBar->AddTool(MainFrameViewConstants::CLEAR_GRID_ID,
                                        MainFrameViewConstants::CLEAR_GRID_TEXT,
                                        m_clearGridImage,
                                        MainFrameViewConstants::CLEAR_GRID_TEXT);

    m_toolBar->Realize();

}

wxMenuBar *MainFrameView::getMenuBar() const {

    return m_menuBar;

}

wxMenu *MainFrameView::getMenuFile() const {

    return m_menuFile;

}

wxMenuItem *MainFrameView::getMenuFileNew() const {

    return m_menuFileNew;

}

wxMenuItem *MainFrameView::getMenuFileExit() const {

    return m_menuFileExit;

}

wxToolBar *MainFrameView::getToolBar() const {

    return m_toolBar;

}

wxButton *MainFrameView::getRunAlgorithmBtn() const {

    return m_RunAlgorithmBtn;

}

wxToolBarToolBase *MainFrameView::getStartNodeBtn() const {
    
    return m_startNodeBtn;

}

wxToolBarToolBase *MainFrameView::getEndNodeBtn() const {

    return m_endNodeBtn;

}

wxToolBarToolBase *MainFrameView::getBlockNodeBtn() const {

    return m_blockNodeBtn;

}

wxToolBarToolBase *MainFrameView::getEraseNodeBtn() const {

    return m_eraseNodeBtn;

}

wxToolBarToolBase *MainFrameView::getNewGridBtn() const {

    return m_newGridBtn;

}

wxToolBarToolBase *MainFrameView::getClearGridBtn() const {

    return m_clearGridBtn;

}
