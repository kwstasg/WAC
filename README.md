# WAC
UE4 Visualization Plugin - Windows Audio Capture (WAC) is an Unreal Engine 4 plugin that captures live audio from the windows default audio device and analyse it to frequency values. 

Practically you can create any audio visualisation through Unreal Engine's BP system by adding custom nodes that react live with your windows audio.

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

![screenshot](https://p5.zdusercontent.com/attachment/374006/6SWd1erlARSx3IeDCFgjZhLBZ?token=eyJhbGciOiJkaXIiLCJlbmMiOiJBMTI4Q0JDLUhTMjU2In0..S4SUMiqoz5mJOQw4AYBrDw.iLnxELpC8rxSyx4fWI41YVtuqVSqL9kp-1Gqp0aSoL8EX7mMEdmNWUkRWp39iZ-hfJLYDiIlMOCUAk-HwrVyr5hL4r57XSXDB0C5okelq8iIGnvOfXL585_-XAO19eThCISn6DTYKDBCNaJhanepGYIjp1JdRj5NPYdqboE_T684k43yR6ygqPcT8db35oDnB5auyS8-XxMl_dsP_6kULWGt_k569gMgHGA1kxOecOYGIybOlHcVExQihaM_s2_0DdxuAChjV6TGpsF8QOHD15U6MPI4-WUixlBF-zoMqs4.Oa9CaspSy9aRveiAyhsV9w)

Special Thanx:
-------------
To [eXifreXi](https://github.com/eXifreXi) for his awesome plugin eXiSoundVis was a learning treasure to me, helped me to understand the appliance of FFT Algorithm on Audio Frequencies visit his repository here https://github.com/eXifreXi/eXiSoundVis
