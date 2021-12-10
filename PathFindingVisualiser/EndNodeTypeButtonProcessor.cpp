#include "EndNodeTypeButtonProcessor.h"

EndNodeTypeButtonProcessor::EndNodeTypeButtonProcessor(int id,
                                                       MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool EndNodeTypeButtonProcessor::matches() {

    return m_id == END_NODE_BTN_ID;

}
