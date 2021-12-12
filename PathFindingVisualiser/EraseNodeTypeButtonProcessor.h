#ifndef ERASE_NODE_TYPE_BTN_PROCESSOR
#define ERASE_NODE_TYPE_BTN_PROCESSOR

#include "MainFrameViewConstants.h"
#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the node erasing type. */
class EraseNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the button
    * @param mainFrame - main frame to process event for
    */
    EraseNodeTypeButtonProcessor(int id,
                                 MainFrame * const mainFrame);

    virtual bool matches() override;

};

#endif // !ERASE_NODE_TYPE_BTN_PROCESSOR
