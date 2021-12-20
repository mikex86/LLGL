/*
 * Controller.h
 *
 * This file is part of the "LLGL" project (Copyright (c) 2015-2019 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 *
 * @author mikex86
 */


#ifndef LLGL_CONTROLLER_H
#define LLGL_CONTROLLER_H

#include <LLGL/Interface.h>

namespace LLGL {

    enum class ControllerButton {
        NONE = 0,
        DPAD_UP = 1,
        DPAD_DOWN = 1 << 1,
        DPAD_LEFT = 1 << 2,
        DPAD_RIGHT = 1 << 3,
        START = 1 << 4,
        BACK = 1 << 5,
        LEFT_BUMPER = 1 << 6,
        RIGHT_BUMPER = 1 << 7,
        BUTTON_S = 1 << 8,
        BUTTON_E = 1 << 9,
        BUTTON_W = 1 << 10,
        BUTTON_N = 1 << 11,
    };

    enum class ControllerJoystick {
        LEFT_THUMB,
        RIGHT_THUMB,
        LEFT_TRIGGER,
        RIGHT_TRIGGER,
    };

    enum class JoystickAxis {
        X,
        Y
    };

    class LLGL_EXPORT ControllerState {

    public:
        [[nodiscard]] bool isConnected() const;

        [[nodiscard]] bool isButtonDown(ControllerButton button) const;

        /**
         * @brief Returns the current joystick value normalized between -1.0f and 1.0f.
         * The value is only valid if the joystick is connected, else it will be 0.0f.
         * For the left and right triggers, the value is normalized between 0.0f and 1.0f.
         * For the left and right thumb sticks, the value is normalized between -1.0f and 1.0f.
         * For triggers, the axis argument is ignored.
         * @param joystick the joystick to query.
         * @param axis the axis to query.
         */
        [[nodiscard]] float getJoystickValue(ControllerJoystick joystick, JoystickAxis axis) const;

    private:
        bool connected_ = false;
        float leftThumbX_ = 0.0f;
        float leftThumbY_ = 0.0f;
        float rightThumbX_ = 0.0f;
        float rightThumbY_ = 0.0f;
        float rightTrigger_ = 0.0f;
        float leftTrigger_ = 0.0f;
        ControllerButton buttonFlags_ = ControllerButton::NONE;

    public:
        void setConnected(bool connected);

        void setLeftThumbX(float leftThumbX);

        void setLeftThumbY(float leftThumbY);

        void setRightThumbX(float rightThumbX);

        void setRightThumbY(float rightThumbY);

        void setRightTrigger(float rightTrigger);

        void setLeftTrigger(float leftTrigger);

        void setButtonFlags(ControllerButton buttonFlags);
    };
} // /namespace LLGL

#endif //LLGL_CONTROLLER_H