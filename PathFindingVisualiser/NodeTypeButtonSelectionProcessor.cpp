#include "NodeTypeButtonSelectionProcessor.h"

NodeTypeButtonSelectionProcessor::NodeTypeButtonSelectionProcessor(int id,
                                                                   MainFrame * const mainFrame) {

        m_processors.push_back(std::make_unique<StartNodeTypeButtonProcessor>(id,
                                                                              mainFrame));
        m_processors.push_back(std::make_unique<EndNodeTypeButtonProcessor>(id,
                                                                            mainFrame));
        m_processors.push_back(std::make_unique<BlockNodeTypeButtonProcessor>(id,
                                                                              mainFrame));
        m_processors.push_back(std::make_unique<EraseNodeTypeButtonProcessor>(id,
                                                                              mainFrame));



}

void NodeTypeButtonSelectionProcessor::process() {

    for (auto &&processor : m_processors) {

        processor->process();

    }

}
