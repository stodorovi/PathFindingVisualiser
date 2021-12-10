#ifndef START_NODE_TYPE_BTN_PROCESSOR
#define START_NODE_TYPE_BTN_PROCESSOR

#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the start node type. */
class StartNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the button
    * @param mainFrame - main frame to process event for
    */
    StartNodeTypeButtonProcessor(int id,
                                 MainFrame * const mainFrame);

    virtual bool matches() override;

};

#endif // !START_NODE_TYPE_BTN_PROCESSOR

