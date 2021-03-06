//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#pragma once

#include "backends/ClWorkloadUtils.hpp"

namespace armnn
{

arm_compute::Status ClDepthwiseConvolutionWorkloadValidate(const TensorInfo& input,
                                                           const TensorInfo& output,
                                                           const DepthwiseConvolution2dDescriptor& descriptor,
                                                           const TensorInfo& weights,
                                                           const TensorInfo& biases);

template<armnn::DataType... dataTypes>
class ClDepthwiseConvolutionBaseWorkload : public TypedWorkload<DepthwiseConvolution2dQueueDescriptor, dataTypes...>
{
public:
    using TypedWorkload<DepthwiseConvolution2dQueueDescriptor, dataTypes...>::m_Data;

    ClDepthwiseConvolutionBaseWorkload(const DepthwiseConvolution2dQueueDescriptor& descriptor,
                                       const WorkloadInfo& info);

protected:
    std::unique_ptr<arm_compute::IFunction> m_DepthwiseConvolutionLayer;

    std::unique_ptr<arm_compute::CLTensor> m_KernelTensor;
    std::unique_ptr<arm_compute::CLTensor> m_BiasTensor;

    void FreeUnusedTensors();
};

} //namespace armnn
