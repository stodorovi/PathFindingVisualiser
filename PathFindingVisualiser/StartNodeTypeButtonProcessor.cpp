#include "StartNodeTypeButtonProcessor.h"

StartNodeTypeButtonProcessor::StartNodeTypeButtonProcessor(int id,
                                                           MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool StartNodeTypeButtonProcessor::matches() {

    return m_id == START_NODE_BTN_ID;

}
