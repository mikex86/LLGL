/*
 * Controller.cpp
 *
 * This file is part of the "LLGL" project (Copyright (c) 2015-2019 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 *
 * @author mikex86
 */

#include <LLGL/ControllerState.h>
#include <cstdint>

namespace LLGL {

    bool ControllerState::isConnected() const {
        return connected_;
    }

    bool ControllerState::isButtonDown(ControllerButton button) const {
        return (static_cast<uint32_t>(buttonFlags_) & static_cast<uint32_t>(button)) != 0;
    }

    float ControllerState::getJoystickValue(ControllerJoystick joystick, JoystickAxis axis) const {
        switch (joystick) {
            case ControllerJoystick::LEFT_THUMB:
                switch (axis) {
                    case JoystickAxis::X:
                        return leftThumbX_;
                    case JoystickAxis::Y:
                        return leftThumbY_;
                }
                break;
            case ControllerJoystick::RIGHT_THUMB:
                switch (axis) {
                    case JoystickAxis::X:
                        return rightThumbX_;
                    case JoystickAxis::Y:
                        return rightThumbY_;
                }
            case ControllerJoystick::LEFT_TRIGGER:
                return leftTrigger_;
            case ControllerJoystick::RIGHT_TRIGGER:
                return rightTrigger_;
        }
        return 0;
    }

    void ControllerState::setConnected(bool connected) {
        connected_ = connected;
    }

    void ControllerState::setLeftThumbX(float leftThumbX) {
        leftThumbX_ = leftThumbX;
    }

    void ControllerState::setLeftThumbY(float leftThumbY) {
        leftThumbY_ = leftThumbY;
    }

    void ControllerState::setRightThumbX(float rightThumbX) {
        rightThumbX_ = rightThumbX;
    }

    void ControllerState::setRightThumbY(float rightThumbY) {
        rightThumbY_ = rightThumbY;
    }

    void ControllerState::setRightTrigger(float rightTrigger) {
        rightTrigger_ = rightTrigger;
    }

    void ControllerState::setLeftTrigger(float leftTrigger) {
        leftTrigger_ = leftTrigger;
    }

    void ControllerState::setButtonFlags(ControllerButton buttonFlags) {
        buttonFlags_ = buttonFlags;
    }

} // /namespace LLGL