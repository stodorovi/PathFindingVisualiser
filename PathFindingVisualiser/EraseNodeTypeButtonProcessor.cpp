#include "EraseNodeTypeButtonProcessor.h"

EraseNodeTypeButtonProcessor::EraseNodeTypeButtonProcessor(int id,
                                                           MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool EraseNodeTypeButtonProcessor::matches() {

    return m_id == MainFrameViewConstants::ERASE_NODE_ID;

}