/*
 * Copyright (c) 2011-2019, The DART development contributors
 * All rights reserved.
 *
 * The list of contributors can be found at:
 *   https://github.com/dartsim/dart/blob/master/LICENSE
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DART_DYNAMICS_DISTANCESENSOR_HPP_
#define DART_DYNAMICS_DISTANCESENSOR_HPP_

#include <Eigen/Dense>
#include "dart/dynamics/Sensor.hpp"
#include "dart/dynamics/detail/DistanceSensorAspect.hpp"

namespace dart {
namespace dynamics {

class BodyNode;

/// This class implements Inertial Measuring Unit (IMU) sensor.
class DistanceSensor
    : public common::EmbedStateAndPropertiesOnTopOf<DistanceSensor,
                                                    detail::DistanceSensorState,
                                                    detail::DistanceSensorProperties,
                                                    Sensor>
{
public:
  using BasicProperties = common::Composite::MakeProperties<DistanceSensor>;
  using State = common::Composite::State;
  using Properties = common::Composite::Properties;

  friend class BodyNode;

  /// Destructor
  ~DistanceSensor() override = default;

  /// Set the AspectState of this Sensor
  void setAspectState(const AspectState& state);

  /// Set the AspectProperties of this Sensor
  void setAspectProperties(const AspectProperties& properties);

protected:
  /// Constructor used by BodyNode
  DistanceSensor(BodyNode* parent, const BasicProperties& properties);

  // Documentation inherited
  Node* cloneNode(BodyNode* parent) const override;
};

} // namespace dynamics
} // namespace dart

#endif // DART_DYNAMICS_DISTANCESENSOR_HPP_
