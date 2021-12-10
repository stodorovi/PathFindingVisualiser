#include "NodeTypeButtonSelectionSelectableProcessor.h"
#include "MainFrame.h"

const std::map<const int, PlaceableNodeType> NodeTypeButtonSelectionSelectableProcessor::NODE_TYPES_BY_ID = {

    std::make_pair(START_NODE_BTN_ID,
                   PlaceableNodeType::START),
    std::make_pair(END_NODE_BTN_ID,
                   PlaceableNodeType::END),
    std::make_pair(BLOCK_NODE_BTN_ID,
                   PlaceableNodeType::BLOCK)

};

const int NodeTypeButtonSelectionSelectableProcessor::NODE_TYPE_BTN_IDS[NODE_TYPE_BTN_SIZE] = {

    START_NODE_BTN_ID,
    END_NODE_BTN_ID,
    BLOCK_NODE_BTN_ID

};

NodeTypeButtonSelectionSelectableProcessor::NodeTypeButtonSelectionSelectableProcessor(int id,
                                                                                       MainFrame * const mainFrame)
    : m_id{id},
      m_mainFrame{mainFrame} {
}

void NodeTypeButtonSelectionSelectableProcessor::process() {

    if (matches()) {

        onMatch();

    }
}

void NodeTypeButtonSelectionSelectableProcessor::onMatch() {

    PlaceableNodeType &placeableNodeType = m_mainFrame->getCurrentPlaceableNodeType();

    wxToolBar *toolbar = m_mainFrame->GetToolBar();

    if (placeableNodeType == NODE_TYPES_BY_ID.at(m_id)) {

        placeableNodeType = PlaceableNodeType::NONE;

    } else {

        placeableNodeType = NODE_TYPES_BY_ID.at(m_id);

        for (int i = 0; i < NODE_TYPE_BTN_SIZE; ++i) {

            if (m_id != NODE_TYPE_BTN_IDS[i]) {

                toolbar->ToggleTool(NODE_TYPE_BTN_IDS[i],
                                    false);

            }

        }

    }

    GridFrame *activeChild = (GridFrame *) m_mainFrame->GetActiveChild();

    if (activeChild) {

        activeChild->setCurrentNodeType(placeableNodeType);

    }

}