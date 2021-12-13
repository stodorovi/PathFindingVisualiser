#ifndef NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H
#define NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H

#include <map>

#include "MainFrameViewConstants.h"
#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class MainFrame;

/** @brief Abstract selectable processor. */
class NodeTypeButtonSelectionSelectableProcessor {

protected:

    MainFrame * const m_mainFrame;

    const std::map<const int, PlaceableNodeType> m_idNodeTypeMap;

    const int m_id;

    /** @brief Sets the current placeable node type & toggles the buttons. */
    virtual void setCurrentNodeTypeAndToggleButtons();

public:

    /**
     * @brief Constructor.
     * 
     * @param buttonID - id of the pressed button.
     * @param mainFrame - main frame to process event for.
    */
    NodeTypeButtonSelectionSelectableProcessor(int buttonID,
                                               MainFrame * const mainFrame);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() = 0;

    /** @brief Process the button check. */
    void process();

};

#endif // !NODE_TYPE_BTN_SELECTION_SELECTABLE_PROCESSOR_H
