#ifndef END_NODE_TYPE_BTN_PROCESSOR
#define END_NODE_TYPE_BTN_PROCESSOR

#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the END node type. */
class EndNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the pressed button
    * @param mainFrame - main frame to process event for
    */
    EndNodeTypeButtonProcessor(int id,
                               MainFrame * const mainFrame);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() override;

};

#endif // !END_NODE_TYPE_BTN_PROCESSOR
