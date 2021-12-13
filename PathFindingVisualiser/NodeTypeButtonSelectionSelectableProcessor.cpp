#include "NodeTypeButtonSelectionSelectableProcessor.h"
#include "MainFrame.h"

NodeTypeButtonSelectionSelectableProcessor::NodeTypeButtonSelectionSelectableProcessor(int id,
                                                                                       MainFrame * const mainFrame)
    : m_id{id},
      m_mainFrame{mainFrame},
      m_idNodeTypeMap {

          {m_mainFrame->getView().getStartNodeBtn()->GetId(), PlaceableNodeType::START},
          {m_mainFrame->getView().getEndNodeBtn()->GetId(),   PlaceableNodeType::END},
          {m_mainFrame->getView().getBlockNodeBtn()->GetId(), PlaceableNodeType::BLOCK},
          {m_mainFrame->getView().getEraseNodeBtn()->GetId(), PlaceableNodeType::ERASE}

      } {
}

void NodeTypeButtonSelectionSelectableProcessor::process() {

    if (matches()) {

        setCurrentNodeTypeAndToggleButtons();

    }

}

void NodeTypeButtonSelectionSelectableProcessor::setCurrentNodeTypeAndToggleButtons() {

    PlaceableNodeType &placeableNodeType = m_mainFrame->getCurrentNodeType();

    wxToolBar *toolbar = m_mainFrame->getView().getToolBar();
    
    if (placeableNodeType == m_idNodeTypeMap.at(m_id)) {

        placeableNodeType = PlaceableNodeType::NONE;

    } else {

        placeableNodeType = m_idNodeTypeMap.at(m_id);

        for (auto &&idNodeTypePair : m_idNodeTypeMap) {

            toolbar->ToggleTool(idNodeTypePair.first,
                                m_id == idNodeTypePair.first);

        }

    }

    GridFrame *activeChild = static_cast<GridFrame *>(m_mainFrame->GetActiveChild());

    if (activeChild) {

        activeChild->getView().setCurrentNodeType(placeableNodeType);

    }

}