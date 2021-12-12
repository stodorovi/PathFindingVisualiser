#include "NodeTypeSetCellProcessor.h"

NodeTypeSetCellProcessor::NodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                                   int row,
                                                   int col) {

    m_processors.push_back(std::make_unique<StartNodeTypeSetCellProcessor>(gridFrameView,
                                                                           row,
                                                                           col));
    m_processors.push_back(std::make_unique<EndNodeTypeSetCellProcessor>(gridFrameView,
                                                                         row,
                                                                         col));
    m_processors.push_back(std::make_unique<BlockNodeTypeSetCellProcessor>(gridFrameView,
                                                                           row,
                                                                           col));
    m_processors.push_back(std::make_unique<EraseNodeTypeSetCellProcessor>(gridFrameView,
                                                                           row,
                                                                           col));

}

void NodeTypeSetCellProcessor::process() {

    for (auto &&processor : m_processors) {

        processor->process();

    }

}
