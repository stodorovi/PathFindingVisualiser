#ifndef NODE_TYPE_BTN_SELECTION_PROCESSOR_H
#define NODE_SELECTION_PROCESSOR_H

#include <memory>
#include <vector>

#include "NodeTypeButtonSelectionSelectableProcessor.h"
#include "PlaceableNodeType.h"

#include "BlockNodeTypeButtonProcessor.h"
#include "EndNodeTypeButtonProcessor.h"
#include "EraseNodeTypeButtonProcessor.h"
#include "StartNodeTypeButtonProcessor.h"

/** forward declaration - circular dependancy */
class MainFrame;

/** @brief Processor that selects the matching sub-processor to process the selected node button */
class NodeTypeButtonSelectionProcessor {

private:

    /** @brief Vector of sub-processors */
    std::vector<std::unique_ptr<NodeTypeButtonSelectionSelectableProcessor>> m_processors;

public:

    /**
     * @brief Constructor.
     * 
     * @param id - the id of the button to process
     * @param mainFrame - the main frame to process event for
    */
    NodeTypeButtonSelectionProcessor(int id,
                                     MainFrame * const mainFrame);

    /** @brief Select the matching processor. */
    void process();

};

#endif // !NODE_TYPE_BTN_SELECTION_PROCESSOR_H

