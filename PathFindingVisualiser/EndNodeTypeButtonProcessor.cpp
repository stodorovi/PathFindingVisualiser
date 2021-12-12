#include "EndNodeTypeButtonProcessor.h"

EndNodeTypeButtonProcessor::EndNodeTypeButtonProcessor(int id,
                                                       MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool EndNodeTypeButtonProcessor::matches() {

    return m_id == MainFrameViewConstants::END_NODE_ID;

}
