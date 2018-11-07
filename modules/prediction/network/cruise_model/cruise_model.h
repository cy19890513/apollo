/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <vector>

#include "Eigen/Dense"

#include "cyber/common/macros.h"
#include "modules/prediction/proto/cruise_model.pb.h"
#include "modules/prediction/network/net_model.h"

namespace apollo {
namespace prediction {
namespace network {

class CruiseModel : public NetModel {
 public:
  /**
   * @brief Load cruise network parameters from a protobuf message
   * @param CruiseModelParameter is a protobuf message
   * @return True if successfully loaded, otherwise False
   */
  bool LoadModel(
      const apollo::prediction::CruiseModelParameter& cruise_model_parameter);

  /**
   * @brief Compute the model output from inputs according to a defined layers'
   * flow
   * @param Inputs to the network
   * @param Output of the network will be returned
   */
  void Run(const std::vector<Eigen::MatrixXf>& inputs,
           Eigen::MatrixXf* output) const override;

 private:
  CruiseModelParameter cruise_model_parameter_;
};

}  // namespace network
}  // namespace prediction
}  // namespace apollo