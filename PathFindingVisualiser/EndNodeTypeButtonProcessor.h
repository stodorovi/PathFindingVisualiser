#ifndef END_NODE_TYPE_BTN_PROCESSOR
#define END_NODE_TYPE_BTN_PROCESSOR

#include "MainFrameViewConstants.h"
#include "NodeTypeButtonSelectionSelectableProcessor.h"

/** @brief Processor for the end node type. */
class EndNodeTypeButtonProcessor : public NodeTypeButtonSelectionSelectableProcessor {

public:

    /**
    * @brief Constructor.
    * @param id - id of the button
    * @param mainFrame - main frame to process event for
    */
    EndNodeTypeButtonProcessor(int id,
                               MainFrame * const mainFrame);

    virtual bool matches() override;

};

#endif // !END_NODE_TYPE_BTN_PROCESSOR
