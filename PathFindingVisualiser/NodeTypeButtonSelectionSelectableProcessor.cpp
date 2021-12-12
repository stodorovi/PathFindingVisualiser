#include "NodeTypeButtonSelectionSelectableProcessor.h"
#include "MainFrame.h"

NodeTypeButtonSelectionSelectableProcessor::NodeTypeButtonSelectionSelectableProcessor(int id,
                                                                                       MainFrame * const mainFrame)
    : m_id{id},
      m_mainFrame{mainFrame},
      m_idNodeTypeMap{

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

        for (IdNodeTypeMap::const_iterator it = m_idNodeTypeMap.begin(); it != m_idNodeTypeMap.end(); ++it) {

            toolbar->ToggleTool(it->first,
                                m_id == it->first);

        }

    }

    GridFrame *activeChild = (GridFrame *) m_mainFrame->GetActiveChild();

    if (activeChild) {

        activeChild->getView().setCurrentNodeType(placeableNodeType);

    }

}