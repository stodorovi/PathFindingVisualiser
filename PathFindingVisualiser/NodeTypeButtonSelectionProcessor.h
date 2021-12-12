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

/**
 * @brief Processor that selects the propper processor on node button press.
*/
class NodeTypeButtonSelectionProcessor {

private:

    /** @brief List of selectable processors to check. */
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

    /** @brief Process the processors & select the proper one. */
    void process();

};

#endif // !NODE_TYPE_BTN_SELECTION_PROCESSOR_H

