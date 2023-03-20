Indoor Automated Hydroponics

This project is focused on automating the indoor hydroponics growing process using a custom control circuit and a mobile app. The control circuit manages various components such as pumps, fans, and LED lights, while the app provides an easy-to-use interface for controlling these components remotely.
Table of Contents

    Getting Started
    Prerequisites
    Hardware Setup
    Software Setup
    Usage
    Contributing
    License

Getting Started

These instructions will help you set up the control circuit and configure the mobile app to manage your indoor hydroponics system.
Prerequisites

    NodeMCU board
    aRest IoT library (v2.9.6)
    esp8266 (v2.7.4) installed in the Arduino board manager
    An account on AppShed

Hardware Setup

Assemble the control circuit using the following components:

    1x NodeMCU board
    5x MOSFET (any low logic level will do)
    1x 12 volt PSU
    1x 0.96 inch OLED
    1x 12 volt water pump
    1x 12 volt air pump
    1x 12 volt LED strip
    4x 12 volt fans

Software Setup

    Install the required libraries:
        aRest IoT library (v2.9.6)
        esp8266 (v2.7.4) installed in the Arduino board manager
    Upload the provided INO file to the NodeMCU board.
    Create a new app on AppShed using your free account.
    Add a button to the app and set its action to JavaScript.
    Use the provided JavaScript code to call functions in the NodeMCU code. For example:

javascript

app.device.callFunction("SetWaterPumpPWM", { "parameters": 0 });

    Load the app on your mobile device.

Usage

    Connect your mobile device to the NodeMCU's Wi-Fi network.
    Open the app on your mobile device.
    Control the hydroponics system components by pressing the buttons in the app.

Contributing

Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests to us.
License

This project is licensed under the MIT License - see the LICENSE.md file for details.

I hope this README file meets your expectations. If you have any further questions or need clarification, please feel free to ask.
