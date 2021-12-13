#ifndef BLOCK_NODE_TYPE_BTN_PROCESSOR
#define BLOCK_NODE_TYPE_BTN_PROCESSOR

#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the BLOCK node type. */
class BlockNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the pressed button
    * @param mainFrame - main frame to process event for
    */
    BlockNodeTypeButtonProcessor(int id,
                                 MainFrame * const mainFrame);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() override;

};

#endif // !BLOCK_NODE_TYPE_BTN_PROCESSOR
