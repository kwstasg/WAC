# WAC
UE4 Visualization Plugin - Windows Audio Capture (WAC) is an Unreal Engine 4 plugin that captures live audio from the windows default audio device and analyse it to frequency values. 

Practically you can create any audio visualisation through Unreal Engine's BP system by adding custom nodes that react live with your windows audio.


UE 5.4.3 (25/7/2024):
-------------
Updated to latest UE 5.4.3

Plugin v5.4.3 : [here](https://github.com/kwstasg/WAC/releases/download/5.4.3/WindowsAudioCapture.zip)

Runtime Demo v5.4.3: [here](https://github.com/kwstasg/WAC/releases/download/5.4.3/WAC_Plugin_.5.4.3.Demo.Project.zip)


UE 4.25:
-------------
Updated to latest UE 4.25.3 release, added Shift Colors Hue Functionality

Color 1: Hue Shift Left/Right: Keboard keys 1/2
Color 2: Hue Shift Left/Right: Keboard keys 3/4

Fixed "Highly Volatile Noise Pattern" Bug

Runtime Demo v4.25.3: [here](https://github.com/kwstasg/WAC/releases/download/4.25.3/WAC_Plugin_4.25.3_Runtime_Demo.zip) 

Runtime Demo v4.25.3: [here](https://github.com/kwstasg/WAC/releases/download/4.25.3/WAC_Plugin_4.25.3_Runtime_DemoVR.zip) (with VR Support)

UE 4.20:
-------------
Plugin v4.20.3 : [here](https://github.com/kwstasg/WAC/releases/download/4.20.3/WAC_Plugin_4.20.3.rar)

Demo Project v4.20.3: [here](https://github.com/kwstasg/WAC/releases/download/4.20.3/WAC_Plugin_4.20.3.Demo.Project.rar) 

Runtime Demo v4.20.3: [here](https://github.com/kwstasg/WAC/releases/download/4.20.3/WAC_Plugin_4.20.3_Runtime_Demo.rar) (with VR Support)

UE 4.17:
-------------
Plugin v4.17.2 : [here](https://github.com/kwstasg/WAC/releases/download/WAC_Plugin_Packaged_4.17.2/WAC_Plugin_Packaged_4.17.2.rar)

UE 4.16:
-------------
Plugin v4.16.1 (updated to VS2017): [here](https://github.com/kwstasg/WAC/releases/download/WAC_Plugin_Packaged_4.16.1/WAC_Plugin_Packaged_4.16.1.rar)


Plugin v4.16: [here](https://github.com/kwstasg/WAC/releases/download/WAC_Plugin_Packaged_4.16/WAC_Plugin_Packaged_4.16.rar)

UE 4.15:
-------------
Demo v4.15: [here](https://www.dropbox.com/s/t0irs476zrjkwwf/WAC_Demo.rar?dl=0) (Now with VR Support)

Demo Project v4.15: [here](https://github.com/kwstasg/WAC/releases/download/WAC_Project_4.15/WAC_Project4.15.zip) 

Plugin v4.15: [here](https://github.com/kwstasg/WAC/releases/download/WAC_Plugin_Packaged_4.15/WAC_Plugin_Packaged_4.15.rar)

Video:
-------------
[![Video](https://img.youtube.com/vi/tyapMcqbpHk/0.jpg)](https://www.youtube.com/watch?v=tyapMcqbpHk)


Instructions:
-------------
1. Add WindowsAudioCapture inside Plugins folder in your project's folder ex. YOUR_PROJECT\Plugins\WindowsAudioCapture (if you dont have a Plugins folder feel free to crete one)
2. Create an Actor BP
3. Add a WindowsAudioCapture Component
4. on tick event add a Get Frequency Array (its better to use a delay because its not necessary to capture frequencies all the time)
5. Analyse Frequency Array as you preffer there are 4 functions so far to assist you Get Specific Freq Value, Get Average Freq Value in Range, Get Average Bass Value , Get Average Subbass Value
6. Use the output value to move/rescale other actors or adjust light brightnes or color...let your fantasy guide you


