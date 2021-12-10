#ifndef NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H
#define NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H

#include <map>

#include "PlaceableNodeType.h"
#include "PathfindingAppConstants.h"

/** forward declaration - circular dependancy */
class MainFrame;

/** @brief Selectable procassors to process. */
class NodeTypeButtonSelectionSelectableProcessor {

protected:

    static constexpr int const NODE_TYPE_BTN_SIZE = 3;
    static const int NODE_TYPE_BTN_IDS[NODE_TYPE_BTN_SIZE];

    static const std::map<const int, PlaceableNodeType> NODE_TYPES_BY_ID;

    const int m_id;

    MainFrame * const m_mainFrame;

public:

    /**
     * @brief Constructor.
     * 
     * @param buttonID - button to process.
     * @param mainFrame - main frame to process event for.
    */
    NodeTypeButtonSelectionSelectableProcessor(int buttonID,
                                               MainFrame * const mainFrame);

    /**
     * @brief Retuns if the button matches the given id.
     * 
     * @return bool 
    */
    virtual bool matches() = 0;

    /** @brief Process the button check. */
    virtual void process();

    /** @brief Sets the button's & child frame's node type. */
    virtual void onMatch();

};


#endif // !NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H

