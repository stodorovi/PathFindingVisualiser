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

    MainFrame * const m_mainFrame;

    using IdNodeTypeMap = std::map<const int, PlaceableNodeType>;
    const IdNodeTypeMap m_idNodeTypeMap;

    const int m_id;

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

    /** @brief Sets the current placeable node type & toggles the buttons. */
    virtual void setCurrentNodeTypeAndToggleButtons();

};

#endif // !NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H
