#ifndef ERASE_NODE_TYPE_BTN_PROCESSOR
#define ERASE_NODE_TYPE_BTN_PROCESSOR

#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the ERASE node type. */
class EraseNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the pressed button
    * @param mainFrame - main frame to process event for
    */
    EraseNodeTypeButtonProcessor(int id,
                                 MainFrame * const mainFrame);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() override;

};

#endif // !ERASE_NODE_TYPE_BTN_PROCESSOR
