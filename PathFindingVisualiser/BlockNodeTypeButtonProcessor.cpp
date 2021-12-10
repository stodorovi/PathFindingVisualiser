#include "BlockNodeTypeButtonProcessor.h"

BlockNodeTypeButtonProcessor::BlockNodeTypeButtonProcessor(int id,
                                                           MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool BlockNodeTypeButtonProcessor::matches() {

    return m_id == BLOCK_NODE_BTN_ID;

}
