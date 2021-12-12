#ifndef BLOCK_NODE_TYPE_BTN_PROCESSOR
#define BLOCK_NODE_TYPE_BTN_PROCESSOR

#include "MainFrameViewConstants.h"
#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the block node type. */
class BlockNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the button
    * @param mainFrame - main frame to process event for
    */
    BlockNodeTypeButtonProcessor(int id,
                                 MainFrame * const mainFrame);

    virtual bool matches() override;

};

#endif // !BLOCK_NODE_TYPE_BTN_PROCESSOR
