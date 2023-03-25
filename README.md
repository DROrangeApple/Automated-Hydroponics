# Indoor Automated Hydroponics

This project is focused on automating the indoor hydroponics growing process using a custom control circuit and a mobile app. The control circuit manages various components such as pumps, fans, and LED lights, while the app provides an easy-to-use interface for controlling these components remotely.

## Table of Contents

- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

These instructions will help you set up the control circuit and configure the mobile app to manage your indoor hydroponics system.

## Prerequisites

- NodeMCU board
- aRest IoT library (v2.9.6)
- esp8266 (v2.7.4) installed in the Arduino board manager
- An account on AppShed

## Hardware Setup

Assemble the control circuit using the following components:

- 1x NodeMCU board
- 5x MOSFET (any low logic level will do)
- 1x 12 volt PSU
- 1x 0.96 inch OLED
- 1x 12 volt water pump
- 1x 12 volt air pump
- 1x 12 volt LED strip
- 4x 12 volt fans

## Software Setup

- Install the required libraries:
    - aRest IoT library (v2.9.6)
    - esp8266 (v2.7.4) installed in the Arduino board manager
- Upload the provided INO file to the NodeMCU board.

IF YOU ARE USING EXISTING CONTROL APP

- Open http://apps.appshed.com/buildithydrocontrol on a WIFI enabled device (make sure its HTTP not HTTPS and AVOID chrome (firefox works great))
- Once webapp has fully loaded go to WIFI settings of device and find SSID BuildItHydro with password buildithydro
- Cog in corner should go green, device can now be controlled via app (App is still very much in development so dont expect too much from it)

IF YOU ARE MAKING YOUR OWN APP

- Create a new app on AppShed using your free account.
- Add a button to the app click on the action tab and set its action to JavaScript.
- Use the provided JavaScript code to call functions in the NodeMCU code. For example:

```javascript
app.device.callFunction("SetWaterPumpPWM", { "parameters": 0 });
```

- Publish the app
- Click Share
- Scan the bottom QR code on a WIFI enabled deivce (avoid chrome, firefox works best)

## Usage

- Connect your mobile device to the NodeMCU's Wi-Fi network.
- Open the app on your mobile device.
- Control the hydroponics system components by pressing
