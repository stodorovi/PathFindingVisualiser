#include "BlockNodeTypeButtonProcessor.h"

BlockNodeTypeButtonProcessor::BlockNodeTypeButtonProcessor(int id,
                                                           MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool BlockNodeTypeButtonProcessor::matches() {

    return m_id == MainFrameViewConstants::BLOCK_NODE_ID;

}
