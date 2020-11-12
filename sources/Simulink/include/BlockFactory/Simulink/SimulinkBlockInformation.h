/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef BLOCKFACTORY_MEX_SIMULINKBLOCKINFORMATION_H
#define BLOCKFACTORY_MEX_SIMULINKBLOCKINFORMATION_H

#include "BlockFactory/Core/BlockInformation.h"
#include "BlockFactory/Core/Parameter.h"
#include "BlockFactory/Core/Port.h"
#include "BlockFactory/Core/Signal.h"

#include <string>
#include <vector>

namespace blockfactory {
    namespace mex {
        class SimulinkBlockInformation;
        namespace impl {
            class SimulinkBlockInformationImpl;
        } // namespace impl
    } // namespace mex
} // namespace blockfactory

// Forward declare SimStruct
typedef struct SimStruct_tag SimStruct;

/**
 * @brief Simulink implementation of block information
 *
 * This class implements the core::BlockInformationfor abstract class providing to core::Block
 * objects the support of interfacing with the Simulink engine.
 */
class blockfactory::mex::SimulinkBlockInformation final : public core::BlockInformation
{
private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    std::unique_ptr<impl::SimulinkBlockInformationImpl> pImpl;
#endif
public:
    using ParameterIndex = unsigned;

    SimulinkBlockInformation(SimStruct* simstruct);
    ~SimulinkBlockInformation() override;

    bool getUniqueName(std::string& blockUniqueName) const override;
    bool optionFromKey(const std::string& key, double& option) const override;
    bool addParameterMetadata(const core::ParameterMetadata& paramMD) override;
    bool parseParameters(core::Parameters& parameters) override;
    bool setPortsInfo(const core::InputPortsInfo& inputPortsInfo,
                      const core::OutputPortsInfo& outputPortsInfo) override;
    core::Port::Info getInputPortInfo(const core::Port::Index idx) const override;
    core::Port::Info getOutputPortInfo(const core::Port::Index idx) const override;
    core::Port::Size::Vector getInputPortWidth(const core::Port::Index idx) const override;
    core::Port::Size::Vector getOutputPortWidth(const core::Port::Index idx) const override;
    core::Port::Size::Matrix getInputPortMatrixSize(const core::Port::Index idx) const override;
    core::Port::Size::Matrix getOutputPortMatrixSize(const core::Port::Index idx) const override;
    core::InputSignalPtr getInputPortSignal(const core::Port::Index idx) const override;
    core::OutputSignalPtr getOutputPortSignal(const core::Port::Index idx) const override;
};

#endif /* BLOCKFACTORY_MEX_SIMULINKBLOCKINFORMATION_H */
