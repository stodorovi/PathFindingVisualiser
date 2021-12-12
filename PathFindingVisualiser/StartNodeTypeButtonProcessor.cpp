#include "StartNodeTypeButtonProcessor.h"
#include "MainFrameView.h"

StartNodeTypeButtonProcessor::StartNodeTypeButtonProcessor(int id,
                                                           MainFrame * const mainFrame)
    : NodeTypeButtonSelectionSelectableProcessor(id,
                                                 mainFrame) {
}

bool StartNodeTypeButtonProcessor::matches() {

    return m_id == MainFrameViewConstants::START_NODE_ID;

}
