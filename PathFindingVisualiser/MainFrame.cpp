#include "MainFrame.h"

MainFrame::MainFrame()
    : wxMDIParentFrame(nullptr,
                       MainFrameConstants::ID,
                       MainFrameConstants::TITLE,
                       wxDefaultPosition,
                       wxSize(MainFrameConstants::WIDTH,
                              MainFrameConstants::HEIGHT)),
      m_currentNodeType{PlaceableNodeType::NONE},
      m_view{this} {

    SetMinSize(wxSize(720,
                      480));

    BindEvents();

}

MainFrame::~MainFrame() {
}

void MainFrame::onMenuNew(wxCommandEvent &event) {

    GridFrame *gridFrame = new GridFrame(this,
                                         wxT("New Grid"));

    gridFrame->Bind(wxEVT_CHILD_FOCUS,
                    &MainFrame::onChildWindowFocusChange,
                    this);

    gridFrame->Show();

}

void MainFrame::onMenuExit(wxCommandEvent &event) {
    
    Close();

    event.Skip();

}

void MainFrame::onRunAlgorithmBtnSelected(wxCommandEvent &event) {
}

void MainFrame::onNodeBtnSelected(wxCommandEvent &event) {

    NodeTypeButtonSelectionProcessor nodeTypeButtonSelectionProcessor(event.GetId(),
                                                                      this);

    nodeTypeButtonSelectionProcessor.process();

    event.Skip();

}

void MainFrame::onChildWindowFocusChange(wxChildFocusEvent &event) {

    GridFrame *activeChildFrame = (GridFrame *)GetActiveChild();

    activeChildFrame->getView().setCurrentNodeType(m_currentNodeType);

    event.Skip();

}

void MainFrame::onClearGridBtnSelected(wxCommandEvent &event) {

    GridFrame *activeChildWindow = (GridFrame*)GetActiveChild();

    if (activeChildWindow) {

        activeChildWindow->clearGrid();

    }

}

void MainFrame::BindEvents() {

    Bind(wxEVT_COMMAND_MENU_SELECTED,
         &MainFrame::onMenuNew,
         this,
         m_view.getMenuFileNew()->GetId());

    Bind(wxEVT_COMMAND_MENU_SELECTED,
         &MainFrame::onMenuExit,
         this,
         m_view.getMenuFileExit()->GetId());

    Bind(wxEVT_BUTTON,
         &MainFrame::onRunAlgorithmBtnSelected,
         this,
         m_view.getRunAlgorithmBtn()->GetId());

    Bind(wxEVT_COMMAND_TOOL_CLICKED,
         &MainFrame::onNodeBtnSelected,
         this,
         m_view.getStartNodeBtn()->GetId());

    Bind(wxEVT_COMMAND_TOOL_CLICKED,
         &MainFrame::onNodeBtnSelected,
         this,
         m_view.getEndNodeBtn()->GetId());

    Bind(wxEVT_COMMAND_TOOL_CLICKED,
         &MainFrame::onNodeBtnSelected,
         this,
         m_view.getBlockNodeBtn()->GetId());

    Bind(wxEVT_COMMAND_TOOL_CLICKED,
         &MainFrame::onNodeBtnSelected,
         this,
         m_view.getEraseNodeBtn()->GetId());

    Bind(wxEVT_COMMAND_TOOL_CLICKED,
        &MainFrame::onMenuNew,
        this,
        m_view.getNewGridBtn()->GetId());

    Bind(wxEVT_COMMAND_TOOL_CLICKED,
         &MainFrame::onClearGridBtnSelected,
         this,
         m_view.getClearGridBtn()->GetId());

}

PlaceableNodeType &MainFrame::getCurrentNodeType() {

    return m_currentNodeType;

}

MainFrameView &MainFrame::getView() {

    return m_view;

}